#include "robot.h"

Robot::Robot(QWidget *parent) :
    QWidget(parent)
{
    memset(w,0,sizeof(w));
    srand((unsigned int)time(NULL));

    ComType = 1;
    PerType = -1;

    robNum = 0;
    perNum = 0;

}

void Robot::getType(int x){
    if(x){
        ComType = 1;
        PerType = 0;
    }else{
        ComType = 0;
        PerType = 1;
    }
}

int Robot::calPoint(int t){
    if(t==0)
        return WEIGHT_ZERO;
    else if(t==1)
        return WEIGHT_ONE;
    else if(t==2)
        return WEIGHT_ZERO;
    else if(t==3)
        return WEIGHT_THREE;
    else
        return WEIGHT_FOUR;
}

int Robot::calPointPrim(int t){
    if(t==0)
        return WEIGHT_ZERO_PRIM;
    else if(t==1)
        return WEIGHT_ONE_PRIM;
    else if(t==2)
        return WEIGHT_ZERO_PRIM;
    else if(t==3)
        return WEIGHT_THREE_PRIM;
    else
        return WEIGHT_FOUR_PRIM;
}

cP Robot::getPointPrim(int tb[16][16]){
    int cb[16][16];
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
            cb[i][j]=tb[i][j];
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++){
            w[i][j]=0;
            if(cb[i][j]==1||cb[i][j]==-1) continue;
            //向上
            robNum = 0;perNum = 0;int type = 0;int num = 0 ;
            if(cb[i-1][j] == ComType) {type = ComType;}
            else if(cb[i-1][j] == PerType) {type = PerType;}
            for(int k=i-1;k>=qMax(0,i-5);k--){
                if(cb[k][j] == type && type) num++;
                else break;
            }
            w[i][j]+=calPointPrim(num);
            //竖直向下
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i+1][j] == ComType) {type = ComType;}
            else if(cb[i+1][j] == PerType) {type = PerType;}
            for(int k=i+1;k<=qMin(15,i+5);k++)
                if(cb[k][j] == type && type) num++;
                else break;
            w[i][j]+=calPointPrim(num);
            //水平向右
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i][j+1] == ComType) {type = ComType;}
            else if(cb[i][j+1] == PerType) {type = PerType;}
            for(int k=j+1;k<=qMin(15,j+5);k++)
                if(cb[i][k] == type && type) num++;
                else break;
            w[i][j]+=calPointPrim(num);
            //水平向左
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i][j-1] == ComType) {type = ComType;}
            else if(cb[i][j-1] == PerType) {type = PerType;}
            for(int k=j-1;k>=qMax(0,j-5);k--)
                if(cb[i][k] == type && type) num++;
                else break;
            w[i][j]+=calPointPrim(num);
            //左上斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i-1][j-1] == ComType) {type = ComType;}
            else if(cb[i-1][j-1] == PerType) {type = PerType;}
            for(int k=j-1,p=i-1;k>=qMax(0,j-5)&&p>=qMax(0,i-5);p--,k--)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPointPrim(num);
            //右下斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i+1][j+1] == ComType) {type = ComType;}
            else if(cb[i+1][j+1] == PerType) {type = PerType;}
            for(int k=j+1,p=i+1;k<=qMin(15,j+5)&&p<=qMin(15,i+5);p++,k++)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPointPrim(num);
            //右上斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i-1][j+1] == ComType) {type = ComType;}
            else if(cb[i-1][j+1] == PerType) {type = PerType;}
            for(int k=j+1,p=i-1;k<=qMin(15,j+5)&&p>=qMax(0,i-5);p--,k++)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPointPrim(num);
            //左下斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i+1][j-1] == ComType) {type = ComType;}
            else if(cb[i+1][j-1] == PerType) {type = PerType;}
            for(int k=j-1,p=i+1;k>=qMax(0,j-5)&&p<=qMin(15,i+5);p++,k--)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPointPrim(num);

        }
    int temp = 0;
    cP t;
    t.x = rand()%16;
    t.y = rand()%16;
    while(cb[t.x][t.y]!=0){
        t.x = rand()%16;
        t.y = rand()%16;
    }
    for(int i=0;i<16;i++)
        for(int j=0 ; j<16 ; j++) if(w[i][j]>temp){
            temp = w[i][j];
            t.x=i;t.y=j;
        }
    return t;
}

