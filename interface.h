#ifndef Interface_H
#define Interface_H


//#include <QtCore/QObject>
//#include <QtGui/QGuiApplication>
//#include <QtQuick/QQuickView>
//#include <QtQml/QQmlApplicationEngine>
//#include <QtQml/QQmlContext>

#include <QObject>
#include <QtQuick>
#include <QTcpSocket>
#include <QTcpServer>


#define V_MAIN      1 //  id des views



class Interface : public QQuickView
{
    Q_OBJECT

public:
    explicit  Interface(QWindow *parent = nullptr);
    bool event(QEvent *event) override;
    ~Interface() override;


    void init();


    void writeSensorLux(QByteArray message);
    void writeSensorSound(QByteArray message);




    QTcpServer *server =  nullptr;
    QTcpSocket *socket = nullptr;
    QList <QTcpSocket*> listSocket;



signals:

public slots:
    // void    handleChecker(int val);
    //void onGetValue(){}

    //void msgDetect(QByteArray msg);

    void luxDetect();
    void soundDetect();
    void onTest();

    void onNewConnection();
    void onReadyRead();

    void socketStateChanged (QAbstractSocket::SocketState socketState);
    void socketError(QAbstractSocket::SocketError socketError);
    void socketDisconnected();


    void displayArchive();











private slots:
    void    viewChanger(int id);
    void    loadMain();



private:
    int m_pageId;
};

#endif // Interface_H
