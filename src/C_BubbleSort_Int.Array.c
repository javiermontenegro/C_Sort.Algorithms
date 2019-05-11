#include <stdio.h>
#include <time.h>

#define NARRAY 8  

void bubble_sort(int a[], int size);
void print(int arr[]);

void bubble_sort(int a[], int size) {
 int switched = 1;
 int hold = 0;
 int i = 0;
 int j = 0;

 size -= 1;

 for(i = 0; i < size && switched; i++) {
  switched = 0;
  for(j = 0; j < size - i; j++)
   if(a[j] > a[j+1]) {
    switched = 1;
    hold = a[j];
    a[j] = a[j + 1];
    a[j + 1] = hold;
   }//End if
 }//End for

}//End bubble_sort

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
    bubble_sort(array, NARRAY);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array\n");
    
    print(array);
    printf("Time spent sorting: %f\n", time_spent);
    return 0;
}//End main