cP Robot::getPointMidd(int tb[16][16]){
    int cb[16][16];
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
            cb[i][j]=tb[i][j];
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++){
            w[i][j]=0;
            if(cb[i][j]==1||cb[i][j]==-1) continue;
            //向上
            robNum = 0;perNum = 0;int type = 0;int num = 0 ;
            if(cb[i-1][j] == ComType) {type = ComType;}
            else if(cb[i-1][j] == PerType) {type = PerType;}
            for(int k=i-1;k>=qMax(0,i-5);k--){
                if(cb[k][j] == type && type) num++;
                else break;
            }
            w[i][j]+=calPoint(num);
            //竖直向下
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i+1][j] == ComType) {type = ComType;}
            else if(cb[i+1][j] == PerType) {type = PerType;}
            for(int k=i+1;k<=qMin(15,i+5);k++)
                if(cb[k][j] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //水平向右
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i][j+1] == ComType) {type = ComType;}
            else if(cb[i][j+1] == PerType) {type = PerType;}
            for(int k=j+1;k<=qMin(15,j+5);k++)
                if(cb[i][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //水平向左
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i][j-1] == ComType) {type = ComType;}
            else if(cb[i][j-1] == PerType) {type = PerType;}
            for(int k=j-1;k>=qMax(0,j-5);k--)
                if(cb[i][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //左上斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i-1][j-1] == ComType) {type = ComType;}
            else if(cb[i-1][j-1] == PerType) {type = PerType;}
            for(int k=j-1,p=i-1;k>=qMax(0,j-5)&&p>=qMax(0,i-5);p--,k--)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //右下斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i+1][j+1] == ComType) {type = ComType;}
            else if(cb[i+1][j+1] == PerType) {type = PerType;}
            for(int k=j+1,p=i+1;k<=qMin(15,j+5)&&p<=qMin(15,i+5);p++,k++)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //右上斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i-1][j+1] == ComType) {type = ComType;}
            else if(cb[i-1][j+1] == PerType) {type = PerType;}
            for(int k=j+1,p=i-1;k<=qMin(15,j+5)&&p>=qMax(0,i-5);p--,k++)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //左下斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i+1][j-1] == ComType) {type = ComType;}
            else if(cb[i+1][j-1] == PerType) {type = PerType;}
            for(int k=j-1,p=i+1;k>=qMax(0,j-5)&&p<=qMin(15,i+5);p++,k--)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);

        }
    int temp = 0;
    cP t;
    t.x = rand()%16;
    t.y = rand()%16;
    while(cb[t.x][t.y]!=0){
        t.x = rand()%16;
        t.y = rand()%16;
    }
    for(int i=0;i<16;i++)
        for(int j=0 ; j<16 ; j++) if(w[i][j]>temp){
            temp = w[i][j];
            t.x=i;t.y=j;
        }
    return t;
}

cP Robot::getPointProf(int tb[16][16]){
    int cb[16][16];
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
            cb[i][j]=tb[i][j];
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++){
            w[i][j]=0;
            if(cb[i][j]==1||cb[i][j]==-1) continue;
            //向上
            robNum = 0;perNum = 0;int type = 0;int num = 0 ;
            if(cb[i-1][j] == ComType) {type = ComType;}
            else if(cb[i-1][j] == PerType) {type = PerType;}
            for(int k=i-1;k>=qMax(0,i-5);k--){
                if(cb[k][j] == type && type) num++;
                else break;
            }
            w[i][j]+=calPoint(num);
            //竖直向下
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i+1][j] == ComType) {type = ComType;}
            else if(cb[i+1][j] == PerType) {type = PerType;}
            for(int k=i+1;k<=qMin(15,i+5);k++)
                if(cb[k][j] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //水平向右
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i][j+1] == ComType) {type = ComType;}
            else if(cb[i][j+1] == PerType) {type = PerType;}
            for(int k=j+1;k<=qMin(15,j+5);k++)
                if(cb[i][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //水平向左
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i][j-1] == ComType) {type = ComType;}
            else if(cb[i][j-1] == PerType) {type = PerType;}
            for(int k=j-1;k>=qMax(0,j-5);k--)
                if(cb[i][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //左上斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i-1][j-1] == ComType) {type = ComType;}
            else if(cb[i-1][j-1] == PerType) {type = PerType;}
            for(int k=j-1,p=i-1;k>=qMax(0,j-5)&&p>=qMax(0,i-5);p--,k--)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //右下斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i+1][j+1] == ComType) {type = ComType;}
            else if(cb[i+1][j+1] == PerType) {type = PerType;}
            for(int k=j+1,p=i+1;k<=qMin(15,j+5)&&p<=qMin(15,i+5);p++,k++)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //右上斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i-1][j+1] == ComType) {type = ComType;}
            else if(cb[i-1][j+1] == PerType) {type = PerType;}
            for(int k=j+1,p=i-1;k<=qMin(15,j+5)&&p>=qMax(0,i-5);p--,k++)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);
            //左下斜
            robNum = 0;perNum = 0;type = 0;num = 0 ;
            if(cb[i+1][j-1] == ComType) {type = ComType;}
            else if(cb[i+1][j-1] == PerType) {type = PerType;}
            for(int k=j-1,p=i+1;k>=qMax(0,j-5)&&p<=qMin(15,i+5);p++,k--)
                if(cb[p][k] == type && type) num++;
                else break;
            w[i][j]+=calPoint(num);

        }
    int temp = 0;
    cP t;
    t.x = rand()%16;
    t.y = rand()%16;
    while(cb[t.x][t.y]!=0){
        t.x = rand()%16;
        t.y = rand()%16;
    }
    for(int i=0;i<16;i++)
        for(int j=0 ; j<16 ; j++) if(w[i][j]>temp){
            temp = w[i][j];
            t.x=i;t.y=j;
        }
    return t;
}
