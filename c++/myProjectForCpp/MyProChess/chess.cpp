#include "chess.h"

Chess::Chess()
{
    W = GAME_BORED_WIDTH;
    LW = GAME_BORED_LINE_WIDTH;
    R = GAME_SCAN_RANGE;
}

void Chess::setChessPic(QString e){
    this->m_chess.load(e);

    this->m_Rect.setWidth(m_chess.width());
    this->m_Rect.setHeight(m_chess.height());

    chessHide();
}

void Chess::chessHide(){
    m_Rect.moveTo(GAME_WIDTH+m_chess.width(),GAME_HEIGHT+m_chess.height());
}

int Chess::getHeight(){
    return this->m_chess.height();
}

int Chess::getWidth(){
    return this->m_chess.width();
}

void Chess::chessMove(int x, int y){
    x = W + LW*x;
    y = W + LW*y;
    m_Rect.moveTo(x-m_chess.width()/2,y-m_chess.height()/2);
}
