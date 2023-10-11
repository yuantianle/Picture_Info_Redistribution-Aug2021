#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ColorStaticApp.h"

class ColorStaticApp : public QMainWindow
{
    Q_OBJECT

public:
    ColorStaticApp(QWidget *parent = Q_NULLPTR);

private:
    Ui::ColorStaticAppClass ui;

public slots:
    void GetObjImg(QImage);
};
