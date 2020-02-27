#include <iostream>
#include "MyTime.h"

using namespace std;

int main() {
	MyTime t2;
	auto t = MyTime::todayTime(),
		t1 = MyTime(366),
		t3 = t1 + t2;
	cout << "Now time: " << t << " | " << t.getTimestamp() << endl;
	cout << "t1: " << t1 << " | " << t1.getTimestamp() << endl;
	cout << "t2: " << t2 << " | " << t2.getTimestamp() << endl;
	cout << "t1 + t2: " << t3 << " | " << t3.getTimestamp() << endl;
	while (true) {
		int tmp;
		cin >> tmp;
		auto time = new MyTime(tmp);
		cout << time->toString() << endl;
		
	}
	return 0;
}