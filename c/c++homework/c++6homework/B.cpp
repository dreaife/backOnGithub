#include<iostream>
#include<windows.h>
#include<iomanip>
using namespace std;
const double pi=3.1416;
class Geometry{
    public:
        virtual double getPerim()=0;
        virtual double getArea()=0;
        virtual void display()=0;
};
class rectangle:public Geometry{
    public:
        rectangle(double x=0,double y=0):x(x),y(y){}
        double getPerim(){
            return 2*(x+y);
        }
        double getArea(){
            return x*y;
        }
        void display(){
            cout<<"周长:"<<fixed<<setprecision(2)<<getPerim()<<endl;
            cout<<"面积:"<<fixed<<setprecision(2)<<getArea()<<endl;
        }
    private:
        double x,y;
};
class Circle:public Geometry{
    public:
        Circle(double rr=0):r(rr){}
        double getPerim(){
            return 2*r*pi;
        }
        double getArea(){
            return pi*r*r;
        }
        void display(){
            cout<<"周长:"<<fixed<<setprecision(2)<<getPerim()<<endl;
            cout<<"面积:"<<getArea()<<endl;
        }
    private:
        double r;
};
void fun(Geometry* ptr){
    ptr->display();
}
int main(){
    rectangle x(2,3);
    cout<<"Rectangle:"<<endl;
    fun(&x);
    cout<<endl;
    Circle y1(5);
    cout<<"Circle:"<<endl;
    fun(&y1);
    system("pause");
    return 0;
}