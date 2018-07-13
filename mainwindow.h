#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QNetworkInterface>
#include <QDir>
#include <QSettings>

#include <QDebug>
#include <QTime>
#include <QFont>

#include "timercontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    enum TimerType { CountUpTimer, Clock24Hour, Clock12Hour };

public slots:
    void timerTabUpdateTimerTimeField(QString value);
    void timerTabTimerServerConnected();
    void timerTabTimerServerDisconnected();

    void clockUpdateTimerTimeout();

private:
    Ui::MainWindow *ui;
    TimerController timerController;
    void processConfig();
    int timerType;
    QTimer *clockUpdateTimer;
};

#endif // MAINWINDOW_H
