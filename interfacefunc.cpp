#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>

#include "interface.h"


void Interface::init(){

    m_socketClient = new QTcpSocket;

}


void Interface::connectToServer(QString ip, int port){

    m_socketClient->connectToHost(ip, port);

    qDebug() << Q_FUNC_INFO << "numéro de l'adresse Ip" << ip << "numéro du port" << port ;
    //else


}
