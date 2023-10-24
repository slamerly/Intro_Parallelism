#include <iostream>
#include <thread>

using std::cout;
using std::endl;

void sayHello() {
	cout << "Hello world !" << endl;
}

int main() {
	std::thread t1(sayHello);
	std::thread t2(sayHello);
	t1.join(); // Wait for the thread
	t2.join();

	return 0;
}