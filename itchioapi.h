#ifndef ITCHIOAPI_H
#define ITCHIOAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

#include "objects/game.h"
#include "objects/downloadkey.h"
#include "objects/upload.h"

class ItchioApi : public QObject
{
    Q_OBJECT
public:
    explicit ItchioApi(QObject* parent = 0);
    void request(QString path, const char* slot);
    void login(QString username, QString password);
    void myGames();
    void myOwnedKeys();
    void downloadKeyUploads(DownloadKey key);

signals:
    void onLogin();
    void onLoginFailure(QString reason);
    void onMyGames(QList<Game> games);
    void onMyOwnedKeys(QList<DownloadKey> games);
    void onDownloadKeyUploads(DownloadKey key, QList<Upload> uploads);

public slots:
    void getMyGamesRequest();
    void getMyOwnedKeys();
    void getLoginRequest();
    void getDownloadKeyUploads();

private:
    QNetworkAccessManager* networkManager;
    int userId;
    QString apiKey;
    QString base;
};

#endif // ITCHIOAPI_H
