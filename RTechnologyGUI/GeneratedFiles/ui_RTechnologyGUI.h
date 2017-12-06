/********************************************************************************
** Form generated from reading UI file 'RTechnologyGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTECHNOLOGYGUI_H
#define UI_RTECHNOLOGYGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RTechnologyGUIClass
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RTechnologyGUIClass)
    {
        if (RTechnologyGUIClass->objectName().isEmpty())
            RTechnologyGUIClass->setObjectName(QStringLiteral("RTechnologyGUIClass"));
        RTechnologyGUIClass->resize(600, 400);
        centralWidget = new QWidget(RTechnologyGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(15, 11, 571, 321));
        RTechnologyGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RTechnologyGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        RTechnologyGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RTechnologyGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RTechnologyGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RTechnologyGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RTechnologyGUIClass->setStatusBar(statusBar);

        retranslateUi(RTechnologyGUIClass);

        QMetaObject::connectSlotsByName(RTechnologyGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *RTechnologyGUIClass)
    {
        RTechnologyGUIClass->setWindowTitle(QApplication::translate("RTechnologyGUIClass", "RTechnologyGUI", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("RTechnologyGUIClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RTechnologyGUIClass: public Ui_RTechnologyGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTECHNOLOGYGUI_H
