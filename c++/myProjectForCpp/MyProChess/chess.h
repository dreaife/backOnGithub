#ifndef CHESS_H
#define CHESS_H
#include "config.h"
#include <QRect>
#include <QPixmap>
#include <QString>

class Chess
{
public:
    Chess();

    QPixmap m_chess;

    QRect m_Rect;

    int W,LW,R;

    void setChessPic(QString e);

    void chessHide();
    void chessMove(int x,int y);

    int getWidth();
    int getHeight();
};

#endif // CHESS_H
