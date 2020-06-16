
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>

#include "interface.h"


void    Interface::viewChanger(int pageId)
{
    if (pageId == V_MAIN)
        QMetaObject::invokeMethod(this, "loadMain", Qt::QueuedConnection);
}


void    Interface::loadMain()
{
    setSource(QUrl("qrc:/main.qml"));
    m_pageId = V_MAIN;

}
