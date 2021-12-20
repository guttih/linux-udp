#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

void MainWindow::init(){
    ui->textEdit->setText("Þetta \n er \n\tindentað\n\t\tdouble indentað as d asd asdf adfsafdsf f faf fa dsa fsdd\n\n\n\n\n\n\n\n\n\n\n\nstuff");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myFunction()));
    timer->start();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette readOnlyPalette = ui->textEdit->palette();
    QColor mainWindowBgColor = palette().color(QPalette::Window);
    readOnlyPalette.setColor(QPalette::Base, mainWindowBgColor);
    ui->textEdit->setPalette(readOnlyPalette);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButtonSend_clicked()
{
    ui->label->setText("Að senda\n\n dude");
}

void MainWindow::myFunction()
{
    qDebug() << "Firing myFunction() update..."
}

