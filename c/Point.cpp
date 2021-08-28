#include<iostream>
#include"Point.h"

using namespace std;

Point::Point(double xx,double yy){
	x=xx;y=yy;
}
Point::Point(const Point &p){
	x=p.x;
	y=p.y;
}
void Point::putinP(double xx,double yy){
	x=xx;y=yy;
}
double Point::getX(){
	return x;
}
double Point::getY(){
	return y;
}
