/********************************************************************************
** Form generated from reading UI file 'colorattribute.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORATTRIBUTE_H
#define UI_COLORATTRIBUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorAttribute
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *Color;
    QLabel *color_label;
    QHBoxLayout *Color_R;
    QLabel *color_r_label;
    QSpinBox *color_r_value;
    QHBoxLayout *Color_G;
    QLabel *color_g_label;
    QSpinBox *color_g_value;
    QHBoxLayout *Color_B;
    QLabel *color_b_label;
    QSpinBox *color_b_value;

    void setupUi(QWidget *ColorAttribute)
    {
        if (ColorAttribute->objectName().isEmpty())
            ColorAttribute->setObjectName(QStringLiteral("ColorAttribute"));
        ColorAttribute->resize(281, 48);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorAttribute->sizePolicy().hasHeightForWidth());
        ColorAttribute->setSizePolicy(sizePolicy);
        ColorAttribute->setMinimumSize(QSize(0, 48));
        ColorAttribute->setMaximumSize(QSize(16777215, 48));
        verticalLayout = new QVBoxLayout(ColorAttribute);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Color = new QHBoxLayout();
        Color->setObjectName(QStringLiteral("Color"));
        color_label = new QLabel(ColorAttribute);
        color_label->setObjectName(QStringLiteral("color_label"));
        color_label->setMinimumSize(QSize(60, 0));
        color_label->setMaximumSize(QSize(60, 16777215));

        Color->addWidget(color_label);

        Color_R = new QHBoxLayout();
        Color_R->setObjectName(QStringLiteral("Color_R"));
        color_r_label = new QLabel(ColorAttribute);
        color_r_label->setObjectName(QStringLiteral("color_r_label"));
        color_r_label->setAlignment(Qt::AlignCenter);

        Color_R->addWidget(color_r_label);

        color_r_value = new QSpinBox(ColorAttribute);
        color_r_value->setObjectName(QStringLiteral("color_r_value"));
        color_r_value->setMaximum(255);

        Color_R->addWidget(color_r_value);


        Color->addLayout(Color_R);

        Color_G = new QHBoxLayout();
        Color_G->setObjectName(QStringLiteral("Color_G"));
        color_g_label = new QLabel(ColorAttribute);
        color_g_label->setObjectName(QStringLiteral("color_g_label"));
        color_g_label->setAlignment(Qt::AlignCenter);

        Color_G->addWidget(color_g_label);

        color_g_value = new QSpinBox(ColorAttribute);
        color_g_value->setObjectName(QStringLiteral("color_g_value"));
        color_g_value->setMaximum(255);

        Color_G->addWidget(color_g_value);


        Color->addLayout(Color_G);

        Color_B = new QHBoxLayout();
        Color_B->setObjectName(QStringLiteral("Color_B"));
        color_b_label = new QLabel(ColorAttribute);
        color_b_label->setObjectName(QStringLiteral("color_b_label"));
        color_b_label->setAlignment(Qt::AlignCenter);

        Color_B->addWidget(color_b_label);

        color_b_value = new QSpinBox(ColorAttribute);
        color_b_value->setObjectName(QStringLiteral("color_b_value"));
        color_b_value->setMaximum(255);

        Color_B->addWidget(color_b_value);


        Color->addLayout(Color_B);


        verticalLayout->addLayout(Color);


        retranslateUi(ColorAttribute);

        QMetaObject::connectSlotsByName(ColorAttribute);
    } // setupUi

    void retranslateUi(QWidget *ColorAttribute)
    {
        ColorAttribute->setWindowTitle(QApplication::translate("ColorAttribute", "Form", Q_NULLPTR));
        color_label->setText(QApplication::translate("ColorAttribute", "Color", Q_NULLPTR));
        color_r_label->setText(QApplication::translate("ColorAttribute", "R", Q_NULLPTR));
        color_g_label->setText(QApplication::translate("ColorAttribute", "G", Q_NULLPTR));
        color_b_label->setText(QApplication::translate("ColorAttribute", "B", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ColorAttribute: public Ui_ColorAttribute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORATTRIBUTE_H
