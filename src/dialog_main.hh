/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DIALOG_MAIN_H
#define DIALOG_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionQuit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpinBox *valThreads;
    QLabel *label_2;
    QSpinBox *valSamples;
    QSpinBox *valWidth;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *valHeight;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QComboBox *objectList;
    QPushButton *buttonCamera;
    QPushButton *lampButton;
    QPushButton *objectButton;
    QCheckBox *valReflections;
    QCheckBox *valShadows;
    QPushButton *buttonTrace;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName(QStringLiteral("Main"));
        Main->resize(527, 350);
        actionAbout = new QAction(Main);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionSave = new QAction(Main);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionQuit = new QAction(Main);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(Main);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        valThreads = new QSpinBox(groupBox);
        valThreads->setObjectName(QStringLiteral("valThreads"));
        valThreads->setMinimum(1);
        valThreads->setMaximum(100);

        gridLayout_2->addWidget(valThreads, 0, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 2, 1, 1);

        valSamples = new QSpinBox(groupBox);
        valSamples->setObjectName(QStringLiteral("valSamples"));
        valSamples->setMaximum(1000);
        valSamples->setValue(20);

        gridLayout_2->addWidget(valSamples, 1, 3, 1, 1);

        valWidth = new QSpinBox(groupBox);
        valWidth->setObjectName(QStringLiteral("valWidth"));
        valWidth->setMinimum(0);
        valWidth->setMaximum(1000);
        valWidth->setValue(500);

        gridLayout_2->addWidget(valWidth, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        valHeight = new QSpinBox(groupBox);
        valHeight->setObjectName(QStringLiteral("valHeight"));
        valHeight->setMaximum(5000);
        valHeight->setValue(250);

        gridLayout_2->addWidget(valHeight, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        objectList = new QComboBox(groupBox_2);
        objectList->addItem(QString());
        objectList->setObjectName(QStringLiteral("objectList"));

        gridLayout_3->addWidget(objectList, 3, 1, 1, 1);

        buttonCamera = new QPushButton(groupBox_2);
        buttonCamera->setObjectName(QStringLiteral("buttonCamera"));

        gridLayout_3->addWidget(buttonCamera, 1, 1, 1, 1);

        lampButton = new QPushButton(groupBox_2);
        lampButton->setObjectName(QStringLiteral("lampButton"));

        gridLayout_3->addWidget(lampButton, 3, 0, 1, 1);

        objectButton = new QPushButton(groupBox_2);
        objectButton->setObjectName(QStringLiteral("objectButton"));

        gridLayout_3->addWidget(objectButton, 1, 0, 1, 1);

        valReflections = new QCheckBox(groupBox_2);
        valReflections->setObjectName(QStringLiteral("valReflections"));
        valReflections->setChecked(true);

        gridLayout_3->addWidget(valReflections, 3, 2, 1, 1);

        valShadows = new QCheckBox(groupBox_2);
        valShadows->setObjectName(QStringLiteral("valShadows"));
        valShadows->setChecked(true);

        gridLayout_3->addWidget(valShadows, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        buttonTrace = new QPushButton(centralwidget);
        buttonTrace->setObjectName(QStringLiteral("buttonTrace"));

        verticalLayout->addWidget(buttonTrace);

        Main->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 527, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        Main->setMenuBar(menubar);
        statusbar = new QStatusBar(Main);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Main->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionQuit);
        menuAbout->addAction(actionAbout);

        retranslateUi(Main);

        QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QMainWindow *Main)
    {
        Main->setWindowTitle(QApplication::translate("Main", "MainWindow", nullptr));
        actionAbout->setText(QApplication::translate("Main", "&About", nullptr));
        actionSave->setText(QApplication::translate("Main", "&Save", nullptr));
        actionQuit->setText(QApplication::translate("Main", "&Quit", nullptr));
        groupBox->setTitle(QApplication::translate("Main", "Tracer Settings", nullptr));
        label_2->setText(QApplication::translate("Main", "Samples:", nullptr));
        label_5->setText(QApplication::translate("Main", "Height:", nullptr));
        label_4->setText(QApplication::translate("Main", "Width:", nullptr));
        label_3->setText(QApplication::translate("Main", "Threads:", nullptr));
        groupBox_2->setTitle(QApplication::translate("Main", "Object Settings", nullptr));
        objectList->setItemText(0, QApplication::translate("Main", "Objects", nullptr));

        buttonCamera->setText(QApplication::translate("Main", "Camera", nullptr));
        lampButton->setText(QApplication::translate("Main", "New Lamp", nullptr));
        objectButton->setText(QApplication::translate("Main", "New Object", nullptr));
        valReflections->setText(QApplication::translate("Main", "Reflections", nullptr));
        valShadows->setText(QApplication::translate("Main", "Shadows", nullptr));
        buttonTrace->setText(QApplication::translate("Main", "Trace", nullptr));
        menuFile->setTitle(QApplication::translate("Main", "&File", nullptr));
        menuAbout->setTitle(QApplication::translate("Main", "&About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DIALOG_MAIN_H
