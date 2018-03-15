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
#include <QtWidgets/QGroupBox>
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
    QAction *actionPointLight;
    QAction *actionRendering;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *objectGroupBox;
    QVBoxLayout *verticalLayout_3;
    QListWidget *object_list_view;
    QGroupBox *lightGroupBox;
    QVBoxLayout *verticalLayout_4;
    QListWidget *light_list_view;
    QOpenGLWidget *openGlPreview;
    QWidget *attributes;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menuObjects;
    QMenu *menuFichier;
    QMenu *menuScene;
    QMenu *menuLights;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1134, 659);
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
        actionPointLight = new QAction(MainWindow);
        actionPointLight->setObjectName(QStringLiteral("actionPointLight"));
        actionRendering = new QAction(MainWindow);
        actionRendering->setObjectName(QStringLiteral("actionRendering"));
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
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        objectGroupBox = new QGroupBox(centralWidget);
        objectGroupBox->setObjectName(QStringLiteral("objectGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(objectGroupBox->sizePolicy().hasHeightForWidth());
        objectGroupBox->setSizePolicy(sizePolicy);
        objectGroupBox->setMinimumSize(QSize(300, 0));
        objectGroupBox->setMaximumSize(QSize(300, 16777215));
        verticalLayout_3 = new QVBoxLayout(objectGroupBox);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        object_list_view = new QListWidget(objectGroupBox);
        object_list_view->setObjectName(QStringLiteral("object_list_view"));
        object_list_view->setMinimumSize(QSize(300, 0));
        object_list_view->setMaximumSize(QSize(300, 16777215));

        verticalLayout_3->addWidget(object_list_view);


        verticalLayout_2->addWidget(objectGroupBox);

        lightGroupBox = new QGroupBox(centralWidget);
        lightGroupBox->setObjectName(QStringLiteral("lightGroupBox"));
        sizePolicy.setHeightForWidth(lightGroupBox->sizePolicy().hasHeightForWidth());
        lightGroupBox->setSizePolicy(sizePolicy);
        lightGroupBox->setMinimumSize(QSize(300, 0));
        lightGroupBox->setMaximumSize(QSize(300, 16777215));
        verticalLayout_4 = new QVBoxLayout(lightGroupBox);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        light_list_view = new QListWidget(lightGroupBox);
        light_list_view->setObjectName(QStringLiteral("light_list_view"));
        light_list_view->setMinimumSize(QSize(300, 0));
        light_list_view->setMaximumSize(QSize(300, 16777215));

        verticalLayout_4->addWidget(light_list_view);


        verticalLayout_2->addWidget(lightGroupBox);


        horizontalLayout->addLayout(verticalLayout_2);

        openGlPreview = new QOpenGLWidget(centralWidget);
        openGlPreview->setObjectName(QStringLiteral("openGlPreview"));
        openGlPreview->setMinimumSize(QSize(400, 0));

        horizontalLayout->addWidget(openGlPreview);

        attributes = new QWidget(centralWidget);
        attributes->setObjectName(QStringLiteral("attributes"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(attributes->sizePolicy().hasHeightForWidth());
        attributes->setSizePolicy(sizePolicy1);
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
        menuBar->setGeometry(QRect(0, 0, 1134, 22));
        menuObjects = new QMenu(menuBar);
        menuObjects->setObjectName(QStringLiteral("menuObjects"));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuScene = new QMenu(menuBar);
        menuScene->setObjectName(QStringLiteral("menuScene"));
        menuLights = new QMenu(menuBar);
        menuLights->setObjectName(QStringLiteral("menuLights"));
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
        menuBar->addAction(menuLights->menuAction());
        menuObjects->addAction(actionSphere);
        menuObjects->addAction(actionCylinder);
        menuFichier->addAction(actionNouveau);
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addAction(actionOptions);
        menuScene->addAction(actionOptions_Scene);
        menuScene->addAction(actionRendering);
        menuLights->addAction(actionPointLight);

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
        actionPointLight->setText(QApplication::translate("MainWindow", "Point Light", Q_NULLPTR));
        actionRendering->setText(QApplication::translate("MainWindow", "Start Rendering", Q_NULLPTR));
        objectGroupBox->setTitle(QApplication::translate("MainWindow", "Objects :", Q_NULLPTR));
        lightGroupBox->setTitle(QApplication::translate("MainWindow", "Lights :", Q_NULLPTR));
        menuObjects->setTitle(QApplication::translate("MainWindow", "Objects", Q_NULLPTR));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", Q_NULLPTR));
        menuScene->setTitle(QApplication::translate("MainWindow", "Scene", Q_NULLPTR));
        menuLights->setTitle(QApplication::translate("MainWindow", "Lights", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
