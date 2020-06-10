// файл point.h:
#include <iostream>
using namespace std;

// Класс, описывающий точку:
class Point
{
protected:
	double x, y;
private:
//---------------------------------------------------------
	friend istream& operator >> (istream& is, Point& p)
	{
		cout << "Задайте координаты точки ";
		return is >> p.x >> p.y;
	}
	friend ostream& operator << (ostream& os, const Point& p)
	{
		return os << "коордиаты точки: [" <<
		p.x << ", " << p.y << "]\n";
	}
//----------------------------------------------------------------
 public:
	Point(double _x=0, double _y=0)
	{ x = _x; y =_y;}
    static double Distance(Point& p1, Point& p2) {
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
};
