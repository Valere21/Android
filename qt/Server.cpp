#include "server.h"

server::server()
{

}


void server::initServer(){

        qDebug() << Q_FUNC_INFO << "test";

      /*  if(m_server){
            delete m_server;
            m_server = nullptr;
        }
    */
        m_server =  new QTcpServer();
        m_server->listen(QHostAddress::Any, 42424);


        connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
        //connect(m_server, SIGNAL(acceptError()),this, SLOT(onNewError()));




}

void server::onNewConnection(){

    QByteArray data;

    m_socket = m_server->nextPendingConnection();

    if (m_socket->bytesAvailable()){


        data = m_socket->readAll();
        qDebug() << Q_FUNC_INFO << "lecture des données" << data;
        m_socket->write(data);
        qDebug() << Q_FUNC_INFO <<"Ecriture des données";

    }

}

void server::onNewError(){

    qDebug() << "Erreur à la nouvelle connection ";
}
