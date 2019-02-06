/*
 * stack.h
 *
 *  Created on: Feb 5, 2019
 *      Author: Aashutosh Taikar
 */


#include<stdio.h>
#include"memory_pool.h"

typedef struct Stack Stack_t;

Stack_t* createStack(int size);

void s_push(Stack_t* stack, block_header_t* header);
void s_print(Stack_t* stack);
block_header_t* s_pop(Stack_t* stack);



