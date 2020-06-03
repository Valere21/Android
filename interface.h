#ifndef INTERFACE_H
#define INTERFACE_H


#include <QtCore/QObject>
#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>

#include <QTcpSocket>



#define V_MAIN      1 //  id des views



class Interface : public QQuickView
{
    Q_OBJECT

public:
    explicit  Interface(QWindow *parent = nullptr);
    bool event(QEvent *event) override;
    ~Interface() override;


signals:

public slots:
   // void    handleChecker(int val);
    void connectToServer(QString ip, int port);


private slots:
    void    viewChanger(int id);
    void    loadMain();
    void init();


    protected:
    int m_pageId;

    QTcpSocket *m_socketClient;
};

#endif // INTERFACE_H
