#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include <qstring.h>
#include <QObject>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class Communicator:public QObject
{
   Q_OBJECT
   QString base_url;
public:
    Communicator();
    Communicator(QString url);

public slots:
    void getCountries();
    void getResponse(QNetworkReply *reply);

signals:
    void resp_countries(QByteArray str);
};

#endif // COMMUNICATOR_H
