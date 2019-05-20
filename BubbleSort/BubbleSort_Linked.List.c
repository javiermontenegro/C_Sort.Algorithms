/*********************************************************************
* Filename:  BubbleSort_Linked.List.c
* Author:    Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:   This code is the implementation of the bubblesort algorithm.
*********************************************************************/

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
/* preform a bubble sort on the linked list */
void llist_bubble_sort(void);
/* print the entire linked list */
void llist_print(void);

/* adds a node at the end of a linked list */
void llist_add(struct lnode **q, int num) {
 struct lnode *tmp; 
 
 tmp = *q;

 /* if the list is empty, create first node */
 if(*q == NULL) {
  *q = malloc(sizeof(struct lnode));
   tmp = *q;
 } else {
  /* go to last node */
  while(tmp->next != NULL)
   tmp = tmp->next;

   /* add node at the end */
   tmp->next = malloc(sizeof(struct lnode));
   tmp = tmp->next;
 }

 /* assign data to the last node */
 tmp->data = num;
 tmp->next = NULL;
}//End llist_add

/* print the entire linked list */
void llist_print(void) {
 visit = head;

 while(visit != NULL) {
  printf("%d ", visit->data);
  visit = visit->next;
 }
 printf("\n");
}//End llist_print

/* preform a bubble sort on the linked list */
void llist_bubble_sort(void) {
 struct lnode *a = NULL;
 struct lnode *b = NULL; 
 struct lnode *c = NULL;
 struct lnode *e = NULL; 
 struct lnode *tmp = NULL; 

 /* 
 // the `c' node precedes the `a' and `e' node 
 // pointing up the node to which the comparisons
 // are being made. 
 */
 while(e != head->next) {
 c = a = head;
 b = a->next;
  while(a != e) {
   if(a->data > b->data) {
    if(a == head) {
     tmp = b -> next;
     b->next = a;
     a->next = tmp;
     head = b;
     c = b;
    } else {
     tmp = b->next;
     b->next = a;
     a->next = tmp;
     c->next = b;
     c = b;
    }
   } else {
    c = a;
    a = a->next;
   }
   b = a->next;
   if(b == e)
    e = a;
  }//End while
 }//End while

}//End llist_bubble_sort

int main(void)   
{
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
    llist_bubble_sort();
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array\n");
    llist_print();

    return 0;
}//End main

