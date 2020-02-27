#pragma once

#include "string"

class MyString: public std::string {

public:
	MyString() : std::string() {};
	MyString(std::string str) : std::string(str) {};

	const MyString operator>>(int b);
};

