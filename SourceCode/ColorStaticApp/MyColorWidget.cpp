#include "MyColorWidget.h"


#define M_PI 3.1415926

MyColorWidget::MyColorWidget(QWidget* parent)
    : QWidget(parent)
{
    Reset();
}

MyColorWidget::~MyColorWidget()
{
}

void MyColorWidget::Reset()
{
    m_maxHue = 0;
    for (int i = 0; i < 360; i++)
        m_hueHistogram[i] = 0;
    m_TempVal.arc = 300;
    m_TempVal.distance = 0;
    m_TempVal.id = 3;
    //emit PutBarBack(0);
}

void MyColorWidget::InitCalculation()
{
    QString link = QFileDialog::getOpenFileName(this, tr("Open a picture for measurement"), "C:/Users/ytl_5/Box/Mural Art/Chemical Analysis/Color-statistical/ColorStaticApp/Image Data Base");
    QFileInfo fileInfo(link);
    QString filename = fileInfo.fileName();
    m_ImageName = filename.toStdString();
    QImage I = QImage(link);
    
    if (!I.isNull())
    {
        m_inImage = I;
        m_OutImage = I;
        ComputeHueHistogram();
        ComputeMostFitTemplate();
        //ShiftImage();
        //emit PutBarBack(0);
        emit ShowOrigImg(I);
    }
    else
    {
        Reset();
    }
}

void MyColorWidget::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); //Turn on anti-aliasing

    const int r = 200;
    QConicalGradient conicalGradient(0, 0, 0); //Create a gradient The first two parameters are the center point of the gradient and the third parameter is the angle of the gradient

    conicalGradient.setColorAt(0.0, Qt::red); //Set each interval of the angle gradient
    conicalGradient.setColorAt(60.0 / 360.0, Qt::yellow);
    conicalGradient.setColorAt(120.0 / 360.0, Qt::green);
    conicalGradient.setColorAt(180.0 / 360.0, Qt::cyan);
    conicalGradient.setColorAt(240.0 / 360.0, Qt::blue);
    conicalGradient.setColorAt(300.0 / 360.0, Qt::magenta);
    conicalGradient.setColorAt(1.0, Qt::red);

    //The outer part of the circle
    painter.translate(r/2, r/2); //Set the origin of the coordinate system to (r,r)
    QBrush background = QBrush(QColor("lightgray"));
    QBrush brush(conicalGradient);  //define the fill pattern's style
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    int m_margin = 10;
    int m_wheelWidth = 15;
    painter.drawEllipse(QPoint(0, 0), r/2 - m_margin, r/2 - m_margin);

    //The inner part of the circle
    painter.setBrush(background);
    painter.drawEllipse(QPoint(0, 0), r / 2 - m_margin - m_wheelWidth, r / 2 - m_margin - m_wheelWidth);

    ////Draw hueHistorgram
    painter.setPen(QPen(conicalGradient, 1.2, Qt::SolidLine, Qt::RoundCap));
    HueTemplate HT;
    for (int i = 0; i < 360; i++) {
        float rInner = r / 2 - m_margin - m_wheelWidth;
        float per;
        if (m_maxHue != 0) {
            per = rInner - ((float)m_hueHistogram[i] / (float)m_maxHue) * rInner;
            painter.drawLine(QPoint(rInner * cos((float)i / 180.0 * M_PI), -rInner * sin((float)i / 180.0 * M_PI)), QPoint(per * cos((float)i / 180.0 * M_PI), -per * sin((float)i / 180.0 * M_PI)));
        }
    }
    
    //The wheel's contours
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor("black")));
    painter.drawEllipse(QPoint(0, 0), 3, 3);
    painter.setPen(QPen(QBrush(QColor("black")), 2, Qt::SolidLine));
    m_rInner = r / 2 - m_margin - m_wheelWidth;
    painter.drawArc(-m_rInner, -m_rInner, m_rInner * 2, m_rInner * 2, 0, 16 * 360);
    float rOuter = r / 2 - m_margin;
    painter.drawArc(-rOuter, -rOuter, rOuter * 2, rOuter * 2, 0, 16 * 360);
    
    //The best suitable Template
    DrawTemplate(&painter);

}

void MyColorWidget::ComputeHueHistogram() {
    m_maxHue = 0;
    for (int i = 0; i < 360; i++)
        m_hueHistogram[i] = 0;
    qDebug() << "Image: width :" << m_OutImage.width() << "height :" << m_OutImage.height();
    for (int i = 0; i < m_OutImage.width(); i++) {
        for (int j = 0; j < m_OutImage.height(); j++) {
            QRgb pColor = m_OutImage.pixel(i, j);
            QColor qColor(pColor);
            int hue = qColor.hsvHue();
            if (hue >= 0) {
                m_hueHistogram[hue]++;
                if (m_hueHistogram[hue] > m_maxHue)
                    m_maxHue = m_hueHistogram[hue];
            }
        }
    }
}

