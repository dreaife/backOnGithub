#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "config.h"
#include <QMessageBox>
#include <QPixmap>
#include <QPainter>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

    gamePlayer members[GAME_PLAYER_NUM];

    QPixmap back;

    void initPlayersData();

    void clearText();

    void saveGamePlayerData();

    void paintEvent(QPaintEvent*);

signals:
    void accept();

private slots:
    void on_DisRegister_clicked();

    void on_regiserConfine_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
