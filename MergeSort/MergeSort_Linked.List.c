#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
 int number;
 struct node *next;
};

/* add a node to the linked list */
struct node *addnode(int number, struct node *next);
/* preform merge sort on the linked list */
struct node *mergesort(struct node *head);
/* merge the lists.. */
struct node *merge(struct node *head_j, struct node *head_k);

/* add a node to the linked list */
struct node *addnode(int number, struct node *next) {
 struct node *tnode;

 tnode = (struct node*)malloc(sizeof(*tnode));

 if(tnode != NULL) {
  tnode->number = number;
  tnode->next = next;
 }

 return tnode;
}

/* preform merge sort on the linked list */
struct node *mergesort(struct node *head) {
 struct node *head_j;
 struct node *head_k;

 if((head == NULL) || (head->next == NULL)) 
  return head;

 head_j = head;
 head_k = head->next;
 while((head_k != NULL) && (head_k->next != NULL)) {
  head = head->next;
  head_k = head->next->next;
 }
 head_k = head->next;
 head->next = NULL;

 return merge(mergesort(head_j), mergesort(head_k));
}

/* merge the lists.. */
struct node *merge(struct node *head_j, struct node *head_k) {
 struct node *head_three;

 if(head_j == NULL) 
  return head_k;

 if(head_k == NULL) 
  return head_j;

 if(head_j->number < head_k->number) {
  head_three = head_j;
  head_three->next = merge(head_j->next, head_k);
 } else {
  head_three = head_k;
  head_three->next = merge(head_j, head_k->next);
 }

 return head_three;
}


int main(void) {
 struct node *head;
 struct node *current;
 struct node *next;
 int test[] = {8, 3, 2, 6, 1, 5, 4, 7, 9, 0};
 int i;

 head = NULL;
 /* insert some numbers into the linked list */
 for(i = 0; i < 10; i++)
  head = addnode(test[i], head);

 printf("Sorted List: \n");
 printf("------------\n");
    
 clock_t start = clock();
 /* sort the list */
 head = mergesort(head);

 /* print the list */
 printf(" before  after\n"), i = 0;
 for(current = head; current != NULL; current = current->next)
  printf("%4d\t%4d\n", test[i++], current->number);

 /* free the list */
 for(current = head; current != NULL; current = next)
  next = current->next, free(current);

 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("\nTime spent sorting: %f\n", time_spent);
 return 0;
}//End main