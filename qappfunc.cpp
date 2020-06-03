
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QRandomGenerator>
#include <QTimer>

#include "qapp.h"

void    QApp::deportedConnect(QString address, int port, int playerIndex){
    m_sock->connectToHost(address, port, QIODevice::ReadWrite);
    connect(m_sock, SIGNAL(connected()), this, SLOT(deportedConnection()));
    m_playerIndex = playerIndex;
    m_port = port;
}

void    QApp::deportedConnection()
{
    QTimer::singleShot(250, [=](){

        m_sock->write("$\n");
    } );
}

int angleToTarget(int angle) {

    int modRes = 0;
    if (angle >= 350 || angle < 8)
        modRes = 20;
    else if ( angle < 26)
        modRes = 1;
    else if ( angle < 44)
        modRes = 18;
    else if ( angle < 62)
        modRes = 4;
    else if ( angle < 80)
        modRes = 16;
    else if ( angle < 98)
        modRes = 6;
    else if ( angle < 116)
        modRes = 10;
    else if ( angle < 134)
        modRes = 15;
    else if ( angle < 152)
        modRes = 2;
    else if ( angle < 170)
        modRes = 17;
    else if ( angle < 188)
        modRes = 3;
    else if ( angle < 206)
        modRes = 19;
    else if ( angle < 224)
        modRes = 7;
    else if ( angle < 242)
        modRes = 16;
    else if ( angle < 260)
        modRes = 8;
    else if ( angle < 278)
        modRes = 11;
    else if ( angle < 296)
        modRes = 14;
    else if ( angle < 314)
        modRes = 9;
    else if ( angle < 332)
        modRes = 12;
    else if ( angle < 350)
        modRes = 5;

    return modRes;
}
void QApp::sendDart(int value, int mult)
{
    QByteArray data;

    data.append("P").append(QString::number(m_playerIndex))
        .append("|").append(QString::number(value)).append("|").append(QString::number(mult)).append("\n");
    m_sock->write(data);
}

QPair<int, int> QApp::vectToDart(double dist, int angle)
{
    int mult = 1;
    if (dist >0.42 && dist <0.46)
        mult = 3;
    if (dist >0.7 && dist <0.74)
        mult = 2;
    if (dist >0.74)
        mult = 0;
    int targetPoint = angleToTarget(angle);
    if (dist < 0.07)
    {
        targetPoint = 25;
        mult = 1;
    }
    if (dist < 0.03 )
    {
        mult = 2;

    }

    QPair<int, int> dart(targetPoint, mult);

    return dart;

}

void QApp::botSendDart(Difficulty difficulty)
{
    QObject* obj = (QObject*)rootObject();
    if (difficulty == Difficulty::EASY)
    {
        double dist = QRandomGenerator::global()->generateDouble();
        int angle = QRandomGenerator::global()->bounded(360);

        QPair<int, int> dart= vectToDart(dist, angle);
        sendDart(dart.first, dart.second);
        QMetaObject::invokeMethod(obj, "updateModel",
            Q_ARG(QVariant, m_playerIndex),
            Q_ARG(QVariant, dart.first),
            Q_ARG(QVariant, dart.second));
    }
}

void QApp::pendingData()
{
    QTcpSocket* sock = (QTcpSocket*)sender();
    QObject* obj = (QObject*)rootObject();
    static int dartCount = 0;


    while (sock->bytesAvailable()) {
        QByteArray data = sock->readLine();

        if (data.at(0) == '*')
        {
            qDebug()<< "=D=>"<<Q_FUNC_INFO<<data ;

        }
        else if (data.at(0) == '$')
        {
            QString dataStr = QString(data);
            QStringList arg = dataStr.split(3);
            int i = 0;
            while (i < arg.length())
            {
                    qDebug()<< "== arg ==>" << arg.at(i);
                    if (arg.at(i) == QString("-c"))
                    {
                        int j = 0;
                        i++;
                        while (j < m_nbPlayer)
                        {
                            m_colorList.append(arg.at(i));
                            i++;
                            j++;
                        }
                        i--;
                    }
                    else if (arg.at(i) == QString("-n"))
                    {
                        i++;
                        m_nbPlayer = arg.at(i).toInt();
                        int j = 0;
                        i++;
                        while (j < m_nbPlayer)
                        {
                            m_playerList.append(arg.at(i));
                            i++;
                            j++;
                        }
                        i--;
                    }
                i++;
            }
            viewChanger(V_MAIN);
        }
        else
        {
            QList<QByteArray> spl = data.split('|');
            if (spl.count() >= 3)
            {

                dartCount = dartCount%3;
                QMetaObject::invokeMethod(obj, "updateModel",
                    Q_ARG(QVariant, (int)spl.at(0).at(1)-'0'),
                    Q_ARG(QVariant, spl.at(1).toInt()),
                    Q_ARG(QVariant, spl.at(2).toInt()));
                dartCount++;
                if (m_isBot
                        && dartCount == 3
                        && ((int)spl.at(0).at(1)-'0' == m_playerIndex - 1
                            || ( m_playerIndex == 0 && (int)spl.at(0).at(1)-'0' == m_playerList.count()-1)))
                {

                    dartCount = 0;
                    QTimer::singleShot(250, [=](){

                    botSendDart(Difficulty::EASY);
                    botSendDart(Difficulty::EASY);
                    botSendDart(Difficulty::EASY);
                    } );
                }

            }
        }
    }

}
