/*********************************************************************
* Filename:  QuickSort_Array.Of.Pointer.To.Structures.c
* Author:    Javier Montenegro (https://javiermontenegro.github.io/)
* Copyright:
* Details:   This code is the implementation of the quicksort algorithm.
*********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NARRAY 5 

struct node {
 char *str;
};

/* compare function for qsort */
static int cmpr(const void *a, const void *b);

/* compare function for qsort */
static int cmpr(const void *a, const void *b) { 
 struct node * const *j = a;
 struct node * const *k = b;

 return strcmp((*j)->str, (*k)->str);
}

int main(void) {
 struct node **strarray = NULL;
 int i = 0, count = 0;
 char *array[NARRAY];

  array[0] = "delta";
  array[1] = "gamma";
  array[2] = "epsilon";
  array[3] = "alpha";
  array[4] = "beta";

  for(int i = 0; i < NARRAY; ++i)
   {
   /* add j element to the array */
   strarray = (struct node **)realloc(strarray, (i + 1) * sizeof(struct node *));

   /* allocate memory for j `struct node` */
   strarray[i] = (struct node *)malloc(sizeof(struct node));

   /* copy the data into the new element (structure) */
   strarray[i]->str = strdup(array[i]);
  }//End for

 /* before sorting ... */
 printf("Initial array\n");
 for(int i = 0; i < NARRAY; i++) {
  printf("[%d]->str: %s", i, strarray[i]->str);
 }

 printf("\n------------\n");
    
 clock_t start = clock();
 /* qsort array of structures */
 qsort(strarray, NARRAY, sizeof(*strarray), cmpr);

 /* after sorting ... */
 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("Sorted array\n");
 for(i = 0; i < NARRAY; i++) {
  printf("[%d]->str: %s", i, strarray[i]->str);
 }//End for

 /* free all strarray elements */
 for(i = 0; i < NARRAY; i++) {
  free(strarray[i]->str);
  free(strarray[i]);
  i++;
 }//End for
 free(strarray);
 
 printf("\n\nTime spent sorting: %f\n", time_spent); 
 return 0;
}//End main