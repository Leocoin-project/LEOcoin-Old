#ifndef MARKETDATA_H
#define MARKETDATA_H

#include "clientmodel.h"
#include "main.h"
#include "wallet.h"
#include "base58.h"

#include <QWidget>

namespace Ui {
    class MarketData;
}

class ClientModel;

class MarketData : public QWidget
{
    Q_OBJECT

public:
    explicit MarketData(QWidget *parent = 0);
    ~MarketData();

    void setModel(ClientModel *model);

public slots:


signals:


private:
    Ui::MarketData *ui;
    ClientModel *model;

private slots:

};

#endif // MARKETDATA_H
