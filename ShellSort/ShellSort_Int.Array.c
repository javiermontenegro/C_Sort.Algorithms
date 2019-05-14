#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXARRAY 10

void shellsort(int a[], int total, int index);

void shellsort(int a[], int total, int index) {
 int i = 0; 
 int j = 0; 
 int k = 0; 
 int l = 0;

 for(k = 0; k < index; k++) {
  for(i = k; i < total; i += index) {
   l = a[i];
   for(j = (i - index); j >= 0; j -= index) {
    if(a[j] > l)
     a[j + index] = a[j];
    else 
     break;
   }//End for

   a[j + index] = l;
  }//End for
 }//End for

 return;
}//End shellsort

int main(void) 
{
 int array[MAXARRAY] = {0};
 int i = 0;

 /* load some random values into the array */
 for(i = 0; i < MAXARRAY; i++)
  array[i] = rand() % 100; 

 /* print the original array */
 printf("Initial array\n");
 for(i = 0; i < MAXARRAY; i++) {
  printf(" %d ", array[i]); 
 }//End for
 
 printf("\n------------\n");
    
 clock_t start = clock();
 shellsort(array, MAXARRAY, 1);
 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("Sorted array\n");
 for(i = 0; i < MAXARRAY; i++) {
  printf(" %d ", array[i]); 
 }//End for
 printf("\nTime spent sorting: %f\n", time_spent);

 return 0;
}//End main