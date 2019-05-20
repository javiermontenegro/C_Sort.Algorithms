/*********************************************************************
* Filename:  ShakerSort_Int.Array.c
* Author:    Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:   This code is the implementation of the shakersort algorithm.
*********************************************************************/

#include <stdio.h>
#include <time.h>

#define NARRAY 8  /* array size */

void swap(int *a, int *b);
void shakersort(int a[], int n);
void print(int arr[]);

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}//End swap

void shakersort(int a[], int n)
{
    int p, i;
    for (p = 1; p <= n / 2; p++)
    {
        for (i = p - 1; i < n - p; i++)
            if (a[i] > a[i+1]){
                swap(&a[i], &a[i + 1]);
		    }//End if

        for (i = n - p - 1; i >= p; i--)
            if (a[i] < a[i-1]){
                swap(&a[i], &a[i - 1]);
		    }//End if
    }//End for
}//End shakersort

void print(int arr[])
{
    int i;
    for(i = 0; i < NARRAY; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}//End print

int main(void)
{
    int array[NARRAY] = {29,25,-1,49,9,37,21,43};
    
    printf("Initial array\n");
    print(array);
    printf("------------\n");
    
    clock_t start = clock();
    shakersort(array, NARRAY);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array\n");
    
    print(array);
    printf("Time spent sorting: %f\n", time_spent);
    return 0;
}//End main