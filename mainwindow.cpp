#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&timerController, SIGNAL(connectedToServer()),this, SLOT(timerTabTimerServerConnected()));
    connect(&timerController, SIGNAL(disconnectedFromServer()),this, SLOT(timerTabTimerServerDisconnected()));
    connect(&timerController, SIGNAL(timerUpdate(QString)),this, SLOT(timerTabUpdateTimerTimeField(QString)));


    QSettings settings( QDir::homePath() + "/settings.ini", QSettings::IniFormat);

    // load the timer server/port into the timercontroller object


    ui->timerField->setStyleSheet( "background-color: black; color: blue;" );
    ui->timerField->setPlainText( "--:--:--" );

    processConfig();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processConfig() {
    QSettings settings( QDir::homePath() + "/settings.ini", QSettings::IniFormat);


    // set the timer connection settings
    settings.beginGroup("Timer");
    timerController.setConnectionParameters( settings.value("Host").toString(), settings.value("Port").toInt() );
    settings.endGroup();

    // build the clock update timer
    clockUpdateTimer = new QTimer(this);
    connect(clockUpdateTimer, SIGNAL( timeout()), this, SLOT(clockUpdateTimerTimeout()));

    // determine what type of timer we are
    settings.beginGroup("FullScreenTimer");
    if( settings.value("Type", "Timer").toString() == "Timer" ) {
        timerType = TimerType::CountUpTimer;
        timerController.startConnection();
    } else if ( settings.value("Type", "Timer").toString() == "Clock24Hour" ) {
        timerType = TimerType::Clock24Hour;
        clockUpdateTimer->start(15);
        ui->timerField->setStyleSheet( "background-color: black; color: white;" );
    } else if ( settings.value("Type", "Timer").toString() == "Clock12Hour" ) {
        timerType = TimerType::Clock12Hour;
        clockUpdateTimer->start(15);
        QFont font = ui->timerField->font();
        font.setPointSize(137);
        ui->timerField->setFont( font );
        ui->timerField->setStyleSheet( "background-color: black; color: white;" );
    } else {
        // default to count up timer
        timerType = TimerType::CountUpTimer;
        timerController.startConnection();
    }
    settings.endGroup();
}

void MainWindow::timerTabUpdateTimerTimeField(QString value)
{
    ui->timerField->setPlainText( value );
}

void MainWindow::timerTabTimerServerConnected()
{
    qDebug() << "## update window to show timer server connected";
    ui->timerField->setPlainText( "--:--:--" );
    ui->timerField->setStyleSheet( "background-color: black; color: green;" );
}

void MainWindow::timerTabTimerServerDisconnected()
{
    qDebug() << "## update window to show timer server as disconnected";
    ui->timerField->setPlainText( "--:--:--" );
    ui->timerField->setStyleSheet( "background-color: black; color: red;" );
}

void MainWindow::clockUpdateTimerTimeout()
{
    if( timerType == TimerType::Clock12Hour )
    {
        ui->timerField->setPlainText( QTime::currentTime().toString("hh:mm:ss ap") );
    } else if( timerType == TimerType::Clock24Hour )
    {
        ui->timerField->setPlainText( QTime::currentTime().toString("HH:mm:ss") );
    } else {
        ui->timerField->setPlainText( "xx:xx:xx" );
    }
}
