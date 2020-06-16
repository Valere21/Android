
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include "archive.h"
#include "interface.h"


Interface::Interface(QWindow *parent) : QQuickView(parent)
{
    Archive ObjArchive;


    setResizeMode(QQuickView::SizeRootObjectToView);

    init();
    setGeometry(300,300, 650, 325);             //Définit la taille de l'app
    rootContext()->setContextProperty("cpp", this); // uncomment this line to use c++ function from QML -- Rajouter le mot clé "cpp" pour appeller une fct d'un .cpp dans un fichier .qml
    viewChanger(V_MAIN);
    //showFullScreen();                            Permet de passer l'app en full screen
    //showMaximized();                             Passe en fullScreen mais conserve la barre de tâche
    show();

}


/*
 * Gestion Close Event                              //Mettre cette fonction en commentaire à la création d'une classe qml
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
