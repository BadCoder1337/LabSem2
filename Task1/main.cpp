#include <iostream>
#include "MyTime.h"

using namespace std;

int main() {
	//cout << "Now time: " << MyTime::todayTime().toString();
	MyTime t1 = MyTime(360);
	cout << "t1: " << t1.toString() << " | " << t1.getTimestamp() << endl;
	MyTime t2 = MyTime(181);
	cout << "t2: " << t2.toString() << " | " << t2.getTimestamp() << endl;
	MyTime t3 = t1 + t2;
	cout << "t1 + t2: " << t3.toString() << " | " << t3.getTimestamp() << endl;
	while (true) {
		int tmp;
		cin >> tmp;
		auto time = new MyTime(tmp);
		cout << time->toString() << endl;
		
	}
	return 0;
}