
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>

#include "qapp.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>

QApp::QApp(QWindow *parent) : QQuickView(parent)
{
    setResizeMode(QQuickView::SizeRootObjectToView);
    rootContext()->setContextProperty("cpp", this); // uncomment this line to use c++ function from QML
    viewChanger(V_CONNECT);
    show();
    m_sock = new QTcpSocket;
//    m_sock->connectToHost(QHostAddress::LocalHost,60000, QIODevice::ReadWrite);
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(pendingData()));
}

QApp::QApp(int port, int nbPlayer, int playerIndex, QStringList playerNameList, QStringList colorList,QWindow *parent) : QQuickView(parent)
  , m_port(port), m_nbPlayer(nbPlayer), m_playerIndex(playerIndex), m_playerList(playerNameList), m_colorList(colorList)
{
    setResizeMode(QQuickView::SizeRootObjectToView);
    rootContext()->setContextProperty("cpp", this); // uncomment this line to use c++ function from QML
    viewChanger(V_MAIN);

    show();
    m_sock = new QTcpSocket;
    m_sock->connectToHost(QHostAddress::LocalHost,port, QIODevice::ReadWrite);
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(pendingData()));
    if (playerNameList[playerIndex].contains("BOT_"))
        m_isBot = true;
}


/*
 * Gestion Close Event
 */
bool QApp::event(QEvent *event)
{
    if (event->type() == QEvent::Close)
    {
        if (m_pageId != V_MAIN)
        {
            viewChanger(V_MAIN);
            return true;
        }
    }
    return QQuickView::event(event);
}

QApp::~QApp()
{

}
