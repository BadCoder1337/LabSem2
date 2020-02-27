#pragma once
#include <string>

class MyTime {

private:
	int _timestamp;

public:
	MyTime(int timestamp = 0);
	MyTime(const MyTime &src);

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
	friend std::ostream& operator<<(std::ostream& out, const MyTime& b);
};

