#ifndef FRMROOM_H
#define FRMROOM_H

#include <QWidget>

namespace Ui {
class frmRoom;
}

class frmRoom : public QWidget
{
    Q_OBJECT

public:
    explicit frmRoom(QWidget *parent = nullptr);
    ~frmRoom();

private:
    Ui::frmRoom *ui;
};

#endif // FRMROOM_H
