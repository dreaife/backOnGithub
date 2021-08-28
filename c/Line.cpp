#include<iostream>
#include"Point.h"
#include"Line.h"
#include<math.h>

using namespace std;

Line::Line(Point pa,Point pb):p1(pa),p2(pb){l_L=sqrt((pa.x-pb.x)*(pa.x-pb.x)+(pa.y-pb.y)*(pa.y-pb.y));}
Line::Line(Line &line){
	p1=line.p1;
	p2=line.p2;
	l_L=line.l_L;
}
double Line::getLength(){
	return l_L;
}
