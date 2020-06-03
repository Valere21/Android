
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>

#include "qapp.h"


void    QApp::viewChanger(int pageId)
{
    if (pageId == V_MAIN)
        QMetaObject::invokeMethod(this, "loadMain", Qt::QueuedConnection);
    if (pageId == V_CONNECT)
        QMetaObject::invokeMethod(this, "loadConnect", Qt::QueuedConnection);
}


void    QApp::loadMain()
{
    setSource(QUrl("qrc:/main.qml"));
    m_pageId = V_MAIN;

    QObject* obj = (QObject*)rootObject();
    qDebug()<< "color :" << m_colorList;
    obj->setProperty("dartColor", m_colorList);
    obj->setProperty("playerIndex", m_playerIndex);

    int i = 0;

    while (i < m_playerList.count())
    {
        QMetaObject::invokeMethod(obj, "createPlayerModel",
            Q_ARG(QVariant, m_playerList.at(i)),
            Q_ARG(QVariant, m_colorList.at(i)));
        i++;
    }
}

void    QApp::loadConnect()
{
    setSource(QUrl("qrc:/connectView/connect.qml"));
    m_pageId = V_MAIN;

    QObject* obj = (QObject*)rootObject();
    qDebug()<< "color :" << m_colorList;
    obj->setProperty("dartColor", m_colorList);
    obj->setProperty("playerIndex", m_playerIndex);

    int i = 0;

    while (i < m_playerList.count())
    {
        QMetaObject::invokeMethod(obj, "createPlayerModel",
            Q_ARG(QVariant, m_playerList.at(i)),
            Q_ARG(QVariant, m_colorList.at(i)));
        i++;
    }
}
