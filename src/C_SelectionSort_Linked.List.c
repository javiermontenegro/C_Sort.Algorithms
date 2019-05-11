#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

struct lnode {
 int data;
 struct lnode *next;
} *head, *visit;

/* add a new entry to the linked list */
void llist_add(struct lnode **q, int num);
/* preform a selection sort on the linked list */
void llist_selection_sort(void);
/* print the entire linked list */
void llist_print(void);

/* adds a node at the end of a linked list */
void llist_add(struct lnode **q, int num) {
 struct lnode *temp; 
 
 temp = *q;

 /* if the list is empty, create first node */
 if(*q == NULL) {
  *q = malloc(sizeof(struct lnode));
   temp = *q;
 } else {
  /* go to last node */
  while(temp->next != NULL)
   temp = temp->next;

   /* add node at the end */
   temp->next = malloc(sizeof(struct lnode));
   temp = temp->next;
 }//End if

 /* assign data to the last node */
 temp->data = num;
 temp->next = NULL;
}//End llist_add

/* print the entire linked list */
void llist_print(void) {
 visit = head;

 /* traverse the entire linked list */
 while(visit != NULL) {
  printf("%d ", visit->data);
  visit = visit->next;
 }
 printf("\n");
}//End llist_print

void llist_selection_sort(void) {
 struct lnode *a = NULL;
 struct lnode *b = NULL;
 struct lnode *c = NULL;
 struct lnode *d = NULL;
 struct lnode *tmp = NULL;

 a = c = head;
 while(a->next != NULL) {
  d = b = a->next;
  while(b != NULL) {
   if(a->data > b->data) {
    /* neighboring linked list node */
    if(a->next == b) { 
     if(a == head) {
      a->next = b->next;
      b->next = a;
      tmp = a;
      a = b;
      b = tmp;
      head = a;
      c = a;
      d = b;
      b = b->next;
     } else {
      a->next = b->next;
      b->next = a;
      c->next = b;
      tmp = a;
      a = b;
      b = tmp;
      d = b;
      b = b->next;
     }
    } else {
     if(a == head) {
      tmp = b->next;
      b->next = a->next;
      a->next = tmp;
      d->next = a;
      tmp = a;
      a = b;
      b = tmp;
      d = b;
      b = b->next;
      head = a;
    } else {
     tmp = b->next;
     b->next = a->next;
     a->next = tmp;
     c->next = b;
     d->next = a;
     tmp = a;
     a = b;
     b = tmp;
     d = b;
     b = b->next;
    }
   }
  } else {
   d = b;
   b = b->next;
  }
 }
  c = a;
  a = a->next;
 }
}//End llist_selection_sort

int main(void) {
 /* linked list */
 struct lnode *newnode = NULL;
 int i = 0; /* a general counter */

 /* load some random values into the linked list */
 for(i = 0; i < MAX; i++) {
  llist_add(&newnode, (rand() % 100));
 }//End for

 head = newnode;
 printf("Initial array\n");
 llist_print();
 printf("------------\n");
    
 clock_t start = clock();
 llist_selection_sort();
 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("Sorted array\n");
 llist_print();
 
 printf("Time spent sorting: %f\n", time_spent);
 return 0;
}//End main