/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DIALOG_CAMERA_H
#define DIALOG_CAMERA_H

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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_dialogCamera
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSlider *valX;
    QSlider *valZ;
    QLabel *label_2;
    QSpinBox *valY_2;
    QSlider *valY;
    QLabel *label_3;
    QSpinBox *valZ_2;
    QSpinBox *valX_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *label_4;
    QSlider *valRotX;
    QSpinBox *valRotY_2;
    QSlider *valRotY;
    QSpinBox *valRotX_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogCamera)
    {
        if (dialogCamera->objectName().isEmpty())
            dialogCamera->setObjectName(QStringLiteral("dialogCamera"));
        dialogCamera->setWindowModality(Qt::WindowModal);
        dialogCamera->resize(467, 178);
        gridLayout = new QGridLayout(dialogCamera);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(dialogCamera);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        valX = new QSlider(groupBox);
        valX->setObjectName(QStringLiteral("valX"));
        valX->setMinimum(-2000);
        valX->setMaximum(2000);
        valX->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(valX, 0, 1, 1, 1);

        valZ = new QSlider(groupBox);
        valZ->setObjectName(QStringLiteral("valZ"));
        valZ->setMinimum(-2000);
        valZ->setMaximum(2000);
        valZ->setValue(0);
        valZ->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(valZ, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        valY_2 = new QSpinBox(groupBox);
        valY_2->setObjectName(QStringLiteral("valY_2"));
        valY_2->setMinimum(-2000);
        valY_2->setMaximum(2000);
        valY_2->setValue(0);

        gridLayout_2->addWidget(valY_2, 1, 2, 1, 1);

        valY = new QSlider(groupBox);
        valY->setObjectName(QStringLiteral("valY"));
        valY->setMinimum(-2000);
        valY->setMaximum(2000);
        valY->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(valY, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        valZ_2 = new QSpinBox(groupBox);
        valZ_2->setObjectName(QStringLiteral("valZ_2"));
        valZ_2->setMinimum(-2000);
        valZ_2->setMaximum(2000);

        gridLayout_2->addWidget(valZ_2, 2, 2, 1, 1);

        valX_2 = new QSpinBox(groupBox);
        valX_2->setObjectName(QStringLiteral("valX_2"));
        valX_2->setMinimum(-2000);
        valX_2->setMaximum(2000);

        gridLayout_2->addWidget(valX_2, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 2, 4);

        groupBox_2 = new QGroupBox(dialogCamera);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        valRotX = new QSlider(groupBox_2);
        valRotX->setObjectName(QStringLiteral("valRotX"));
        valRotX->setMinimum(-90);
        valRotX->setMaximum(90);
        valRotX->setValue(0);
        valRotX->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(valRotX, 0, 1, 1, 1);

        valRotY_2 = new QSpinBox(groupBox_2);
        valRotY_2->setObjectName(QStringLiteral("valRotY_2"));
        valRotY_2->setMinimum(-90);
        valRotY_2->setMaximum(90);

        gridLayout_3->addWidget(valRotY_2, 1, 2, 1, 1);

        valRotY = new QSlider(groupBox_2);
        valRotY->setObjectName(QStringLiteral("valRotY"));
        valRotY->setMinimum(-90);
        valRotY->setMaximum(90);
        valRotY->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(valRotY, 1, 1, 1, 1);

        valRotX_2 = new QSpinBox(groupBox_2);
        valRotX_2->setObjectName(QStringLiteral("valRotX_2"));
        valRotX_2->setMinimum(-90);
        valRotX_2->setMaximum(90);
        valRotX_2->setValue(0);

        gridLayout_3->addWidget(valRotX_2, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 4, 2, 1);

        buttonBox = new QDialogButtonBox(dialogCamera);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 1, 1, 4);


        retranslateUi(dialogCamera);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogCamera, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogCamera, SLOT(reject()));
        QObject::connect(valX, SIGNAL(valueChanged(int)), valX_2, SLOT(setValue(int)));
        QObject::connect(valX_2, SIGNAL(valueChanged(int)), valX, SLOT(setValue(int)));
        QObject::connect(valY, SIGNAL(valueChanged(int)), valY_2, SLOT(setValue(int)));
        QObject::connect(valY_2, SIGNAL(valueChanged(int)), valY, SLOT(setValue(int)));
        QObject::connect(valZ, SIGNAL(valueChanged(int)), valZ_2, SLOT(setValue(int)));
        QObject::connect(valZ_2, SIGNAL(valueChanged(int)), valZ, SLOT(setValue(int)));
        QObject::connect(valRotX, SIGNAL(valueChanged(int)), valRotX_2, SLOT(setValue(int)));
        QObject::connect(valRotX_2, SIGNAL(valueChanged(int)), valRotX, SLOT(setValue(int)));
        QObject::connect(valRotY, SIGNAL(valueChanged(int)), valRotY_2, SLOT(setValue(int)));
        QObject::connect(valRotY_2, SIGNAL(valueChanged(int)), valRotY, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(dialogCamera);
    } // setupUi

    void retranslateUi(QDialog *dialogCamera)
    {
        dialogCamera->setWindowTitle(QApplication::translate("dialogCamera", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("dialogCamera", "Position", nullptr));
        label->setText(QApplication::translate("dialogCamera", "Y:", nullptr));
        label_2->setText(QApplication::translate("dialogCamera", "Z:", nullptr));
        label_3->setText(QApplication::translate("dialogCamera", "X:", nullptr));
        groupBox_2->setTitle(QApplication::translate("dialogCamera", "Rotation", nullptr));
        label_5->setText(QApplication::translate("dialogCamera", "Yaw", nullptr));
        label_4->setText(QApplication::translate("dialogCamera", "Pitch", nullptr));
        valRotY_2->setSuffix(QApplication::translate("dialogCamera", " deg", nullptr));
        valRotX_2->setSuffix(QApplication::translate("dialogCamera", " deg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogCamera: public Ui_dialogCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DIALOG_CAMERA_H
