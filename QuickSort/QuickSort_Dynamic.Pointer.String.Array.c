#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NARRAY 5 

void sortstrarr(void *array, unsigned n);
static int cmpr(const void *a, const void *b);

static int cmpr(const void *a, const void *b) { 
 return strcmp(*(char **)a, *(char **)b);
}//End cmpr

void sortstrarr(void *array, unsigned n) { 
 qsort(array, n, sizeof(char *), cmpr);
}//End sortstrarr

int main (void) {
 char **strarray = NULL;
 char *array[NARRAY];

 array[0] = "delta";
 array[1] = "gamma";
 array[2] = "epsilon";
 array[3] = "alpha";
 array[4] = "beta";
 
 for(int i = 0; i < NARRAY; ++i)
 {
   strarray = (char **)realloc(strarray, (i + 1) * sizeof(char *));
   strarray[i] = strdup(array[i]);
 }
                  
 printf("Initial array\n");
 for(int i = 0; i < NARRAY; i++)
  printf("%2d: %s", i, strarray[i]);

 printf("\n------------\n");

 clock_t start = clock();
 sortstrarr(strarray, NARRAY);
 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("Sorted array\n");
 for(int i = 0; i < NARRAY; i++)
  printf("%2d: %s", i, strarray[i]);

 /* free mem... */
 for(int i = 0; i < NARRAY; i++)
  free(strarray[i]);

 free(strarray);
 printf("\n\nTime spent sorting: %f\n", time_spent);
 return 0;
}//End main