#include<iostream>
#include<algorithm>
using namespace std;
class Point{
	public:
		Point(){
			x = 0;y = 0;
		}
		Point(double a,double b):x(a),y(b){}
		void move(double a,double b){
			x = a;y = b;
		}
		~Point(){
			x = 0;y = 0;
		}
		double x,y;
};
class Rectangle:public Point{
	public:
		Rectangle():Point(),w(0),h(0){}
		Rectangle(double a,double b,double ww,double hh):Point(a,b),w(ww),h(hh){}
		void getMess(){
			cout<<"Left-Down Point:("<<x<<','<<y<<")\n";
			cout<<"Weight:"<<w<<"\tHeight:"<<h<<endl;
			cout<<"Area:"<<w*h<<endl;
		}
		~Rectangle(){
			w = 0;h = 0;
		}
		double w,h;
};
int main(){
	Rectangle rec(1,1,5,8);
	rec.getMess();
	return 0;
}