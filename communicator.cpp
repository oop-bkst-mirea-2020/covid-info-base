#include "communicator.h"



Communicator::Communicator()
{
    base_url = "https://covid-api.com/api/";
}

Communicator::Communicator(QString url)
{
    base_url = url;
}

void Communicator::getCountries()
{
    //Базовый адрес для запроса
    QString url = base_url+"regions";
    //Запрос
    QNetworkRequest request =  QNetworkRequest(QUrl(url));
    //Объект доступа - содержит общую конфигурацию и настройки для посылаемых запросов
    QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
    //Связь слотов и сигналов
    connect(mngr, &QNetworkAccessManager::finished,this,&Communicator::getResponse);
    mngr->get(request);
}

void Communicator::getResponse(QNetworkReply *reply)
{
    QByteArray str = reply->readAll();
    qDebug() << str;
    //Посылаем сигнал
    emit resp_countries(str);
}

