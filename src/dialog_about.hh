/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DIALOG_ABOUT_H
#define DIALOG_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_dialogAbout
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogAbout)
    {
        if (dialogAbout->objectName().isEmpty())
            dialogAbout->setObjectName(QStringLiteral("dialogAbout"));
        dialogAbout->setWindowModality(Qt::WindowModal);
        dialogAbout->resize(318, 84);
        gridLayout = new QGridLayout(dialogAbout);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(dialogAbout);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(dialogAbout);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(dialogAbout);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogAbout, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogAbout, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialogAbout);
    } // setupUi

    void retranslateUi(QDialog *dialogAbout)
    {
        dialogAbout->setWindowTitle(QApplication::translate("dialogAbout", "Dialog", nullptr));
        label->setText(QApplication::translate("dialogAbout", "Trace is a toy raytracer written from scratch in C++.\n"
"Trace uses Qt, and so should you.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogAbout: public Ui_dialogAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DIALOG_ABOUT_H
