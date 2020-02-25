#pragma once
#include <string>

class MyTime {

	int _timestamp;

public:
	MyTime() {};
	MyTime(int timestamp);

	MyTime& setHours(int hour);
	MyTime& setMinutes(int minute);
	MyTime& setSecounds(int secound);
	MyTime& setTimestamp(int timestamp);

	int getHours();
	int getMinutes();
	int getSecounds();
	int getTimestamp();

	static MyTime todayTime();

	std::string toString();

	MyTime operator+(const MyTime& b);
	MyTime operator-(const MyTime& b);

};

