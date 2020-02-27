#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>

#include "MyTime.h"

/*
1.7.	Разработать класс Time для работы с временными параметрами.
Определить в этом классе функции-члены, которые обеспечивают ввод/вывод элементов класса,
а также доступ к закрытым членам класса.
Кроме этого определить функцию-член TodayTime(),
которая возвращает системное время объекту класса Time.

2.7.	Разработать класс Time для работы с временными параметрами.
Класс должен содержать основной конструктор, конструктор по умолчанию и конструктор копирования.
Определить в этом классе функции-члены, которые обеспечивают ввод/вывод элементов класса,
а также доступ к закрытым членам класса.
Кроме этого определить функцию-член TodayTime(),
которая возвращает системное время объекту класса Time.
*/

MyTime::MyTime(int tmp) {
	_timestamp = tmp;
}

MyTime::MyTime(const MyTime & src) {
	_timestamp = src._timestamp;
}

std::string MyTime::toString() {
	std::ostringstream str;
	str
		<< std::setw(2)
		<< std::setfill('0')
		<< getHours()
		<< ':'
		<< std::setw(2)
		<< std::setfill('0')
		<< getMinutes()
		<< ':'
		<< std::setw(2)
		<< std::setfill('0')
		<< getSecounds();
	return str.str();
}

MyTime MyTime::operator+(const MyTime& b) {
	return MyTime(this->_timestamp + b._timestamp);
}

MyTime MyTime::operator-(const MyTime& b) {
	return MyTime(this->_timestamp - b._timestamp);
}

std::ostream & operator<<(std::ostream& out, const MyTime& b) {
	out << MyTime(b._timestamp).toString();
	return out;
}

MyTime& MyTime::setHours(int hour) {
	return *this;
}

MyTime& MyTime::setMinutes(int minute) {
	return *this;
}

MyTime& MyTime::setSecounds(int secound) {
	return *this;
}

MyTime& MyTime::setTimestamp(int timestamp) {
	return *this;
}

int MyTime::getHours() {
	return _timestamp / 3600;
}

int MyTime::getMinutes() {
	return _timestamp % 3600 / 60;
}

int MyTime::getSecounds() {
	return _timestamp % 60;
}

int MyTime::getTimestamp() {
	return _timestamp;
}

MyTime MyTime::todayTime() {
	time_t now = time(0);
	tm *ltm = localtime(&now);

	return MyTime(ltm->tm_hour * 3600 + ltm->tm_min * 60 + ltm->tm_sec);
}
