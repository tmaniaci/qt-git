#include "downloader.h"

Downloader::Downloader(QObject *parent) :
    QObject(parent)
{
}

void Downloader::doDownload()
{
    QString loginURL = "http://uat.itelecoach.com/home/doctorwaitingroom.php?host_id=coach1";

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(loginURL)));
}

void Downloader::replyFinished (QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        //qDebug() << reply->readAll();

        QString resp = reply->readAll();
        //qDebug() << "resp" << resp;

        QJsonDocument jsonResponse = QJsonDocument::fromJson(resp.toUtf8());
        //qDebug() << "QJsonDocument" <<  jsonResponse;

        QJsonObject jsonObject = jsonResponse.object();
        //qDebug() << "QJsonObject" << sett2;

        QJsonArray jsonArray = jsonObject["waitingroom"].toArray();
        //qDebug() <<"\n" << "QJsonArray" << jsonArray;

        QStringList arrival_dates;

        foreach (const QJsonValue & value, jsonArray)
                {
                    QJsonObject obj = value.toObject();
                    arrival_dates.append(obj["date_rfc2822"].toString());
                }

        qDebug() << "\n" << "Arrival Dates" << arrival_dates;


    }

    reply->deleteLater();
}


