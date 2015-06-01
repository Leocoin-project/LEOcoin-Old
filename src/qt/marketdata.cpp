#include "marketdata.h"
#include "ui_marketdata.h"
#include "main.h"
#include "wallet.h"
#include "base58.h"
#include "walletmodel.h"
#include "bitcoinrpc.h"
#include "bitcoinunits.h"
#include "optionsmodel.h"

MarketData::MarketData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarketData)
{
    ui->setupUi(this);
    QObject::connect(&m_nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseNetworkResponse(QNetworkReply*)));
    connect(ui->refreshButton, SIGNAL(pressed()), this, SLOT(updatePrices()));
    this->updatePrices();
}

void MarketData::updatePrices()
{
    this->getRequest(APIURL);
}

void MarketData::setModel(WalletModel *model)
{
    this->model = model;
    if(model && model->getOptionsModel())
    {
        this->setBalance();
    }
}

void MarketData::getRequest(const QString &urlString)
{
    QUrl url (urlString);
    QNetworkRequest req (url);
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    req.setSslConfiguration(config);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json; charset=utf-8");
    m_nam.get(req);
}

void MarketData::parseNetworkResponse(QNetworkReply *finished )
{
    QUrl requestUrl = finished->url();

    if ( finished->error() != QNetworkReply::NoError )
    {
        // A communication error has occurred
        emit networkError(finished->error());
        return;
    }

    if (requestUrl == APIURL)
    {
        this->parseSummary(finished);
    }

    finished->deleteLater();
}

void MarketData::parseSummary(QNetworkReply *reply)
{
    QString data = reply->readAll();
    qDebug() << "Summary response:" << data;

    QJsonParseError jsonParseError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8(), &jsonParseError);
    if (jsonResponse.isObject())
    {
        QJsonObject mainObject = jsonResponse.object();
        if (!mainObject.contains("success") && !mainObject["success"].toBool())
        {
            return;
        }

        if (mainObject.contains("result"))
        {
            QJsonArray resultArray = mainObject["result"].toArray();
            foreach (const QJsonValue &value, resultArray)
            {
                QJsonObject marketObject = value.toObject();
                if (marketObject.contains("MarketName") && marketObject["MarketName"].toString() == "BTC-XWC")
                {
                    if (marketObject.contains("Last"))
                    {
                        currentGBPPrice = marketObject["Last"].toDouble();
                    }

                    // Updating summary labels
                    this->ui->labelBTC->setText(QSTRING_DOUBLE(currentGBPPrice));
               }
           }
       }

    } else {
        qWarning() << "Parsing summary failed with error: " << jsonParseError.errorString();
    }
}

void MarketData::setBalance()
{
    int unit = model->getOptionsModel()->getDisplayUnit();
    currentBalance = this->model->getBalance();
    ui->labelBalance->setText(BitcoinUnits::formatWithUnit(unit, currentBalance));
}

MarketData::~MarketData()
{
    delete ui;
}
