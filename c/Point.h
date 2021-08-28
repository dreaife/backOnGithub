#ifndef Point_H_
class Point{
	public:
		Point(double xx=0,double yy=0);
		Point(const Point &p);
		void putinP(double xx=0,double yy=0);
		double getX();
		double getY(); 
	private:
		double x,y;
};
#endif
