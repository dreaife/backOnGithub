#ifndef START_H
#define START_H

#include "widget.h"
#include "map.h"
#include <QWidget>
#include <QMessageBox>
#include "config.h"
#include <QKeyEvent>

namespace Ui {
class Start;
}

class Start : public QWidget
{
    Q_OBJECT

public:

    void initWindows();

    bool isSuccess;

    Map map;

    Widget* m;
    QLabel *textStart;
    QLabel* textFailed;

    void paintEvent(QPaintEvent *);

    explicit Start(QWidget *parent = 0);
    ~Start();

    void keyPressEvent(QKeyEvent* e);

public slots:
        void restart();
        void succes();

private:
    Ui::Start *ui;
};

#endif // START_H
