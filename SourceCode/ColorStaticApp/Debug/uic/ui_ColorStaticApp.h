/********************************************************************************
** Form generated from reading UI file 'ColorStaticApp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORSTATICAPP_H
#define UI_COLORSTATICAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyColorWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ColorStaticAppClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    MyColorWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ColorStaticAppClass)
    {
        if (ColorStaticAppClass->objectName().isEmpty())
            ColorStaticAppClass->setObjectName(QString::fromUtf8("ColorStaticAppClass"));
        ColorStaticAppClass->resize(1084, 735);
        centralWidget = new QWidget(ColorStaticAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new MyColorWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(widget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        ColorStaticAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ColorStaticAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1084, 22));
        ColorStaticAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ColorStaticAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ColorStaticAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ColorStaticAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ColorStaticAppClass->setStatusBar(statusBar);

        retranslateUi(ColorStaticAppClass);
        QObject::connect(pushButton, SIGNAL(pressed()), widget, SLOT(InitCalculation()));
        QObject::connect(pushButton_2, SIGNAL(pressed()), widget, SLOT(OutPutExcel()));

        QMetaObject::connectSlotsByName(ColorStaticAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *ColorStaticAppClass)
    {
        ColorStaticAppClass->setWindowTitle(QCoreApplication::translate("ColorStaticAppClass", "ColorStaticApp", nullptr));
        label->setText(QCoreApplication::translate("ColorStaticAppClass", "Need to Choose a Picture...", nullptr));
        pushButton->setText(QCoreApplication::translate("ColorStaticAppClass", "Input Picture", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ColorStaticAppClass", "Previous", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ColorStaticAppClass", "Next", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ColorStaticAppClass", "OutPut Information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorStaticAppClass: public Ui_ColorStaticAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORSTATICAPP_H
