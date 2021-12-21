#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frmroom.h"
//#include "json.h"
#include "gstring.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Json json("{\"hello\":\"world\"}");
    String str = "bull";
    ui->tabWidget->removeTab(1);
    ui->listAvailable->addItem("Public");
}

void MainWindow::addTab(QString tabName)
{
    int ret = ui->tabWidget->addTab(new frmRoom(), tabName);
}

int MainWindow::getTabIndexOf(QString tabName)
{
    for (int i = 0; i < ui->tabWidget->count(); i++) {
        QString test = ui->tabWidget->tabText(i);
         if (tabName == test )
             return i;
    }
    return -1;

}
bool MainWindow::removeTab(QString tabName)
{
    int index = getTabIndexOf(tabName);
    if (index > -1)
    {
        QWidget *pWidget = ui->tabWidget->widget(index);
        delete pWidget;
        ui->tabWidget->removeTab(index);
        return true;
    }
    return false;
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnOpen_clicked()
{
   QListWidgetItem *pItem = ui->listAvailable->currentItem();

   if (pItem) {
       QString name = pItem->text();
       addTab(name);
       ui->listOpen->addItem(name);
       ui->listAvailable->removeItemWidget(pItem);
       delete pItem;

   }
}


void MainWindow::on_btnClose_clicked()
{
    QListWidgetItem *pItem = ui->listOpen->currentItem();

    if (pItem) {
        QString name = pItem->text();
        addTab(name);
        ui->listAvailable->addItem(name);
        ui->listOpen->removeItemWidget(pItem);
        delete pItem;
        removeTab(name);

    }

}

