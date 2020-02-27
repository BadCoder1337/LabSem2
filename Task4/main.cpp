#include "StackString.h"
#include "iostream"

using namespace std;

int main() {
	StackString stack;
	cout << stack.size() << endl;
	cout << (stack << string("ABC")).size() << endl;
	cout << stack.push("HJKPO").size() << endl;
	cout << stack.push("DEFG").size() << endl;
	cout << !stack << endl;
	return 0;
}