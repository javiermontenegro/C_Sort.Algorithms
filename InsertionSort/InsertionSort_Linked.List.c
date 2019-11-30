/*********************************************************************
* Filename:  InsertionSort_Linked.List.c
* Author:    Javier Montenegro (https://javiermontenegro.github.io/)
* Copyright:
* Details:   This code is the implementation of the insertionsort algorithm.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NARRAY 5 

struct lnode {
 char *str;
 struct lnode *next;
};

struct lnode *insert(char *data, struct lnode *list);
void free_list(struct lnode *list);
void print_list(struct lnode *list);

struct lnode *insert(char *data, struct lnode *list) {
 struct lnode *p;
 struct lnode *q;

 /* create a new node */
 p = (struct lnode *)malloc(sizeof(struct lnode));
 /* save data into new node */
 p->str = strdup(data);

 /* first, we handle the case where `data' should be the first element */
 if(list == NULL || strcmp(list->str, data) > 0) {
  /* apperently this !IS! the first element */
  /* now data should [be|becomes] the first element */
  p->next = list;
  return p;
 } else {  
  /* search the linked list for the right location */
  q = list;
  while(q->next != NULL && strcmp(q->next->str, data) < 0) {
   q = q->next;
  }
  p->next = q->next;
  q->next = p;
  return list;
 }
}
    
void free_list(struct lnode *list) {
 struct lnode *p;

 while(list != NULL) {
  p = list->next;
  free(list);
  list = p;
 }//End while
}//End free_list
  
void print_list(struct lnode *list) {
 struct lnode *p;
  
 for(p = list; p != NULL; p = p->next)
  printf("%s ", p->str);
}//End print_list

int main(void) 
{
  struct lnode *list;
  list = NULL;
  char *array[NARRAY];

  array[0] = "delta";
  array[1] = "gamma";
  array[2] = "epsilon";
  array[3] = "alpha";
  array[4] = "beta";

  printf("Initial array\n");
  for(int i = 0; i < NARRAY; ++i)
  {
    printf("%s ", array[i]);
  }
  printf("\n------------\n");
    
  clock_t start = clock();
  for(int i = 0; i < NARRAY; ++i)
  {
    list = insert(array[i], list);      
  }//End for

  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted array\n");
  print_list(list);
  free_list(list);

  printf("\n\nTime spent sorting: %f\n", time_spent);
  return 0;
}//End main