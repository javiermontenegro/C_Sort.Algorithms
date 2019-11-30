/*********************************************************************
* Filename:  MergeSort_Int.Array.c
* Author:    Javier Montenegro (https://javiermontenegro.github.io/)
* Copyright:
* Details:   This code is the implementation of the mergesort algorithm.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXARRAY 10

void mergesort(int a[], int low, int high);

void mergesort(int a[], int low, int high) {
 int i = 0;
 int length = high - low + 1;
 int pivot  = 0;
 int merge1 = 0;
 int merge2 = 0;
 int working[length];

 if(low == high)
  return;

 pivot  = (low + high) / 2;

 mergesort(a, low, pivot);
 mergesort(a, pivot + 1, high);
 
 for(i = 0; i < length; i++)
  working[i] = a[low + i];

 merge1 = 0;
 merge2 = pivot - low + 1;

 for(i = 0; i < length; i++) {
  if(merge2 <= high - low)
   if(merge1 <= pivot - low)
    if(working[merge1] > working[merge2])
     a[i + low] = working[merge2++];
    else
     a[i + low] = working[merge1++];
   else
    a[i + low] = working[merge2++];
  else
   a[i + low] = working[merge1++];
 }//End for
}//End mergesort

int main(void) 
{
 int array[MAXARRAY];
 int i = 0;

 /* load some random values into the array */
 for(i = 0; i < MAXARRAY; i++)
  array[i] = rand() % 100; 

 /* array before mergesort */
 printf("Initial array\n");
 for(i = 0; i < MAXARRAY; i++)
   printf(" %d", array[i]);

 printf("\n------------\n");
    
 clock_t start = clock();
 mergesort(array, 0, MAXARRAY - 1);
 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("Sorted array\n");
 for(i = 0; i < MAXARRAY; i++)
   printf(" %d", array[i]);

 printf("\nTime spent sorting: %f\n", time_spent);
 return 0;
}//End main
