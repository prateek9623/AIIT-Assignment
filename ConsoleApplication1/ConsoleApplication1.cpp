#include <iostream>
#include <thread>

using namespace std;

void func() {
	cout << "Hello World";
}

int main()
{
	thread t1(func);
	t1.join();
    return 0;
}

