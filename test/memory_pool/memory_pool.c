/*
 * author: iancain
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <memory.h>
#include "memory_pool.h"
#include "stack.h"

// PRIVATE: declared inside *.c file
typedef struct memory_pool_block_header
{
    uint32_t magic;      // NODE_MAGIC = 0xBAADA555. error checking
    size_t size;
    bool inuse;      // true = currently allocated. Used for error checking

    struct memory_pool_block_header * next;

} memory_pool_block_header_t;

struct memory_pool {
    size_t count;         // total elements
    size_t block_size;   // size of each block
    size_t available;

    struct memory_pool_block_header * pool;
    //void ** shadow; 	// shadow copy of nodes to free on destroy even if caller/user still has them in acquired state
};

// HTODB = header to data block
//     converts header pointer to container data block
#define MEMORY_POOL_HTODB(_header_, _block_size_) ((void *)_header_ - _block_size_)

// DBTOH = data block to header
//     convert data block pointer to point to embedded header information block
#define MEMORY_POOL_DBTOH(_data_block_, _block_size_) ((memory_pool_block_header_t *)(_data_block_ + _block_size_))

#define NODE_MAGIC 0xBAADA555 // magic value to check for data corruption


struct Stack* stack;

memory_pool_t * memory_pool_init(size_t count, size_t block_size)
{
    memory_pool_t *mp = NULL;
    memory_pool_block_header_t * last;
    void * block = NULL;	//data_block
    int n = 0;

    // allocate memory pool struct. give ownership back to caller
    mp = (memory_pool_t*) malloc (sizeof(memory_pool_t));
    if( mp == NULL ) {
        printf("ERROR: memory_pool_init: unable to malloc memory_pool_t. OOM\n");
        return NULL;
    }
    printf("memory_pool_init(mp=%p, count=%zu, block_size=%zu)\n", mp, count, block_size);
    size_t total_size = block_size + sizeof(memory_pool_block_header_t);
    mp->pool = (memory_pool_block_header_t*)malloc(sizeof(total_size));
    if( mp->pool == NULL ) {
        printf("ERROR: pool: unable to malloc memory_pool_t. OOM\n");
        return NULL;
    }
    mp->count = count;
    mp->block_size = block_size;
    mp->available = count;
    last = mp->pool;

    stack = createStack();

    for( n = 0; n < count; ++n ) {
        // allocate data block
    	block = (size_t*)malloc(sizeof(block_size));
    	block = MEMORY_POOL_HTODB(last, mp->block_size);

    	//  total_size = data block size + header size
        size_t total_size = block_size + sizeof(memory_pool_block_header_t);
        last->inuse= true;
        last->magic= NODE_MAGIC;
        last->size =block_size;
        s_push(stack, last);

        // move to end of data block to create header
        if(n < count-1) last->next = (memory_pool_block_header_t*)malloc(sizeof(total_size));
        else last->next = NULL;


        // add to stack (just a simple stack)


        printf("MEMORY_POOL: i=%d, data=%p, header=%p, block_size=%zu, next=%p\n",
               n, block, last, last->size, last->next);


        if(n < count-1) last = last->next;

    }
//    s_print(stack);
    return n == count ? mp : NULL;
}

bool memory_pool_destroy(memory_pool_t *mp)
{
	memory_pool_block_header_t* tmp;
    memory_pool_block_header_t* curr = mp->pool;	//header block starts here

    printf("\nmemory_pool_destroy(mp = %p, count=%zu, block_size=%zu)\n", mp, mp->count, mp->block_size);

    for(int n = 0; n < mp->count; ++n ) {
        // free all data blocks from pool
    	tmp = curr;
    	if(curr->next) curr = curr->next;
    	if(tmp){
    		tmp->inuse = false;
    		tmp->magic = 0;
    		tmp->size = 0;
    		free(tmp);
    	}
    	else break;
    }

    // free memory pool itself
    mp->pool->inuse = false;
    mp->pool->magic = 0;
    mp->pool->size = 0;
    free(mp->pool);

    mp->available = 0;
    mp->count = 0;
    mp->block_size = 0;
    free(mp);

    return true;
}

void * memory_pool_acquire(memory_pool_t * mp)
{
    // pop front/top of the stack and get the header
	memory_pool_block_header_t* header = s_pop(stack);

    // get data block from header
    void * data = MEMORY_POOL_HTODB(header, mp->block_size);

    printf("memory_pool_acquire: mp=%p, data=%p, header=%p\n", mp, data,header);
    return data;  // return to caller
}

bool memory_pool_release(memory_pool_t *mp, void * data)
{
    // move to header inside memory block using MEMORY_POOL_DBTOH(data, mp->block_size);
	memory_pool_block_header_t *header = MEMORY_POOL_DBTOH(data, mp->block_size);

    printf("memory_pool_release: data=%p, header=%p, block_size=%zu, next=%p\n",
           data, header, header->size, header->next);

    // push on back/bottom of the stack
    s_push(stack, header);

    return true;
}

size_t memory_pool_available(memory_pool_t *mp)
{
    if( mp == NULL ) {
        printf("\nERROR: memory_pool_available: memory pool invalid\n");
        return 0;
    }
    return mp->available;
}

void memory_pool_dump(memory_pool_t *mp)
{
    if( mp == NULL ) {
        printf("\nERROR: memory_pool_dump: memory pool invalid\n");
        return;
    }

    printf("\nmemory_pool_dump(mp = %p, count=%zu, available=%zu, block_size=%zu)\n",
            mp, mp->count, mp->available, mp->block_size);

    memory_pool_block_header_t * header = mp->pool;

    for(int n = 0; n < mp->available && header; ++n ) {
        void * data_block = MEMORY_POOL_HTODB(header, mp->block_size);
        printf(" + block: i=%d, data=%p, header=%p, inuse=%s, block_size=%zu, next=%p\n",
               n, data_block, header, header->inuse ? "TRUE":"FALSE", header->size, header->next ? header->next: NULL);

        header = header->next;
    }
}
