/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTextBrowser *CurrentBox;
    QPushButton *PrevButton;
    QPushButton *PauseButton;
    QPushButton *ResButton;
    QPushButton *SkipButton;
    QLabel *label_2;
    QLineEdit *commandInput;
    QPushButton *GoButton;
    QTextBrowser *OutputBox;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(479, 580);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 131, 16));
        CurrentBox = new QTextBrowser(centralwidget);
        CurrentBox->setObjectName(QStringLiteral("CurrentBox"));
        CurrentBox->setGeometry(QRect(10, 20, 441, 31));
        PrevButton = new QPushButton(centralwidget);
        PrevButton->setObjectName(QStringLiteral("PrevButton"));
        PrevButton->setGeometry(QRect(10, 60, 91, 32));
        PauseButton = new QPushButton(centralwidget);
        PauseButton->setObjectName(QStringLiteral("PauseButton"));
        PauseButton->setGeometry(QRect(100, 60, 131, 32));
        ResButton = new QPushButton(centralwidget);
        ResButton->setObjectName(QStringLiteral("ResButton"));
        ResButton->setGeometry(QRect(230, 60, 131, 32));
        SkipButton = new QPushButton(centralwidget);
        SkipButton->setObjectName(QStringLiteral("SkipButton"));
        SkipButton->setGeometry(QRect(360, 60, 91, 32));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 71, 31));
        commandInput = new QLineEdit(centralwidget);
        commandInput->setObjectName(QStringLiteral("commandInput"));
        commandInput->setGeometry(QRect(80, 100, 331, 31));
        GoButton = new QPushButton(centralwidget);
        GoButton->setObjectName(QStringLiteral("GoButton"));
        GoButton->setGeometry(QRect(410, 100, 41, 32));
        OutputBox = new QTextBrowser(centralwidget);
        OutputBox->setObjectName(QStringLiteral("OutputBox"));
        OutputBox->setGeometry(QRect(20, 150, 441, 361));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 479, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Audio Player", nullptr));
        label->setText(QApplication::translate("MainWindow", "Currently Playing:", nullptr));
        PrevButton->setText(QApplication::translate("MainWindow", "Previous", nullptr));
        PauseButton->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        ResButton->setText(QApplication::translate("MainWindow", "Resume", nullptr));
        SkipButton->setText(QApplication::translate("MainWindow", "Skip", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Command:", nullptr));
        commandInput->setText(QString());
        GoButton->setText(QApplication::translate("MainWindow", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
