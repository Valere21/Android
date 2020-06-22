
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include "interface.h"


Interface::Interface(QWindow *parent) : QQuickView(parent)
{
    setResizeMode(QQuickView::SizeRootObjectToView);
    setGeometry(120,120, 650, 325);             //Définit la taille de l'app

    rootContext()->setContextProperty("cpp", this); // uncomment this line to use c++ function from QML
    viewChanger(V_MAIN);
    init();
    show();
}


/*
 * Gestion Close Event
 */
bool Interface::event(QEvent *event)
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



Interface::~Interface()
{

}
