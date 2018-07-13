/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *timerField_top;
    QTextEdit *timerField;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        timerField_top = new QPlainTextEdit(centralWidget);
        timerField_top->setObjectName(QStringLiteral("timerField_top"));
        timerField_top->setEnabled(false);
        timerField_top->setGeometry(QRect(0, 0, 1281, 231));
        QFont font;
        font.setFamily(QStringLiteral("Menlo"));
        font.setPointSize(189);
        timerField_top->setFont(font);
        timerField_top->setLayoutDirection(Qt::LeftToRight);
        timerField_top->setStyleSheet(QStringLiteral("background-color: white; color: red;"));
        timerField_top->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        timerField_top->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        timerField = new QTextEdit(centralWidget);
        timerField->setObjectName(QStringLiteral("timerField"));
        timerField->setGeometry(QRect(0, 230, 1281, 271));
        timerField->setFont(font);
        timerField->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        timerField->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        timerField_top->setPlainText(QApplication::translate("MainWindow", "00:00:00", Q_NULLPTR));
        timerField->setPlaceholderText(QApplication::translate("MainWindow", "00:00:00", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