void MyColorWidget::ComputeMostFitTemplate() {
    HueTemplate HT;
    HT.HTcompute();
    
    int S[360];
    for (int i = 0; i < 360; i++)
        S[i] = 0;
    for (int i = 0; i < m_inImage.width(); i++) {
        for (int j = 0; j < m_inImage.height(); j++) {
            QColor color = QColor(m_inImage.pixel(i, j));
            S[color.hsvHue()] += color.hsvSaturation();
        }
    }

    m_TempVal = HT.computeDistanceFast(m_inImage, 0, S);
    qDebug() << "Type = " << HT.names[0] << "Arc = " << m_TempVal.arc << "Distance" << m_TempVal.distance;
    for (int i = 1; i < 7; i++) {
        TemplateValue temp = HT.computeDistanceFast(m_inImage, i, S);
        if (temp.distance < m_TempVal.distance)
            m_TempVal = temp;
        qDebug() << "Type = " << HT.names[i] << "Arc = " << temp.arc << "Distance" << temp.distance;
    }
    emit ShowTheBestTemp(m_TempVal.id);
    update();
}

void MyColorWidget::DrawTemplate(QPainter * painter) {

    if (m_TempVal.id == -1)
        return;
    HueTemplate HT;
    int border1;
    painter->setPen(Qt::NoPen);
    if (HT.region1Arcs[m_TempVal.id] != 0) {
        border1 = (m_TempVal.arc - HT.region1Arcs[m_TempVal.id] / 2 + 360) % 360;
        //qDebug() << "b1 = " << border1;
        painter->setBrush(QBrush(QColor(0, 0, 0, 80)));
        painter->drawPie(-m_rInner, -m_rInner, m_rInner * 2, m_rInner * 2, border1 * 16, HT.region1Arcs[m_TempVal.id] * 16);
    }
    if (HT.region2Arcs[m_TempVal.id] != 0) {
        border1 = (m_TempVal.arc + HT.region2Shift[m_TempVal.id] - HT.region2Arcs[m_TempVal.id] / 2 + 360) % 360;
        painter->setBrush(QBrush(QColor(0, 0, 0, 80)));
        painter->drawPie(-m_rInner, -m_rInner, m_rInner * 2, m_rInner * 2, border1 * 16, HT.region2Arcs[m_TempVal.id] * 16);
    }
}

void MyColorWidget::ShiftImage() {
    HueTemplate HT;

    for (int i = 0; i < m_OutImage.width(); i++) {
        for (int j = 0; j < m_OutImage.height(); j++) {
            QColor qColor = QColor::fromRgb(m_OutImage.pixel(i, j));
            int hue = qColor.hsvHue();
            int targetHue = HT.targetHue(m_TempVal.arc, hue, m_TempVal.id);
            QColor targetColor = QColor::fromHsv(targetHue, qColor.hsvSaturation(), qColor.value(), qColor.alpha());
            m_OutImage.setPixel(i, j, qRgb(targetColor.redF() * 255.0, targetColor.greenF() * 255.0, targetColor.blueF() * 255.0));
        }
    }
    ComputeHueHistogram();
    emit OutPutImage(m_OutImage);
    update();
}

void MyColorWidget::ShiftImageWithTempX(int x) {
    if (x < 8 && x > -1)
    {
        HueTemplate HT;
        HT.HTcompute();

        int S[360];
        for (int i = 0; i < 360; i++)
            S[i] = 0;
        for (int i = 0; i < m_OutImage.width(); i++) {
            for (int j = 0; j < m_OutImage.height(); j++) {
                QColor color = QColor(m_OutImage.pixel(i, j));
                S[color.hsvHue()] += color.hsvSaturation();
            }
        }

        switch (x)
        {
            case 0: 
                m_TempVal = HT.computeDistanceFast(m_OutImage, x, S);
                break;
            case 1: 
                m_TempVal = HT.computeDistanceFast(m_OutImage, x, S);
                break;
            case 2: 
                m_TempVal = HT.computeDistanceFast(m_OutImage, x, S);
                break;
            case 3: 
                m_TempVal = HT.computeDistanceFast(m_OutImage, x, S);
                break;
            case 4: 
                m_TempVal = HT.computeDistanceFast(m_OutImage, x, S);
                break;
            case 5: 
                m_TempVal = HT.computeDistanceFast(m_OutImage, x, S);
                break;
            case 6: 
                m_TempVal = HT.computeDistanceFast(m_OutImage, x, S);
                break;
            case 7:
                m_TempVal = HT.computeDistanceFast(m_OutImage, x, S);
                break;
            default: 
                break;
        }
        
        for (int i = 0; i < m_OutImage.width(); i++) {
            for (int j = 0; j < m_OutImage.height(); j++) {
                QColor qColor = QColor::fromRgb(m_OutImage.pixel(i, j));
                int hue = qColor.hsvHue();
                int targetHue = HT.targetHue(m_TempVal.arc, hue, m_TempVal.id);
                QColor targetColor = QColor::fromHsv(targetHue, qColor.hsvSaturation(), qColor.value(), qColor.alpha());
                m_OutImage.setPixel(i, j, qRgb(targetColor.redF() * 255.0, targetColor.greenF() * 255.0, targetColor.blueF() * 255.0));
            }
        }
        ComputeHueHistogram();
        emit PutBarBack(0);
        emit OutPutImage(m_OutImage);
        update();
    }
}

