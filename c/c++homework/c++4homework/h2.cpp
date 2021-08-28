#include<iostream>
#include<windows.h>
#include<cmath>
#include<vector>
using namespace std;
class Point {
    public:
        Point(double xx=0,double yy=0):x(xx),y(yy){dis=sqrt(xx*xx+yy*yy);};
        friend void paixu(vector<Point> P);
        void printPoint(){
            cout<<'('<<x<<','<<y<<')'<<"  "<<dis<<endl;
        }
    private:
        double x,y;
        double dis;
};
void paixu(vector<Point> P){
    Point temp;
    for(int i=0;i<10;i++){
        int index=i;
        for(int j=i+1;j<10;j++)
            if(P[j].dis<P[i].dis) index=j;
        if(P[index].dis<P[i].dis){
            temp=P[i];
            P[i]=P[index];
            P[index]=temp;
        } 
    }
}
int main(){
    vector<Point> p(10);
    p[0]={-1,-3},p[1]={-2,-4},p[2]={1,3},p[3]={-2,5},p[4]={3,-4},p[5]={5,3},p[6]={1,7},p[7]={6,3},p[8]={4,4},p[9]={7,8};
    paixu(p);
    for(int i=0;i<10;i++) p[i].printPoint();
    system("pause");
    return 0;
}