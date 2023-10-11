#pragma once

#include <QOpenGLWidget>
#include <QPainter>
#include <QImage>
#include <QDebug>
#include <QString>
#include <QFileDialog>

#include "template.h"

#include <fstream>
#include <iostream>
#include <string>
#include <streambuf>

class MyColorWidget: public QWidget
{
    Q_OBJECT

public:
    MyColorWidget(QWidget* parent = Q_NULLPTR);
    ~MyColorWidget();
    

public slots:
    void Reset();
    void InitCalculation();
    void ShiftImageWithTempX(int x);
    void ShiftImageWithAngle(int a);
    void ImplementTmpScheme();
    void OutPutExcel();

public :
    void paintEvent(QPaintEvent* e);
    void ComputeHueHistogram();
    void ComputeMostFitTemplate();
    void DrawTemplate(QPainter* painter);
    void ShiftImage();
    void ShiftImageWithSpatialLocality();
    
private:
    QImage m_inImage;
    QImage m_OutImage;
    float m_rInner;

    int m_hueHistogram[360];
    int m_maxHue;
    TemplateValue m_TempVal;
    std::string m_ImageName;

signals:
    void ShowTheBestTemp(int i);
    void OutPutImage(QImage I);
    void PutBarBack(int);
    void ShowTempImg(QImage I);
    void ShowOrigImg(QImage I);
};