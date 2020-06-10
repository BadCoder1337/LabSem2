#include <iostream>
#include <conio.h>
#include <windows.h>
#define _USE_MATH_DEFINES 
#include <math.h> 
using namespace std;

/*
7.7	Разработать класс Point для задания координаты точки на плоскости.
Выбирая этот класс в качестве базового, разработать производный класс Circle,
определяющий окружности разного радиуса.
В обоих классах объявить виртуальную функцию Length,
которая возвращает длину соответствующего объекта.
В главной программе объявить массив указателей на несколько точек и 3 окружности.
Определить в этом классе функцию, возвращающую длины медиан треугольника,
вершинами которому служат центры трех заданных окружностей и вывести эти длины в главной программе.
*/

// Класс, описывающий точку:
class CPoint {
protected:
	int x, y; // координаты точки 
public:
	// Конструктор:
	CPoint(int _x = 320, int _y = 240) {
		x = _x; y = _y;
	}
	int GetX() { return x; }
	virtual double Length() //Виртуальная функция возвращающая длину. 
// Для точки - длинна радиус вектора:
	{
		return sqrt((double)(x * x + y * y));
	}
    static void Triangle(CPoint* p1, CPoint* p2, CPoint* p3) {
        CPoint 
            m12((p1->x + p2->x)/2, (p1->y + p2->y)/2),
            m13((p1->x + p3->x)/2, (p1->y + p3->y)/2), 
            m23((p2->x + p3->x)/2, (p2->y + p3->y)/2); 
        cout << "Длины медиан: " << CPoint::Distance(&m12, p3) << ", " << CPoint::Distance(&m13, p2) << ", " << CPoint::Distance(&m23, p1);
    }
    static double Distance(CPoint* p1, CPoint* p2) {
		return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
    }
};

// Класс, описывающий окружность (производный от класса CPoint):
class CCircle : public CPoint {
	int r; // радиус окружности
public:
	CCircle() { r = 2; }
	// Основной конструктор:
	CCircle(int _x, int _y, int _r) :
		CPoint(_x, _y) // Явный вызов конструктора базового класса
	{
		r = _r;
	}
	double Length() { return 2 * M_PI * r; } // длина окружности
};

// Пример использования классов:
int main() {
	//Настройки шрифтов и региональных стандартов: 
	if (SetConsoleCP(1251) == 0)
		//проверка правильности установки кодировки символов для ввода
	{
		cerr << "Failed to set codepage!" << endl;
		/* если не удалось установить кодовую страницу, вывод сообщения об ошибке */
	}
	if (SetConsoleOutputCP(1251) == 0)//тоже самое для вывода
	{
		cerr << "Failed to set OUTPUT page!" << endl;
	}
	CPoint** ptr = new CPoint * [5]; /* помните, что указатель на объект производного класса является одновременно и указателем на объект базового класса */
// создаем несколько объектов:	
	ptr[0] = new CPoint(100, 100);
	ptr[1] = new CCircle(200, 150, 10);
	ptr[2] = new CPoint(100, 200);
	ptr[3] = new CCircle(200, 250, 10);
	ptr[4] = new CCircle(100, 300, 5);
	/* такого типа цикл можно написать только при использовании виртуальных функций: */
	for (int i = 0; i < 5; i++)
		cout << "Длина объекта " << ptr[i]->Length() << endl;
	// одним оператором обрабатываем объекты разных типов
//------------------------------------
    cout << "Треугольник из центров окружностей: \n";
    CPoint::Triangle(ptr[1], ptr[3], ptr[4]);
    cout << "\nТреугольник из точек и окружности: \n";
    CPoint::Triangle(ptr[0], ptr[1], ptr[2]);
	for (int i = 0; i < 5; i++)
		delete ptr[i];
	delete ptr;
	_getch();
	return 0;
}

