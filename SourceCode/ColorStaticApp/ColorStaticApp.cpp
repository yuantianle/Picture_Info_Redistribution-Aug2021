#include "ColorStaticApp.h"

ColorStaticApp::ColorStaticApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    menuBar()->setStyleSheet("background-color: lightblue; selection-background-color: #0067f7;");

    this->setStyleSheet("background-color: #b8c3d1;");

    connect(ui.widget, SIGNAL(ShowOrigImg(QImage)), this, SLOT(GetObjImg(QImage)));

}

void ColorStaticApp::GetObjImg(QImage I)
{

    QImage img = I;

    if (!img.isNull())
    {
        int height = 200;
        int width = 200;
        int Owidth = img.width(), Oheight = img.height();
        int Fwidth, Fheight;
        ui.label->setGeometry(0, 0, height, width);
        ui.label->setAlignment(Qt::AlignCenter);

        int Mul;
        if (Owidth / width >= Oheight / height)
            Mul = Owidth / width;
        else
            Mul = Oheight / height;
        Fwidth = Owidth / Mul;
        Fheight = Oheight / Mul;

        QImage scaledimg = img.scaled(Fwidth, Fheight, Qt::KeepAspectRatio);

        ui.label->setPixmap(QPixmap::fromImage(scaledimg));
    }
    else
    {
        ui.label->setText("    Need a selection..\n\n\n\n\n\n");
    }
}
