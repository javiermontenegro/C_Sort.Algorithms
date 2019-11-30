/*********************************************************************
* Filename:  InsertionSort_2D.Linked.List.c
* Author:    Javier Montenegro (https://javiermontenegro.github.io/)
* Copyright:
* Details:   This code is the implementation of the insertionsort algorithm.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
 int number;
 struct node *next;
};

struct node *head = NULL;

/* insert a node directly at the right place in the linked list */
void insert_node(int value);

void insert_node(int value) {
 struct node *temp = NULL;
 struct node *j = NULL;
 struct node *k = NULL;

 if(head == NULL) {
  head = (struct node *)malloc(sizeof(struct node *));
  head->next = NULL;
 }//End if

 j = head;
 k = head->next;
 
 temp = (struct node *)malloc(sizeof(struct node *));
 temp->number = value;
 
 while(k != NULL && temp->number < k->number) {
  j = j->next;
  k = k->next;
 }//End while

 j->next = temp;
 temp->next = k;
}//End insert_node

int main(void) 
{
 struct node *current = NULL;
 struct node *next = NULL;
 int test[] = {8, 3, 2, 6, 1, 5, 4, 7, 9, 0};
 int i = 0;

 printf("Sorted List: \n");
 printf("------------\n");
    
 clock_t start = clock();

 /* insert some numbers into the linked list */
 for(i = 0; i < 10; i++)
  insert_node(test[i]);

 /* print the list */
 printf(" before  after\n"), i = 0;
 while(head->next != NULL) {
  printf("%4d\t%4d\n", test[i++], head->number);
  head = head->next;
 }

 /* free the list */
 for(current = head; current != NULL; current = next)
  next = current->next, free(current);

 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("\nTime spent sorting: %f\n", time_spent);
 return 0;
}//End main