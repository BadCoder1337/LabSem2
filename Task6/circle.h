// Класс, описывающий окружность:
#include "point.h"
#define _USE_MATH_DEFINES 
#include <math.h>
class Circle: public Point // Класс Point является базовым для класса Circle
{
	friend istream& operator >> (istream& is, Circle& c)
	{
		cout << "Задайте координаты центра ";
		return is >> c.x >> c.y;
		cout << "Задайте радиус ";
		is >> c.r;
	}
	friend ostream& operator << (ostream& os, const Circle& c)
	{
return os << "Радиус: " << c.r << ", " <<  Point(c.x, c.y); 
// Пример использования функции базового класса

	}
//----------------------------------------------------------------
  protected:
	double r; // радиус окружности
  public:
// конструктор:
	Circle (double _x = 0, double _y = 0, double _r = 0): Point (_x, _y)
	{ r = _r;}
	double Area ()
	{return M_PI* r *r;} // площадь круга

    static void Triangle(Circle& p1, Circle& p2, Circle& p3) {
        Point 
            m12((p1.x + p2.x)/2, (p1.y + p2.y)/2),
            m13((p1.x + p3.x)/2, (p1.y + p3.y)/2), 
            m23((p2.x + p3.x)/2, (p2.y + p3.y)/2); 
        cout << "Длины медиан: " << Point::Distance(m12, p3) << ", " << Point::Distance(m13, p2) << ", " << Point::Distance(m23, p1);
    }
};
