/*
 * main.cpp
 *
 *  Created on: Feb 3, 2019
 *      Author: Aashutosh Taikar
 */
#include<stdio.h>
#include"memory_pool.h"

int main(){
	size_t count = 5;
	size_t block_size = 2;
	memory_pool_t *mem = memory_pool_init(count, block_size);
	memory_pool_dump(mem);
//	void* data=memory_pool_acquire(mem);
//
//	bool status = memory_pool_release(mem, data);
//	printf("released:%s",status?"true":"false");

	memory_pool_destroy(mem);

	memory_pool_dump(mem);

	printf("finished\n");

	//printf("Memory available %zu blocks",memory_pool_available(mem));

}




