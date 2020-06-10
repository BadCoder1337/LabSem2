#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "circle.h"
using namespace std;

/* 
Разработать класс Point для задания координаты точки на плоскости.
Выбирая этот класс в качестве базового, разработать производный класс Circle,
определяющий окружности разного радиуса.
Определить в этом классе функцию,
возвращающую длины медиан треугольника,
вершинами которому служат центры трех заданных окружностей.
*/


int main()
{
	//Настройки шрифтов и региональных стандартов: 
	if(SetConsoleCP(1251)==0)
	//проверка правильности установки кодировки символов для ввода
	{
		cerr<<"Failed to set codepage!"<<endl;
	/* если не удалось установить кодовую страницу, вывод сообщения об ошибке */
	}
	if(SetConsoleOutputCP(1251)==0)//тоже самое для вывода
	{
		cerr<<"Failed to set OUTPUT page!"<<endl;
	}
	Point pt(200, 200);
	cout<<pt;
	cin>>pt;
	cout<<pt;
	Circle cr(300, 200, 20),
        cr1(200, 300, 10),
        cr2(150, 50, 30);
	cout<<cr;
	cin>>cr;
	cout<< cr <<"площадь окружности"<<cr.Area()<<endl;
	cout<< cr1 <<"площадь окружности"<<cr1.Area()<<endl;
	cout<< cr2 <<"площадь окружности"<<cr2.Area()<<endl;
	Circle::Triangle(cr, cr1, cr2);
	_getch();
	return 0;
}
