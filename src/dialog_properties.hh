/********************************************************************************
** Form generated from reading UI file 'properties.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DIALOG_PROPERTIES_H
#define DIALOG_PROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_dialogProperties
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QSpinBox *valY_2;
    QSpinBox *valX_2;
    QSlider *valX;
    QSlider *valY;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *valZ_2;
    QSlider *valZ;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QSlider *valReflect;
    QLabel *label_4;
    QSpinBox *valReflect_2;
    QPushButton *buttonColor;

    void setupUi(QDialog *dialogProperties)
    {
        if (dialogProperties->objectName().isEmpty())
            dialogProperties->setObjectName(QStringLiteral("dialogProperties"));
        dialogProperties->setWindowModality(Qt::WindowModal);
        dialogProperties->resize(551, 178);
        gridLayout = new QGridLayout(dialogProperties);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(dialogProperties);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 6, 0, 1, 1);

        valY_2 = new QSpinBox(groupBox);
        valY_2->setObjectName(QStringLiteral("valY_2"));
        valY_2->setMinimum(-2000);
        valY_2->setMaximum(2000);

        gridLayout_2->addWidget(valY_2, 1, 4, 1, 1);

        valX_2 = new QSpinBox(groupBox);
        valX_2->setObjectName(QStringLiteral("valX_2"));
        valX_2->setMinimum(-2000);
        valX_2->setMaximum(2000);

        gridLayout_2->addWidget(valX_2, 0, 4, 1, 1);

        valX = new QSlider(groupBox);
        valX->setObjectName(QStringLiteral("valX"));
        valX->setMinimum(-2000);
        valX->setMaximum(2000);
        valX->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(valX, 0, 1, 1, 1);

        valY = new QSlider(groupBox);
        valY->setObjectName(QStringLiteral("valY"));
        valY->setMinimum(-2000);
        valY->setMaximum(2000);
        valY->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(valY, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        valZ_2 = new QSpinBox(groupBox);
        valZ_2->setObjectName(QStringLiteral("valZ_2"));
        valZ_2->setMinimum(-2000);
        valZ_2->setMaximum(2000);

        gridLayout_2->addWidget(valZ_2, 6, 4, 1, 1);

        valZ = new QSlider(groupBox);
        valZ->setObjectName(QStringLiteral("valZ"));
        valZ->setMinimum(-2000);
        valZ->setMaximum(2000);
        valZ->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(valZ, 6, 1, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(dialogProperties);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 2, 1, 1);

        groupBox_2 = new QGroupBox(dialogProperties);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        valReflect = new QSlider(groupBox_2);
        valReflect->setObjectName(QStringLiteral("valReflect"));
        valReflect->setMaximum(100);
        valReflect->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(valReflect, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        valReflect_2 = new QSpinBox(groupBox_2);
        valReflect_2->setObjectName(QStringLiteral("valReflect_2"));
        valReflect_2->setMaximum(100);

        gridLayout_3->addWidget(valReflect_2, 2, 2, 1, 1);

        buttonColor = new QPushButton(groupBox_2);
        buttonColor->setObjectName(QStringLiteral("buttonColor"));

        gridLayout_3->addWidget(buttonColor, 1, 0, 1, 3);


        gridLayout->addWidget(groupBox_2, 1, 2, 1, 1);


        retranslateUi(dialogProperties);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogProperties, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogProperties, SLOT(reject()));
        QObject::connect(valX, SIGNAL(valueChanged(int)), valX_2, SLOT(setValue(int)));
        QObject::connect(valX_2, SIGNAL(valueChanged(int)), valX, SLOT(setValue(int)));
        QObject::connect(valY, SIGNAL(valueChanged(int)), valY_2, SLOT(setValue(int)));
        QObject::connect(valZ, SIGNAL(valueChanged(int)), valZ_2, SLOT(setValue(int)));
        QObject::connect(valY_2, SIGNAL(valueChanged(int)), valY, SLOT(setValue(int)));
        QObject::connect(valZ_2, SIGNAL(valueChanged(int)), valZ, SLOT(setValue(int)));
        QObject::connect(valReflect, SIGNAL(valueChanged(int)), valReflect_2, SLOT(setValue(int)));
        QObject::connect(valReflect_2, SIGNAL(valueChanged(int)), valReflect, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(dialogProperties);
    } // setupUi

    void retranslateUi(QDialog *dialogProperties)
    {
        dialogProperties->setWindowTitle(QApplication::translate("dialogProperties", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("dialogProperties", "Position", nullptr));
        label_3->setText(QApplication::translate("dialogProperties", "Z:", nullptr));
        label->setText(QApplication::translate("dialogProperties", "X: ", nullptr));
        label_2->setText(QApplication::translate("dialogProperties", "Y:", nullptr));
        groupBox_2->setTitle(QApplication::translate("dialogProperties", "Properties", nullptr));
        label_4->setText(QApplication::translate("dialogProperties", "Reflectivity", nullptr));
        valReflect_2->setSuffix(QApplication::translate("dialogProperties", "%", nullptr));
        buttonColor->setText(QApplication::translate("dialogProperties", "Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogProperties: public Ui_dialogProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DIALOG_PROPERTIES_H
