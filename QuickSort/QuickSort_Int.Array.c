/*********************************************************************
* Filename:  QuickSort_Int.Array.c
* Author:    Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:   This code is the implementation of the quicksort algorithm.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXARRAY 10

void quicksort(int arr[], int low, int high);
/* sort everything inbetween `low' <-> `high' */
void quicksort(int arr[], int low, int high) {
 int i = low;
 int j = high;
 int y = 0;
 /* compare value */
 int z = arr[(low + high) / 2];

 /* partition */
 do {
  /* find member above ... */
  while(arr[i] < z) i++;

  /* find element below ... */
  while(arr[j] > z) j--;

  if(i <= j) {
   /* swap two elements */
   y = arr[i];
   arr[i] = arr[j]; 
   arr[j] = y;
   i++; 
   j--;
  }
 } while(i <= j);

 /* recurse */
 if(low < j) 
  quicksort(arr, low, j);

 if(i < high) 
  quicksort(arr, i, high); 
}//End quicksort

int main(void) 
{
 int array[MAXARRAY] = {0};
 
 /* load some random values into the array */
 for(int i = 0; i < MAXARRAY; i++)
  array[i] = rand() % 100; 

 /* print the original array */
 printf("Initial array\n");
 for(int i = 0; i < MAXARRAY; i++) {
  printf(" %d ", array[i]); 
 }//End for
 
 printf("\n------------\n");
    
 clock_t start = clock();
 quicksort(array, 0, (MAXARRAY - 1));
 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
 
 /* print the `quicksorted' array */
 printf("Sorted array\n");
 for(int i = 0; i < MAXARRAY; i++) {
  printf(" %d ", array[i]); 
 }//End for
 
 printf("\n\nTime spent sorting: %f\n", time_spent);
 return 0;
}//End main