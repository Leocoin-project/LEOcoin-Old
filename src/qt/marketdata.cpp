#include "marketdata.h"
#include "ui_marketdata.h"
#include "main.h"
#include "wallet.h"
#include "base58.h"
#include "clientmodel.h"
#include "bitcoinrpc.h"

MarketData::MarketData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarketData)
{
    ui->setupUi(this);
}

void MarketData::setModel(ClientModel *model)
{
    this->model = model;
}

MarketData::~MarketData()
{
    delete ui;
}
