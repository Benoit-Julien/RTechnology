/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSphere;
    QAction *actionCylinder;
    QAction *actionOuvrir;
    QAction *actionEnregistrer;
    QAction *actionEnregistrer_sous;
    QAction *actionOptions;
    QAction *actionNouveau;
    QAction *actionOptions_Scene;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *object_list_view;
    QOpenGLWidget *openGLPreview;
    QWidget *attributes;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menuObjects;
    QMenu *menuFichier;
    QMenu *menuScene;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1132, 659);
        actionSphere = new QAction(MainWindow);
        actionSphere->setObjectName(QStringLiteral("actionSphere"));
        actionCylinder = new QAction(MainWindow);
        actionCylinder->setObjectName(QStringLiteral("actionCylinder"));
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QStringLiteral("actionEnregistrer"));
        actionEnregistrer_sous = new QAction(MainWindow);
        actionEnregistrer_sous->setObjectName(QStringLiteral("actionEnregistrer_sous"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName(QStringLiteral("actionNouveau"));
        actionOptions_Scene = new QAction(MainWindow);
        actionOptions_Scene->setObjectName(QStringLiteral("actionOptions_Scene"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        object_list_view = new QListWidget(centralWidget);
        object_list_view->setObjectName(QStringLiteral("object_list_view"));
        object_list_view->setMinimumSize(QSize(300, 0));
        object_list_view->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(object_list_view);

        openGLPreview = new QOpenGLWidget(centralWidget);
        openGLPreview->setObjectName(QStringLiteral("openGLPreview"));
        openGLPreview->setMinimumSize(QSize(400, 0));

        horizontalLayout->addWidget(openGLPreview);

        attributes = new QWidget(centralWidget);
        attributes->setObjectName(QStringLiteral("attributes"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(attributes->sizePolicy().hasHeightForWidth());
        attributes->setSizePolicy(sizePolicy);
        attributes->setMinimumSize(QSize(400, 0));
        attributes->setMaximumSize(QSize(400, 16777215));
        attributes->setLayoutDirection(Qt::LeftToRight);
        attributes->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(attributes);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout->addWidget(attributes);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1132, 22));
        menuObjects = new QMenu(menuBar);
        menuObjects->setObjectName(QStringLiteral("menuObjects"));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuScene = new QMenu(menuBar);
        menuScene->setObjectName(QStringLiteral("menuScene"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuScene->menuAction());
        menuBar->addAction(menuObjects->menuAction());
        menuObjects->addAction(actionSphere);
        menuObjects->addAction(actionCylinder);
        menuFichier->addAction(actionNouveau);
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addAction(actionOptions);
        menuScene->addAction(actionOptions_Scene);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSphere->setText(QApplication::translate("MainWindow", "Sphere", Q_NULLPTR));
        actionCylinder->setText(QApplication::translate("MainWindow", "Cylinder", Q_NULLPTR));
        actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir", Q_NULLPTR));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", Q_NULLPTR));
        actionEnregistrer_sous->setText(QApplication::translate("MainWindow", "Enregistrer sous", Q_NULLPTR));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        actionNouveau->setText(QApplication::translate("MainWindow", "Nouveau", Q_NULLPTR));
        actionOptions_Scene->setText(QApplication::translate("MainWindow", "Scene Options", Q_NULLPTR));
        menuObjects->setTitle(QApplication::translate("MainWindow", "Objects", Q_NULLPTR));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", Q_NULLPTR));
        menuScene->setTitle(QApplication::translate("MainWindow", "Scene", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
