#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


// Custom Allocator
void *alloc(size_t size){
	void *p = sbrk(size);

	if (p == (void *) -1)
		return NULL;

	return p;
}


int main(){
	void *ptr;
	void *top = sbrk(0);
	ptr = malloc(20480);			// 20480 bytes = 20KB
	void *top2 = sbrk(0);
	alloc(20480);
	void *top3 = sbrk(0);
	printf("Malloc: The top of heap went from %p to %p \n", top, top2);
	printf("Alloc: The top of heap went from %p to %p \n",top2,top3);
	long diff;
	diff = top2 - top;
	long diff2 = top3 - top2;
	printf("Malloc Diff: %td\nAlloc Diff: %td\n",diff,diff2);
}
