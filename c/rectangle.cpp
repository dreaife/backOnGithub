#include<iostream>
using namespace std;
class Point{
	public:
		double x,y;
		Point (double xx,double yy):x(xx),y(yy){}
};
class Rectangle{
	public:
		Rectangle(double xx1,double yy1,double xx2,double yy2): p1(xx1,yy1),p2(xx2,yy2) {}
		double SR(){
			double a=0,b=0;
			if(p1.x-p2.x<=0) a=-(p1.x-p2.x);
			else a=p1.x-p2.x;
			if(p1.y-p2.y<=0) b=-(p1.y-p2.y);
			else b=p1.y-p2.y;
			cout <<"矩形面积为：";
			return a*b;
		}
	private:
		Point p1,p2;
};
int main(){
	Rectangle A(1,3,5,7);
	cout<<A.SR()<<endl;
	return 0;
}
