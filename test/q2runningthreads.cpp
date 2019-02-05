/*
2) Implement c++11 threading example
      2-3 threads running
*/

#include<iostream>
#include<thread>

void foo(){
	printf("hello from thread %d\n", std::this_thread::get_id());
}

int main() {

	std::thread thread1(foo);
	std::thread thread2(foo);
	std::thread thread3(foo);

	thread1.join();
	thread2.join();
	thread3.join();

	std::cout << "finished\n";
	return 0;
}
