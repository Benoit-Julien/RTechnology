/********************************************************************************
** Form generated from reading UI file 'scenesettings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENESETTINGS_H
#define UI_SCENESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SceneSettings
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxCamera;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *Rotation;
    QLabel *rotation_label;
    QHBoxLayout *Rotation_X;
    QLabel *rotation_x_label;
    QDoubleSpinBox *rotation_x_value;
    QHBoxLayout *Rotation_Y;
    QLabel *rotation_y_label;
    QDoubleSpinBox *rotation_y_value;
    QHBoxLayout *Rotation_Z;
    QLabel *rotation_z_label;
    QDoubleSpinBox *rotation_z_value;
    QHBoxLayout *Position;
    QLabel *position_label;
    QHBoxLayout *Position_X;
    QLabel *position_x_label;
    QDoubleSpinBox *position_x_value;
    QHBoxLayout *Position_Y;
    QLabel *position_y_label;
    QDoubleSpinBox *position_y_value;
    QHBoxLayout *Position_Z;
    QLabel *position_z_label;
    QDoubleSpinBox *position_z_value;
    QHBoxLayout *viewPlaneDistance;
    QLabel *viewPlaneDistance_label;
    QDoubleSpinBox *viewPlaneDistance_value;
    QHBoxLayout *viewPlaneWidth;
    QLabel *viewPlaneWidth_label;
    QDoubleSpinBox *viewPlaneWidth_value;
    QHBoxLayout *viewPlaneHeight;
    QLabel *viewPlaneHeight_label;
    QDoubleSpinBox *viewPlaneHeight_value;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SceneSettings)
    {
        if (SceneSettings->objectName().isEmpty())
            SceneSettings->setObjectName(QStringLiteral("SceneSettings"));
        SceneSettings->resize(496, 261);
        verticalLayout = new QVBoxLayout(SceneSettings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBoxCamera = new QGroupBox(SceneSettings);
        groupBoxCamera->setObjectName(QStringLiteral("groupBoxCamera"));
        verticalLayout_2 = new QVBoxLayout(groupBoxCamera);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Rotation = new QHBoxLayout();
        Rotation->setObjectName(QStringLiteral("Rotation"));
        rotation_label = new QLabel(groupBoxCamera);
        rotation_label->setObjectName(QStringLiteral("rotation_label"));
        rotation_label->setMinimumSize(QSize(60, 0));
        rotation_label->setMaximumSize(QSize(60, 16777215));

        Rotation->addWidget(rotation_label);

        Rotation_X = new QHBoxLayout();
        Rotation_X->setObjectName(QStringLiteral("Rotation_X"));
        rotation_x_label = new QLabel(groupBoxCamera);
        rotation_x_label->setObjectName(QStringLiteral("rotation_x_label"));

        Rotation_X->addWidget(rotation_x_label);

        rotation_x_value = new QDoubleSpinBox(groupBoxCamera);
        rotation_x_value->setObjectName(QStringLiteral("rotation_x_value"));
        rotation_x_value->setWrapping(false);
        rotation_x_value->setMinimum(-100000);
        rotation_x_value->setMaximum(100000);

        Rotation_X->addWidget(rotation_x_value);


        Rotation->addLayout(Rotation_X);

        Rotation_Y = new QHBoxLayout();
        Rotation_Y->setObjectName(QStringLiteral("Rotation_Y"));
        rotation_y_label = new QLabel(groupBoxCamera);
        rotation_y_label->setObjectName(QStringLiteral("rotation_y_label"));

        Rotation_Y->addWidget(rotation_y_label);

        rotation_y_value = new QDoubleSpinBox(groupBoxCamera);
        rotation_y_value->setObjectName(QStringLiteral("rotation_y_value"));
        rotation_y_value->setMinimum(-100000);
        rotation_y_value->setMaximum(100000);

        Rotation_Y->addWidget(rotation_y_value);


        Rotation->addLayout(Rotation_Y);

        Rotation_Z = new QHBoxLayout();
        Rotation_Z->setObjectName(QStringLiteral("Rotation_Z"));
        rotation_z_label = new QLabel(groupBoxCamera);
        rotation_z_label->setObjectName(QStringLiteral("rotation_z_label"));

        Rotation_Z->addWidget(rotation_z_label);

        rotation_z_value = new QDoubleSpinBox(groupBoxCamera);
        rotation_z_value->setObjectName(QStringLiteral("rotation_z_value"));
        rotation_z_value->setMinimum(-100000);
        rotation_z_value->setMaximum(100000);

        Rotation_Z->addWidget(rotation_z_value);


        Rotation->addLayout(Rotation_Z);


        verticalLayout_2->addLayout(Rotation);

        Position = new QHBoxLayout();
        Position->setObjectName(QStringLiteral("Position"));
        position_label = new QLabel(groupBoxCamera);
        position_label->setObjectName(QStringLiteral("position_label"));
        position_label->setMinimumSize(QSize(60, 0));
        position_label->setMaximumSize(QSize(60, 16777215));

        Position->addWidget(position_label);

        Position_X = new QHBoxLayout();
        Position_X->setObjectName(QStringLiteral("Position_X"));
        position_x_label = new QLabel(groupBoxCamera);
        position_x_label->setObjectName(QStringLiteral("position_x_label"));

        Position_X->addWidget(position_x_label);

        position_x_value = new QDoubleSpinBox(groupBoxCamera);
        position_x_value->setObjectName(QStringLiteral("position_x_value"));
        position_x_value->setMinimum(-100000);
        position_x_value->setMaximum(100000);

        Position_X->addWidget(position_x_value);


        Position->addLayout(Position_X);

        Position_Y = new QHBoxLayout();
        Position_Y->setObjectName(QStringLiteral("Position_Y"));
        position_y_label = new QLabel(groupBoxCamera);
        position_y_label->setObjectName(QStringLiteral("position_y_label"));

        Position_Y->addWidget(position_y_label);

        position_y_value = new QDoubleSpinBox(groupBoxCamera);
        position_y_value->setObjectName(QStringLiteral("position_y_value"));
        position_y_value->setMinimum(-100000);
        position_y_value->setMaximum(100000);

        Position_Y->addWidget(position_y_value);


        Position->addLayout(Position_Y);

        Position_Z = new QHBoxLayout();
        Position_Z->setObjectName(QStringLiteral("Position_Z"));
        position_z_label = new QLabel(groupBoxCamera);
        position_z_label->setObjectName(QStringLiteral("position_z_label"));

        Position_Z->addWidget(position_z_label);

        position_z_value = new QDoubleSpinBox(groupBoxCamera);
        position_z_value->setObjectName(QStringLiteral("position_z_value"));
        position_z_value->setMinimum(-100000);
        position_z_value->setMaximum(100000);

        Position_Z->addWidget(position_z_value);


        Position->addLayout(Position_Z);


        verticalLayout_2->addLayout(Position);

        viewPlaneDistance = new QHBoxLayout();
        viewPlaneDistance->setObjectName(QStringLiteral("viewPlaneDistance"));
        viewPlaneDistance_label = new QLabel(groupBoxCamera);
        viewPlaneDistance_label->setObjectName(QStringLiteral("viewPlaneDistance_label"));

        viewPlaneDistance->addWidget(viewPlaneDistance_label);

        viewPlaneDistance_value = new QDoubleSpinBox(groupBoxCamera);
        viewPlaneDistance_value->setObjectName(QStringLiteral("viewPlaneDistance_value"));
        viewPlaneDistance_value->setValue(1);

        viewPlaneDistance->addWidget(viewPlaneDistance_value);


        verticalLayout_2->addLayout(viewPlaneDistance);

        viewPlaneWidth = new QHBoxLayout();
        viewPlaneWidth->setObjectName(QStringLiteral("viewPlaneWidth"));
        viewPlaneWidth_label = new QLabel(groupBoxCamera);
        viewPlaneWidth_label->setObjectName(QStringLiteral("viewPlaneWidth_label"));

        viewPlaneWidth->addWidget(viewPlaneWidth_label);

        viewPlaneWidth_value = new QDoubleSpinBox(groupBoxCamera);
        viewPlaneWidth_value->setObjectName(QStringLiteral("viewPlaneWidth_value"));
        viewPlaneWidth_value->setValue(0.5);

        viewPlaneWidth->addWidget(viewPlaneWidth_value);


        verticalLayout_2->addLayout(viewPlaneWidth);

        viewPlaneHeight = new QHBoxLayout();
        viewPlaneHeight->setObjectName(QStringLiteral("viewPlaneHeight"));
        viewPlaneHeight_label = new QLabel(groupBoxCamera);
        viewPlaneHeight_label->setObjectName(QStringLiteral("viewPlaneHeight_label"));

        viewPlaneHeight->addWidget(viewPlaneHeight_label);

        viewPlaneHeight_value = new QDoubleSpinBox(groupBoxCamera);
        viewPlaneHeight_value->setObjectName(QStringLiteral("viewPlaneHeight_value"));
        viewPlaneHeight_value->setValue(0.35);

        viewPlaneHeight->addWidget(viewPlaneHeight_value);


        verticalLayout_2->addLayout(viewPlaneHeight);


        verticalLayout->addWidget(groupBoxCamera);

        buttonBox = new QDialogButtonBox(SceneSettings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SceneSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), SceneSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SceneSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(SceneSettings);
    } // setupUi

    void retranslateUi(QDialog *SceneSettings)
    {
        SceneSettings->setWindowTitle(QApplication::translate("SceneSettings", "Dialog", Q_NULLPTR));
        groupBoxCamera->setTitle(QApplication::translate("SceneSettings", "Camera :", Q_NULLPTR));
        rotation_label->setText(QApplication::translate("SceneSettings", "Rotation", Q_NULLPTR));
        rotation_x_label->setText(QApplication::translate("SceneSettings", "X", Q_NULLPTR));
        rotation_y_label->setText(QApplication::translate("SceneSettings", "Y", Q_NULLPTR));
        rotation_z_label->setText(QApplication::translate("SceneSettings", "Z", Q_NULLPTR));
        position_label->setText(QApplication::translate("SceneSettings", "Position", Q_NULLPTR));
        position_x_label->setText(QApplication::translate("SceneSettings", "X", Q_NULLPTR));
        position_y_label->setText(QApplication::translate("SceneSettings", "Y", Q_NULLPTR));
        position_z_label->setText(QApplication::translate("SceneSettings", "Z", Q_NULLPTR));
        viewPlaneDistance_label->setText(QApplication::translate("SceneSettings", "viewPlaneDistance", Q_NULLPTR));
        viewPlaneWidth_label->setText(QApplication::translate("SceneSettings", "viewPlaneWidth", Q_NULLPTR));
        viewPlaneHeight_label->setText(QApplication::translate("SceneSettings", "viewPlaneHeight", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SceneSettings: public Ui_SceneSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENESETTINGS_H
