#pragma once

#include "string"

using namespace std;

struct Node {
	string data;
	Node *next;
};

class StackString {
private:
	friend Node;
	Node *_begin;
	Node *_end;
	void init();
public:
	StackString();
	StackString& push(string str);
	StackString& insert(string str, int pos);
	string pop();
	string top();
	int size();

	string operator!();
	StackString& operator<<(string str);
};
