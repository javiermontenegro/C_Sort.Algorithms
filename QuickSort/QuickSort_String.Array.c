#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NARRAY 5 

void sortstrarr(void *array, unsigned n);
void print(char *arr[]);
static int cmpr(const void *a, const void *b);

static int cmpr(const void *a, const void *b) { 
 return strcmp(*(char **)a, *(char **)b);
}//End cmpr

void sortstrarr(void *array, unsigned n) { 
 qsort(array, n, sizeof(char *), cmpr);
}//End sortstrarr

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
    sortstrarr(array, NARRAY);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array\n");
    
    print(array);
    printf("\nTime spent sorting: %f\n", time_spent);
    return 0;
}//End main