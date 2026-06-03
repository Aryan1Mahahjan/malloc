#include <stdio.h>
#include <stdlib.h>

int main() {

	
   int *ptr;
   int n = 6;
   char word[6] = "Hello";

   ptr = (int*)malloc(n * sizeof(int));
   if (ptr == NULL) {
      printf("Memory not allocated.\n");
      exit(0);
   } else {
      printf("Memory successfully allocated using malloc.\n");

      for (int i = 0; i < 6;i++){
	      *(ptr + i) = word[i];
      }

      free(ptr);
      printf("Malloc memory successfully freed.\n");
   }
   return 0;
}
