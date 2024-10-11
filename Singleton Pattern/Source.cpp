#include "Singleton.h"
#include "thread"
#include <iostream>

using namespace std;

void threadFoo() {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton *obj = Singleton::getInstance("Foo");
	cout << obj->getValue() << endl;
}

void threadBar() {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton* obj = Singleton::getInstance("Bar");
	cout << obj->getValue() << endl;
}
 
int main() {
	cout << "value should always be same" << endl;
	std::thread t1(threadFoo);
	std::thread t2(threadBar);
	t1.join();
	t2.join();

	return 0;
}