/********************************************************************************
** Form generated from reading UI file 'defaultattribute.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULTATTRIBUTE_H
#define UI_DEFAULTATTRIBUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DefaultAttribute
{
public:
    QVBoxLayout *verticalLayout_2;
    QLineEdit *name_lineEdit;
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
    QHBoxLayout *Scale;
    QLabel *scale_label;
    QHBoxLayout *Scale_X;
    QLabel *scale_x_label;
    QDoubleSpinBox *scale_x_value;
    QHBoxLayout *Scale_Y;
    QLabel *scale_y_label;
    QDoubleSpinBox *scale_y_value;
    QHBoxLayout *Scale_Z;
    QLabel *scale_z_label;
    QDoubleSpinBox *scale_z_value;

    void setupUi(QWidget *DefaultAttribute)
    {
        if (DefaultAttribute->objectName().isEmpty())
            DefaultAttribute->setObjectName(QStringLiteral("DefaultAttribute"));
        DefaultAttribute->resize(454, 151);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DefaultAttribute->sizePolicy().hasHeightForWidth());
        DefaultAttribute->setSizePolicy(sizePolicy);
        DefaultAttribute->setMinimumSize(QSize(0, 151));
        DefaultAttribute->setMaximumSize(QSize(16777215, 151));
        verticalLayout_2 = new QVBoxLayout(DefaultAttribute);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        name_lineEdit = new QLineEdit(DefaultAttribute);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));
        name_lineEdit->setMaxLength(255);

        verticalLayout_2->addWidget(name_lineEdit);

        Position = new QHBoxLayout();
        Position->setObjectName(QStringLiteral("Position"));
        position_label = new QLabel(DefaultAttribute);
        position_label->setObjectName(QStringLiteral("position_label"));
        position_label->setMinimumSize(QSize(60, 0));
        position_label->setMaximumSize(QSize(60, 16777215));

        Position->addWidget(position_label);

        Position_X = new QHBoxLayout();
        Position_X->setObjectName(QStringLiteral("Position_X"));
        position_x_label = new QLabel(DefaultAttribute);
        position_x_label->setObjectName(QStringLiteral("position_x_label"));

        Position_X->addWidget(position_x_label);

        position_x_value = new QDoubleSpinBox(DefaultAttribute);
        position_x_value->setObjectName(QStringLiteral("position_x_value"));
        position_x_value->setMinimum(-100000);
        position_x_value->setMaximum(100000);

        Position_X->addWidget(position_x_value);


        Position->addLayout(Position_X);

        Position_Y = new QHBoxLayout();
        Position_Y->setObjectName(QStringLiteral("Position_Y"));
        position_y_label = new QLabel(DefaultAttribute);
        position_y_label->setObjectName(QStringLiteral("position_y_label"));

        Position_Y->addWidget(position_y_label);

        position_y_value = new QDoubleSpinBox(DefaultAttribute);
        position_y_value->setObjectName(QStringLiteral("position_y_value"));
        position_y_value->setMinimum(-100000);
        position_y_value->setMaximum(100000);

        Position_Y->addWidget(position_y_value);


        Position->addLayout(Position_Y);

        Position_Z = new QHBoxLayout();
        Position_Z->setObjectName(QStringLiteral("Position_Z"));
        position_z_label = new QLabel(DefaultAttribute);
        position_z_label->setObjectName(QStringLiteral("position_z_label"));

        Position_Z->addWidget(position_z_label);

        position_z_value = new QDoubleSpinBox(DefaultAttribute);
        position_z_value->setObjectName(QStringLiteral("position_z_value"));
        position_z_value->setMinimum(-100000);
        position_z_value->setMaximum(100000);

        Position_Z->addWidget(position_z_value);


        Position->addLayout(Position_Z);


        verticalLayout_2->addLayout(Position);

        Rotation = new QHBoxLayout();
        Rotation->setObjectName(QStringLiteral("Rotation"));
        rotation_label = new QLabel(DefaultAttribute);
        rotation_label->setObjectName(QStringLiteral("rotation_label"));
        rotation_label->setMinimumSize(QSize(60, 0));
        rotation_label->setMaximumSize(QSize(60, 16777215));

        Rotation->addWidget(rotation_label);

        Rotation_X = new QHBoxLayout();
        Rotation_X->setObjectName(QStringLiteral("Rotation_X"));
        rotation_x_label = new QLabel(DefaultAttribute);
        rotation_x_label->setObjectName(QStringLiteral("rotation_x_label"));

        Rotation_X->addWidget(rotation_x_label);

        rotation_x_value = new QDoubleSpinBox(DefaultAttribute);
        rotation_x_value->setObjectName(QStringLiteral("rotation_x_value"));
        rotation_x_value->setWrapping(false);
        rotation_x_value->setMinimum(-100000);
        rotation_x_value->setMaximum(100000);

        Rotation_X->addWidget(rotation_x_value);


        Rotation->addLayout(Rotation_X);

        Rotation_Y = new QHBoxLayout();
        Rotation_Y->setObjectName(QStringLiteral("Rotation_Y"));
        rotation_y_label = new QLabel(DefaultAttribute);
        rotation_y_label->setObjectName(QStringLiteral("rotation_y_label"));

        Rotation_Y->addWidget(rotation_y_label);

        rotation_y_value = new QDoubleSpinBox(DefaultAttribute);
        rotation_y_value->setObjectName(QStringLiteral("rotation_y_value"));
        rotation_y_value->setMinimum(-100000);
        rotation_y_value->setMaximum(100000);

        Rotation_Y->addWidget(rotation_y_value);


        Rotation->addLayout(Rotation_Y);

        Rotation_Z = new QHBoxLayout();
        Rotation_Z->setObjectName(QStringLiteral("Rotation_Z"));
        rotation_z_label = new QLabel(DefaultAttribute);
        rotation_z_label->setObjectName(QStringLiteral("rotation_z_label"));

        Rotation_Z->addWidget(rotation_z_label);

        rotation_z_value = new QDoubleSpinBox(DefaultAttribute);
        rotation_z_value->setObjectName(QStringLiteral("rotation_z_value"));
        rotation_z_value->setMinimum(-100000);
        rotation_z_value->setMaximum(100000);

        Rotation_Z->addWidget(rotation_z_value);


        Rotation->addLayout(Rotation_Z);


        verticalLayout_2->addLayout(Rotation);

        Scale = new QHBoxLayout();
        Scale->setObjectName(QStringLiteral("Scale"));
        scale_label = new QLabel(DefaultAttribute);
        scale_label->setObjectName(QStringLiteral("scale_label"));
        scale_label->setMinimumSize(QSize(60, 0));
        scale_label->setMaximumSize(QSize(60, 16777215));

        Scale->addWidget(scale_label);

        Scale_X = new QHBoxLayout();
        Scale_X->setObjectName(QStringLiteral("Scale_X"));
        scale_x_label = new QLabel(DefaultAttribute);
        scale_x_label->setObjectName(QStringLiteral("scale_x_label"));

        Scale_X->addWidget(scale_x_label);

        scale_x_value = new QDoubleSpinBox(DefaultAttribute);
        scale_x_value->setObjectName(QStringLiteral("scale_x_value"));
        scale_x_value->setMinimum(-100000);
        scale_x_value->setMaximum(100000);

        Scale_X->addWidget(scale_x_value);


        Scale->addLayout(Scale_X);

        Scale_Y = new QHBoxLayout();
        Scale_Y->setObjectName(QStringLiteral("Scale_Y"));
        scale_y_label = new QLabel(DefaultAttribute);
        scale_y_label->setObjectName(QStringLiteral("scale_y_label"));

        Scale_Y->addWidget(scale_y_label);

        scale_y_value = new QDoubleSpinBox(DefaultAttribute);
        scale_y_value->setObjectName(QStringLiteral("scale_y_value"));
        scale_y_value->setMinimum(-100000);
        scale_y_value->setMaximum(100000);

        Scale_Y->addWidget(scale_y_value);


        Scale->addLayout(Scale_Y);

        Scale_Z = new QHBoxLayout();
        Scale_Z->setObjectName(QStringLiteral("Scale_Z"));
        scale_z_label = new QLabel(DefaultAttribute);
        scale_z_label->setObjectName(QStringLiteral("scale_z_label"));

        Scale_Z->addWidget(scale_z_label);

        scale_z_value = new QDoubleSpinBox(DefaultAttribute);
        scale_z_value->setObjectName(QStringLiteral("scale_z_value"));
        scale_z_value->setMinimum(-100000);
        scale_z_value->setMaximum(100000);

        Scale_Z->addWidget(scale_z_value);


        Scale->addLayout(Scale_Z);


        verticalLayout_2->addLayout(Scale);


        retranslateUi(DefaultAttribute);

        QMetaObject::connectSlotsByName(DefaultAttribute);
    } // setupUi

    void retranslateUi(QWidget *DefaultAttribute)
    {
        DefaultAttribute->setWindowTitle(QApplication::translate("DefaultAttribute", "Form", Q_NULLPTR));
        position_label->setText(QApplication::translate("DefaultAttribute", "Position", Q_NULLPTR));
        position_x_label->setText(QApplication::translate("DefaultAttribute", "X", Q_NULLPTR));
        position_y_label->setText(QApplication::translate("DefaultAttribute", "Y", Q_NULLPTR));
        position_z_label->setText(QApplication::translate("DefaultAttribute", "Z", Q_NULLPTR));
        rotation_label->setText(QApplication::translate("DefaultAttribute", "Rotation", Q_NULLPTR));
        rotation_x_label->setText(QApplication::translate("DefaultAttribute", "X", Q_NULLPTR));
        rotation_y_label->setText(QApplication::translate("DefaultAttribute", "Y", Q_NULLPTR));
        rotation_z_label->setText(QApplication::translate("DefaultAttribute", "Z", Q_NULLPTR));
        scale_label->setText(QApplication::translate("DefaultAttribute", "Scale", Q_NULLPTR));
        scale_x_label->setText(QApplication::translate("DefaultAttribute", "X", Q_NULLPTR));
        scale_y_label->setText(QApplication::translate("DefaultAttribute", "Y", Q_NULLPTR));
        scale_z_label->setText(QApplication::translate("DefaultAttribute", "Z", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DefaultAttribute: public Ui_DefaultAttribute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULTATTRIBUTE_H
