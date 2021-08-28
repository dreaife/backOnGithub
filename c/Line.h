#ifndef Point_H_
#define Point_H_
#include "Point.h"
#endif
#ifndef Line_H_
class Line{
	public:
		Line(Point pa,Point pb);
		Line(Line &line);
		double getLength();
	private:
		Point p1,p2;
		double l_L;
};
#endif
