#ifndef QAPP_H
#define QAPP_H


#include <QtCore/QObject>
#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QTcpSocket>





#define V_MAIN      1 //  id des views
#define V_CONNECT      2 //  id des views



class QApp : public QQuickView
{
    Q_OBJECT

public:
    explicit  QApp(QWindow *parent = nullptr);
              QApp(int port, int nbPlayer, int playerIndex, QStringList playerNameList, QStringList colorList,QWindow *parent = nullptr);
    bool event(QEvent *event) override;
    ~QApp() override;

    enum Difficulty{
        EASY,
        MEDIUM,
        HARD
    };


signals:

public slots:
//    void    handleChecker(int val);
    void    pendingData();
    void    sendDart(int value, int mult);
    void    botSendDart(Difficulty difficulty);
    QPair<int, int> vectToDart(double dist, int angle);
    void    deportedConnect(QString address, int port, int playerIndex);

private slots:
    void    viewChanger(int id);
    void    loadMain();
    void    loadConnect();
    void    deportedConnection();


private:
    int m_pageId;
    int m_port;
    int m_nbPlayer;
    int m_playerIndex;
    QStringList m_playerList;
    QStringList m_colorList;
    QTcpSocket *m_sock;
    bool m_isBot = false;
};

#endif // QAPP_H
