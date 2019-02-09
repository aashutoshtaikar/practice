/*  4) Use your implementation of c++11 lock_guard (NOT std::lock_guard)
     to protect a common resource in your threading example from #3 and #4
*/

#include <iostream>
#include <thread>
#include <mutex>
#include "q1.custom_lock.h"


std::mutex mtx;		//mutex1
std::mutex mtx2;	//different mutex

//sharedVar as a common resource
int sharedVar = 0;


void foo(){
	printf("doing some work from thread %d, shared var:%d \n", std::this_thread::get_id(), sharedVar);
	std::this_thread::sleep_for(std::chrono::seconds(5));	//set speed here to check race conditions

	custom_locks::lock_guard lg_1(mtx2);
	for(int i = 0; i<=9;i++) sharedVar++;
	printf("operating over shared resource from thread %d, shared var:%d \n", std::this_thread::get_id(), sharedVar);
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

