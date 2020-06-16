#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QTcpSocket>

//#include <wiringPi.h>

#include "interface.h"

void Interface::onTest(){

    qDebug() << "Test du QML";

    QObject* obj = (QObject*)rootObject();                      // l'objet root est l'objet le plus haut soit la Window (l'Item). Il est indsipensable de créer un Item à la racine pour utiliser la fct findChild (création de l'item Parent pour appeller un item fille)
    QObject* obj2 = obj->findChild<QObject*>("rect");           //Pour toucher un item en particulier il lui set un name  et les caractéristiques que l'on souhaite modifié
    obj2->setProperty("color", "lightpurple");

}

void  Interface::init(){

    if (server){

        delete server;
        server = nullptr;
    }


    server =  new QTcpServer(this);
    server->listen(QHostAddress::Any, 4242);
    server->setMaxPendingConnections(1);

    connect(server, SIGNAL(newConnection()),this, SLOT(onNewConnection()));


}


/*void Interface::msgDetect(QByteArray msg){

    QObject* rootItem = (QObject*)rootObject();
    QObject* txtMsg = rootItem->findChild<QObject*>("txtServ");
    txtMsg->setProperty("text", msg);
}*/

void Interface::luxDetect(){
    qDebug() << Q_FUNC_INFO;
    QString messageLux = "Il y'a détection par le capteur de lumière";

    QObject* rootItem = (QObject*)rootObject();                      // l'objet root est l'objet le plus haut soit la Window (l'Item). Il est indsipensable
    QObject* txtLux = rootItem->findChild<QObject*>("sensorLuxValue");
    txtLux->setProperty("text", messageLux);

    QObject* lightLux = rootItem->findChild<QObject*>("luxIndicator");

    lightLux->setProperty("color", "c01414");
    lightLux->setProperty ("active", "true");

}

void Interface::soundDetect(){

    qDebug() << Q_FUNC_INFO;
    QString messageSound = "Il y'a détection par le capteur à ultrason";

    QObject* rootItem = (QObject*)rootObject();                      // l'objet root est l'objet le plus haut soit la Window (l'Item). Il est indsipensable de créer un Item à la racine pour utiliser la fct findChild (création de l'item Parent pour appeller un item fille)
    QObject* txtSound = rootItem->findChild<QObject*>("sensorSoundValue");
    txtSound->setProperty("text",messageSound);

    QObject* lightSound = rootItem->findChild<QObject*>("soundIndicator");
    lightSound->setProperty("color", "c01414");
    lightSound->setProperty ("active", "true");

}

void Interface::onNewConnection(){

    qDebug() << "Nouvelle connection";


    socket = server->nextPendingConnection();

    listSocket.append(socket);

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));                                                                          //Connect au slot de lecture

    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));                      //Slot d'erreur
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));        //Slot de changement d'état
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

    soundDetect();
    luxDetect();

}

void Interface::onReadyRead(){
    //bool flag = true;
    qDebug() << Q_FUNC_INFO << "Test du onReadyRead";
    QByteArray message;    
    message.clear();

    while (socket->bytesAvailable()){
        //flag = false;
        qDebug() << "Test de lecture";
        message = socket->readAll();
        qDebug() << message;
        /*if (flag == false){
        msgDetect(message);
        flag = true;
        }*/
        socket->write("Le message reçu est :" + message);
    }

    //    message = "Test message";
    //    writeSensorLux(message);


}

void Interface::writeSensorLux(QByteArray message){

    //**** PLACER ICI LES VALEURS DES CAPTEURS (OU SIMPLEMENT LEURS DETECTION)****//

    socket->write(message);
}

void Interface::socketError(QAbstractSocket::SocketError socketError){

    qDebug() << "Erreur du socket, numéro d'erreur :" << socketError;
}

void Interface::socketStateChanged(QAbstractSocket::SocketState socketState){

    qDebug() << "Etat du socket à changer" << socketState;


}

void Interface::socketDisconnected(){

    qDebug() << "Socket déconnecter";
}

void Interface::displayArchive(){
    static bool opacity = true;

    QObject* rootItem = (QObject*)rootObject();                      // l'objet root est l'objet le plus haut soit la Window (l'Item). Il est indsipensable
    QObject* archiveButton = rootItem->findChild<QObject*>("swipeArchive");
    archiveButton->setProperty("opacity", opacity);
    opacity = !opacity;

}


