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
    connect(&networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseNetworkResponse(QNetworkReply*)));
    connect(ui->refreshButton, SIGNAL(pressed()), this, SLOT(refreshClicked()));
}

void MarketData::refreshClicked()
{
    this->updatePrices();
}

void MarketData::updatePrices()
{
    this->getRequest(APIURL);
}

void MarketData::getRequest(const QString &urlString)
{
    QUrl url(urlString);
    QNetworkRequest req(url);
    networkAccessManager.get(req);
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
        this->parseCoinPairRates(finished);
    }

    finished->deleteLater();
}

void MarketData::parseCoinPairRates(QNetworkReply *reply)
{
    QString data = reply->readAll();
    QJsonParseError jsonParseError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8(), &jsonParseError);
    QJsonArray mainArray = jsonResponse.array();
    foreach (const QJsonValue &value, mainArray) {
        QJsonObject marketPair = value.toObject();
        if (marketPair.contains("Symbol") && marketPair["Symbol"].toString() == "LEO/GBP")
        {
            if (marketPair.contains("Rate"))
            {
                currentGBPPrice = marketPair["Rate"].toDouble();
                currentGBPBalancePrice = currentBalance * currentGBPPrice / 1000000;
            }
            this->ui->labelGBP1->setText(QSTRING_DOUBLE(currentGBPPrice));
            this->ui->labelGBP->setText(QSTRING_DOUBLE(currentGBPBalancePrice));
        }else if (marketPair.contains("Symbol") && marketPair["Symbol"].toString() == "LEO/EUR"){
            if (marketPair.contains("Rate"))
            {
                currentEURPrice = marketPair["Rate"].toDouble();
                currentEURBalancePrice = currentBalance * currentEURPrice / 1000000;
            }
            this->ui->labelEUR1->setText(QSTRING_DOUBLE(currentEURPrice));
            this->ui->labelEUR->setText(QSTRING_DOUBLE(currentEURBalancePrice));
        }else if (marketPair.contains("Symbol") && marketPair["Symbol"].toString() == "LEO/BTC"){
            if (marketPair.contains("Rate"))
            {
                currentBTCPrice = marketPair["Rate"].toDouble();
                currentBTCBalancePrice = currentBalance * currentBTCPrice / 1000000;
            }
            this->ui->labelBTC1->setText(QSTRING_DOUBLE(currentBTCPrice));
            this->ui->labelBTC->setText(QSTRING_DOUBLE(currentBTCBalancePrice));
        }else if (marketPair.contains("Symbol") && marketPair["Symbol"].toString() == "LEO/USD"){
            if (marketPair.contains("Rate"))
            {
                currentUSDPrice = marketPair["Rate"].toDouble();
                currentUSDBalancePrice = currentBalance * currentUSDPrice / 1000000;
            }
            this->ui->labelUSD1->setText(QSTRING_DOUBLE(currentUSDPrice));
            this->ui->labelUSD->setText(QSTRING_DOUBLE(currentUSDBalancePrice));
        }
    }
}

void MarketData::setModel(WalletModel *model)
{
    this->model = model;
    if(model && model->getOptionsModel())
    {
        setBalance(model->getBalance(), model->getStake(), model->getUnconfirmedBalance(), model->getImmatureBalance());
        connect(model, SIGNAL(balanceChanged(qint64, qint64, qint64, qint64)), this, SLOT(setBalance(qint64, qint64, qint64, qint64)));
    }
}

void MarketData::setBalance(qint64 balance, qint64 stake, qint64 unconfirmedBalance, qint64 immatureBalance)
{
    int unit = model->getOptionsModel()->getDisplayUnit();
    currentBalance = balance;
    ui->labelBalance->setText(BitcoinUnits::formatWithUnit(unit, currentBalance));
    this->updatePrices();
}

MarketData::~MarketData()
{
    delete ui;
}
