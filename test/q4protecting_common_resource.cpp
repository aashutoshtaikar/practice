/*  4) Use your implementation of c++11 lock_guard (NOT std::lock_guard)
     to protect a common resource in your threading example from #3 and #4
*/

#include <iostream>
#include <thread>
#include <mutex>
#include "q1.custom_lock.h"

std::mutex mtx;		//mutex1
std::mutex mtx2;	//different mutex
int sharedVar = 0;


void foo(){
	custom_locks::lock_guard lg_1(mtx2);
	for(int i = 0; i<=9;i++) sharedVar++;
	printf("hello from thread %d, shared var:%d \n", std::this_thread::get_id(), sharedVar);
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void bar(){
	custom_locks::lock_guard lg_1(mtx);
	for(int i = 0; i<=9;i++) sharedVar++;
	printf("hello from thread %d, shared var:%d \n", std::this_thread::get_id(), sharedVar);
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

void baz(){
	custom_locks::lock_guard lg_1(mtx);
	for(int i = 0; i<=9;i++) sharedVar++;
	printf("hello from thread %d, shared var:%d \n", std::this_thread::get_id(), sharedVar);
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main() {

	std::thread thread1(foo);
	std::thread thread2(bar);
	std::thread thread3(baz);

	thread1.join();
	thread2.join();
	thread3.join();

	std::cout << "finished\n";
	return 0;
}