void MyColorWidget::ShiftImageWithAngle(int a) {
    if (m_inImage.height() != 0)
    {
        HueTemplate HT;

        m_TempVal.arc = a;
        for (int i = 0; i < m_OutImage.width(); i++) {
            for (int j = 0; j < m_OutImage.height(); j++) {
                QColor qColor = QColor::fromRgb(m_OutImage.pixel(i, j));
                int hue = qColor.hsvHue();
                int targetHue = HT.targetHue(m_TempVal.arc, hue, m_TempVal.id);
                QColor targetColor = QColor::fromHsv(targetHue, qColor.hsvSaturation(), qColor.value(), qColor.alpha());
                m_OutImage.setPixel(i, j, qRgb(targetColor.redF() * 255.0, targetColor.greenF() * 255.0, targetColor.blueF() * 255.0));
            }
        }
        ComputeHueHistogram();
        emit OutPutImage(m_OutImage);
        update();
    }
}

void MyColorWidget::ShiftImageWithSpatialLocality() {
    HueTemplate HT;

    //QImage o_image = QImage(m_fileName);
    //o_image = fit500(&o_image);
    for (int i = 0; i < m_OutImage.width(); i++) {
        for (int j = 0; j < m_OutImage.height(); j++) {
            QColor qColor = QColor::fromRgb(m_OutImage.pixel(i, j));
            //int hue = qColor.hsvHue();
            int targetHue;
            //long long int * labels = HT.computeArcDistanceLabel(m_TV.arc, hue, m_TV.id);
            //if (abs(labels[2]) != abs(labels[3]))
            targetHue = HT.targetHueWithSpatialLocality(i, j, m_OutImage, m_TempVal);
            //else
                //targetHue =  HT.targetHue(m_TV.arc, hue, m_TV.id);
            //delete [] labels;
            QColor targetColor = QColor::fromHsv(targetHue, qColor.hsvSaturation(), qColor.value(), qColor.alpha());
            m_OutImage.setPixel(i, j, qRgb(targetColor.redF() * 255.0, targetColor.greenF() * 255.0, targetColor.blueF() * 255.0));
        }
    }
    ComputeHueHistogram();
    emit OutPutImage(m_OutImage);
    update();
}

void MyColorWidget::ImplementTmpScheme()
{
    QString link = QFileDialog::getOpenFileName(this, tr("Open a harmony scheme for the object"), "C:/Users/ytl_5/Box/Mural Art/2.5D System/Version7 (OpenCV CGAL)/Mark/Images");
    QImage I = QImage(link);
    m_inImage = I;
    ComputeMostFitTemplate();
    ShiftImage();
    emit ShowTempImg(I);
    update();
}

void MyColorWidget::OutPutExcel()
{
    std::ofstream outf;
    std::string s1 = m_ImageName.substr(0, m_ImageName.length() - 4);
    std::string s0("C:/Users/ytl_5/Box/Mural Art/Chemical Analysis/Color-statistical/ColorStaticApp/Output Excel/");
    std::string s2(".csv");
    s0.append(s1);
    s0.append(s2);
    outf.open(s0, std::ios::out | std::ios::trunc);
    if (!outf.is_open())
        qDebug() << "Error when do out put" ;

    outf << "Picture Name" << "," << "Hue Degree" << "," << "Value (Accumulated saturation for each degree of hue)" << "," << "TEMP1 range" << "," << "TEMP2 range" << "," << "TEMP name" << std::endl;
    
    HueTemplate HT;
    int border1;
    int border2;
    int border1l, border1r, border2l, border2r;
    if (HT.region1Arcs[m_TempVal.id] != 0)
    {
        border1 = (m_TempVal.arc - HT.region1Arcs[m_TempVal.id] / 2 + 360) % 360;
        border1l = border1;
        border1r = border1l + HT.region1Arcs[m_TempVal.id];
    }
    else
    {
        border1l = -1;
        border1r = -1;
    }
    if (HT.region2Arcs[m_TempVal.id] != 0) {
        border2 = (m_TempVal.arc + HT.region2Shift[m_TempVal.id] - HT.region2Arcs[m_TempVal.id] / 2 + 360) % 360;
        border2l = border2;
        border2r = border2l + HT.region2Arcs[m_TempVal.id];
    }
    else
    {
        border2l = -1;
        border2r = -1;
    }


    outf << m_ImageName << "," << "," << "," << border1l << " " << border1r << "," << border2l << " " << border2r << ","<< m_TempVal.id <<std::endl;
    for (int i = 0; i < 360; i++)
    {
        outf  << "," << i << "," << (float)m_hueHistogram[i] / (float)m_maxHue << std::endl;
    }
    

    outf.close();

    //std::ifstream iFile("result.csv");
    //std::string readStr((std::istreambuf_iterator<char>(iFile)), std::istreambuf_iterator<char>());
    //std::cout << readStr.c_str();


}