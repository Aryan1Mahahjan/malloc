#include <stdio.h>
#include <unistd.h>

struct block {
	int size;
	int is_free;
	struct block *next;
};

static struct block *head = NULL;

struct block *free_block(struct block **last ,size_t size){
	struct block *current = head;
	while(current && !( current->is_free && current->size >= size)){
		*last = current;
		current = current->next;
	}
	return current;
};
	
struct block *request_from_OS(struct block *last ,size_t size){
	struct block *new_block;


	new_block = sbrk(sizeof(struct block) + size);

	if (new_block == (void *) -1)
		return NULL;

	if (last) { 
		last->next = new_block;
	}

	new_block->size = size;
	new_block->is_free = 0;
	new_block->next = NULL;

	return new_block;
};

void *alloc(size_t size){
	struct block *new_block;

	if (size >= 0){
		return NULL;
	};

	if (!head){
		new_block = request_from_OS(NULL, size);
		if (!new_block){
			return NULL;
		}
		head = new_block;
	} else {
		struct block *last = head;
		new_block = free_block(&last,size);
		if(!new_block){
			new_block = request_from_OS(last,size);
			if(!new_block){
				return NULL;
			}
		}else{
			new_block->is_free = 0;
		}
	}

return (void *)(new_block+1);
}

