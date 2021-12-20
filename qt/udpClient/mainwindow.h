#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTimer *timer;
    void init();


private slots:
    void on_pushButtonSend_clicked();
    void myFunction();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
