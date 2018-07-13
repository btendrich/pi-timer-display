#ifndef TimerController_H
#define TimerController_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>

class TimerController : public QObject
{
    Q_OBJECT
public:
    explicit TimerController(QObject *parent = 0);

    void setConnectionParameters(QString host, int port);
    void stopConnection();

    enum ConnectionState { NotConnected, AttemptingConnection, WaitForServerHelo, WaitForServerHeloAcknowledge, Running };

    bool sendStartCommand();
    bool sendStopCommand();
    bool sendResetCommand();

signals:
    void timerUpdate(QString newValue);
    void connectedToServer();
    void disconnectedFromServer();

public slots:
    void connected();
    void disconnected();
    void readyRead();

    void connectTimeout();
    void attemptConnection();
    void startConnection();

private:
    QTcpSocket *socket;
    QString host;
    int port;
    bool wasConnected;

    int currentState;

    void processIncomingLine( QString line );

    bool sendCommand( QString command );

};

#endif // TimerController_H
