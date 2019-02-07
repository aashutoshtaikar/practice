/*1) Reimplement c++11 lock_guard (NOT use std::lock_guard). Use namespace
      to allow you to call your class impl "lock_guard" and not conflict with
      std::lock_guard
*/

#include<iostream>
#include<thread>
#include<mutex>
#include<queue>

namespace custom_locks {
/*provides a way to serialize threads in situations where multiple different non shared mutexes need to be synchronized
 * Drawbacks: 1. Serialization of R/W task from a shared resource
 * 	      2. Race Condition: Not addressed*/
class lock_guard {
	std::queue<std::mutex*> m_que_M;

public:
	//no implicit conversions allowed
	explicit lock_guard(std::mutex& _m){
		_m.lock();
		m_que_M.push(std::addressof(_m));
	}


	~lock_guard() {
		while(!m_que_M.empty()){
			std::mutex* tmp_m = m_que_M.back();
			m_que_M.pop();
			tmp_m->unlock();
		}
	}

	//deleting unused constructors to avoid copy/move/assignment
	lock_guard(const lock_guard&) = delete;
	lock_guard& operator=(const lock_guard&) = delete;
	lock_guard(const lock_guard&&) = delete;
	lock_guard& operator=(const lock_guard&&) = delete;
};

}




