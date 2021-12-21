#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gstring.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnOpen_clicked();
    //void on_pushButton_clicked();
    void on_btnClose_clicked();

    void on_listAvailable_itemSelectionChanged();

    void on_listOpen_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    void addTab(QString tabName);
    int getTabIndexOf(QString tabName);
    bool removeTab(QString tabName);
};
#endif // MAINWINDOW_H
