#include "MyString.h"
#include "iostream"

using namespace std;

int main() {
	MyString str;
	int i;
	while (true) {
		cout << "String: ";
		//str = string("abc"); 
		cin >> str;
		cout << "Move: ";
		//i = 1;
		cin >> i;
		cout << "Result: " << (str >> i) << endl;
	}
	return 0;
}