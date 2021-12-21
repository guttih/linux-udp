#include "frmroom.h"
#include "ui_frmroom.h"

frmRoom::frmRoom(QString roomName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmRoom)
{
    ui->setupUi(this);
    ui->lblTitle->setText(roomName);
}

frmRoom::frmRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmRoom)
{
    ui->setupUi(this);
}

frmRoom::~frmRoom()
{
    delete ui;
}
