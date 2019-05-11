#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NARRAY 8  /* array size */

bool check_sorted(int *a, int n);
void shuffle(int *a, int n);
void sort(int *a, int n);
void print(int arr[]);

bool check_sorted(int *a, int n)
{
  while ( --n >= 1 ) {
    if ( a[n] < a[n-1] ) return false;
  }
  return true;
}//End check_sorted

void shuffle(int *a, int n)
{
  int i, t, r;
  for(i=0; i < n; i++) {
    t = a[i];
    r = rand() % n;
    a[i] = a[r];
    a[r] = t;
  }//End for
}//End shuffle

void sort(int *a, int n)
{
  while ( !check_sorted(a, n) ) shuffle(a, n);
}//End sort

void print(int arr[])
{
    int i;
    for(i = 0; i < NARRAY; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}//End print

int main()
{
    int array[NARRAY] = {29,25,-1,49,9,37,21,43};
    
    printf("Initial array\n");
    print(array);
    printf("------------\n");
    
    clock_t start = clock();
    sort(array, NARRAY);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array\n");
    
    print(array);
    printf("Time spent sorting: %f\n", time_spent);
    return 0;
}//End main
