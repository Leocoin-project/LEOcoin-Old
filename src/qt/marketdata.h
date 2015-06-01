#ifndef MARKETDATA_H
#define MARKETDATA_H

#include "clientmodel.h"
#include "main.h"
#include "wallet.h"
#include "base58.h"

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QtNetwork/QtNetwork>
#include <QCoreApplication>
#include <QDebug>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QVariant>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>

#define QSTRING_DOUBLE(var) QString::number(var, 'f', 8)

namespace Ui {
    class MarketData;
}

class WalletModel;

class MarketData : public QWidget
{
    Q_OBJECT

public:
    explicit MarketData(QWidget *parent = 0);
    ~MarketData();

    void setModel(WalletModel *model);
public slots:
    void updatePrices();
signals:
    void networkError(QNetworkReply::NetworkError err);

private:
    Ui::MarketData *ui;
    WalletModel *model;
    qint64 currentBalance;
    QNetworkAccessManager m_nam;
    const QString APIURL = "https://bittrex.com/api/v1.1/public/getmarketsummary?market=btc-xwc";
    double currentGBPPrice;

    void setBalance();
    void getRequest(const QString &url);
    void parseSummary(QNetworkReply *reply);

private slots:
    void parseNetworkResponse(QNetworkReply *finished);
};

#endif // MARKETDATA_H
