/*********************************************************************
* Filename:  HeapSort_Int.Array.c
* Author:    Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:   This code is the implementation of the heapsort algorithm.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* array of MAXARRAY length ... */
#define MAXARRAY 5

/* preform the heapsort */
void heapsort(int ar[], int len);
/* help heapsort() to bubble down starting at pos[ition] */
void heapbubble(int pos, int ar[], int len);
       
void heapbubble(int pos, int array[], int len) {
 int z = 0;
 int max = 0; 
 int tmp = 0;
 int left = 0; 
 int right = 0; 

 z = pos;
 for(;;) {
  left = 2 * z + 1;  
  right = left + 1;

  if(left >= len)
   return;
  else if(right >= len)
   max = left;
  else if(array[left] > array[right])
   max = left; 
  else
   max = right; 

  if(array[z] > array[max])
   return; 

  tmp = array[z]; 
  array[z] = array[max];  
  array[max] = tmp;
  z = max;
 }
}//End heapbubble

void heapsort(int array[], int len) {
 int i = 0;
 int tmp = 0;

 for(i = len / 2; i >= 0; --i)
  heapbubble(i, array, len); 

 for(i = len - 1; i > 0; i--) {
  tmp = array[0];  
  array[0] = array[i]; 
  array[i] = tmp;
  heapbubble(0, array, i);
 }//End for
}//End heapsort

int main(void) {
 int array[MAXARRAY];
 int i = 0;

 /* load some random values into the array */
 for(i = 0; i < MAXARRAY; i++)
  array[i] = rand() % 100; 

 /* print the original array */
 printf("Initial array\n");
 for(i = 0; i < MAXARRAY; i++) {
  printf(" %d ", array[i]); 
 }
 printf("\n------------\n");

 clock_t start = clock();
 heapsort(array, MAXARRAY);
 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("Sorted array\n");
 for(i = 0; i < MAXARRAY; i++) {
  printf(" %d ", array[i]); 
 }
 printf("\nTime spent sorting: %f\n", time_spent);

 return 0;
}//End mains