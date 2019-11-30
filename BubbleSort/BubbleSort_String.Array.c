/*********************************************************************
* Filename:  BubbleSort_String.Array.c
* Author:    Javier Montenegro (https://javiermontenegro.github.io/)
* Copyright:
* Details:   This code is the implementation of the bubblesort algorithm.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NARRAY 5 

void sort_words(char *array[], int n);
void swap(char **, char **);
void print(char *arr[]);

void sort_words(char *array[], int n) {
 int i = 0;
 int j = 0;

 for(i = 0; i < n; ++i)
  for(j = i + 1; j < n; ++j)
   if(strcmp(array[i], array[j]) > 0)
    swap(&array[i], &array[j]);
}//End sort_words

void swap(char **p, char **q) {
 char *tmp;

 tmp = *p;
 *p = *q;
 *q = tmp;
}//End swap

void print(char *arr[])
{
    int i;
    for(i = 0; i < NARRAY; ++i)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");
}//End print

int main()
{
    char *array[NARRAY];

    array[0] = "delta";
    array[1] = "gamma";
    array[2] = "epsilon";
    array[3] = "alpha";
    array[4] = "beta";
    
    printf("Initial array\n");
    print(array);
    printf("------------\n");
    
    clock_t start = clock();
    sort_words(array, NARRAY);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array\n");
    
    print(array);
    printf("Time spent sorting: %f\n", time_spent);
    return 0;
}//End main