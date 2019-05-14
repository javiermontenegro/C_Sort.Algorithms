#include <stdio.h>
#include <time.h>

#define NARRAY 10  

void selection_sort(int a[], int size);
void print(int arr[]);

void selection_sort(int a[], int size) {
 int i = 0;
 int j = 0;
 int large = 0;
 int index = 0;

 for(i = size - 1; i > 0; i--) {
  large = a[0];
  index = 0;
  for(j = 1; j <= i; j++)
   if(a[j] > large) {
    large = a[j];
    index = j;
   }//End if

   a[index] = a[i];
   a[i] = large;
 }//End for
 
}//End selection_sort

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
  selection_sort(array, NARRAY);
  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted array\n");
    
  print(array);
  printf("Time spent sorting: %f\n", time_spent);
  return 0;
}//End main