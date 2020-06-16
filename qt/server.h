#ifndef Server_H
#define Server_H
#include <QTcpSocket>
#include <QTcpServer>


class server : public QObject
{

    Q_OBJECT

public:
    server();

    void initServer ();



protected:

QTcpServer *m_server;
QTcpSocket *m_socket;

public slots :

void onNewConnection();
void onNewError();





};

#endif // Server_H
