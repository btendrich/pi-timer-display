#include "timercontroller.h"

TimerController::TimerController(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    wasConnected = false;
    currentState = ConnectionState::NotConnected;
    emit disconnectedFromServer();
}

void TimerController::setConnectionParameters(QString host, int port)
{
    qDebug() << "TimerController::setConectionParameters(" << host << "," << port << ") called";
    this->host = host;
    this->port = port;
}

void TimerController::startConnection()
{
    qDebug() << "TimerController::startConnection() called";
    currentState = ConnectionState::AttemptingConnection;
    socket->abort();
    QTimer::singleShot(1000, this, SLOT(attemptConnection()));
}

void TimerController::stopConnection()
{
    qDebug() << "TimerController::stopConnection() called";
    if( currentState != ConnectionState::NotConnected )
        socket->abort();
}

void TimerController::attemptConnection()
{
    qDebug() << "TimerController::attemptConnection() called";
    qDebug() << "attempting connection to (" << host << "," << port << ")";

    socket->connectToHost( host, port );

    // you have 5 second to negotiate the connection (including the protocol versions) or fuck you...
    QTimer::singleShot(5000, this, SLOT(connectTimeout()));

}

void TimerController::connectTimeout()
{
    if( currentState != ConnectionState::Running)
    {
        qDebug() << "Failed to connect (or negotiate protocol) in 5 seconds... die off and retry";
        startConnection();
    }
}

void TimerController::connected()
{
    qDebug() << "TimerController::connected";

    currentState = ConnectionState::WaitForServerHelo;
}

void TimerController::disconnected()
{
    qDebug() << "TimerController::disconnected() called";
    if( currentState == ConnectionState::Running)
    {
        qDebug() << "disconnected() called and I was successfully connected to the host... starting a 5 second delay to attempt reconnect...";
        currentState = ConnectionState::NotConnected;
        emit disconnectedFromServer();
        QTimer::singleShot(5000, this, SLOT(startConnection()));
    }
}

void TimerController::readyRead()
{
    // read the data from the socket
    QString buffer = socket->readAll();
    buffer.remove(QRegExp("[\\r]"));
    QStringList lines = buffer.split("\n", QString::SkipEmptyParts);

    for( int i = 0; i < lines.size(); ++i)
    {
        processIncomingLine( lines.at(i) );
    }

}

void TimerController::processIncomingLine( QString line )
{
    QStringList args = line.split(" ", QString::SkipEmptyParts);

    switch( currentState )
    {
        case ConnectionState::WaitForServerHelo:
            if( args.at(0).toUpper() == "HELO" )
            {
                // this is a HELO
                if( args.at(1).toUpper() == "TIMERSERVER" )
                {
                    // this is from a TimerServer
                    qDebug() << "Received HELO from TimerServer speaking version " << args.at(2);
                    socket->write("HELO 0.1\r\n");
                    currentState = ConnectionState::WaitForServerHeloAcknowledge;
                } else {
                    qDebug() << "While wating for server HELO we received: '" << line << "'";
                }
            } else {
                qDebug() << "While wating for server HELO we received: '" << line << "'";
            }
            break;
        case ConnectionState::WaitForServerHeloAcknowledge:
            if( args.at(0).toUpper() == "OK" )
            {
                currentState = ConnectionState::Running;
                emit connectedToServer();
                qDebug() << "Successfully negotiated a connection with the TimerServer...";
            } else {
                qDebug() << "While wating for server to acknowledge our HELO we received: '" << line << "'";
            }
            break;
        case ConnectionState::Running:
            if( args.at(0).toUpper() == "UPDATE" )
            {
                emit timerUpdate( args.at(1) );
            } else {
                qDebug() << "Received unknown command from TimerServer '" << args.at(0) << "'";
            }
            break;
    }
}

bool TimerController::sendStartCommand()
{
    return sendCommand( "START" );
}

bool TimerController::sendStopCommand()
{
    return sendCommand( "STOP" );
}

bool TimerController::sendResetCommand()
{
    return sendCommand( "RESET" );
}

bool TimerController::sendCommand(QString command)
{
    if( currentState == ConnectionState::Running )  {

        qDebug() << "Send command '" << command << "' to server";
        QString toServer = command + "\r\n";
        socket->write( toServer.toStdString().c_str() );
    }
    return false;
}
