/*********************************************************************
* Filename:  TreeSort_String.Struct.c
* Author:    Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:   This code is the implementation of the treesort algorithm.
*********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NARRAY 5 

struct tnode { 
 char *str;
 struct tnode *left; 
 struct tnode *right; 
};

void insert(struct tnode **p, char *value);
void print(struct tnode *root);
/* call by reference .. ! */
void insert(struct tnode **p, char *value) {
 if(!*p) {
  *p = (struct tnode *)malloc(sizeof(struct tnode));
  (*p)->left = (*p)->right = NULL;
  (*p)->str = strdup(value);
  return;
 }

 if(strcmp(value, (*p)->str) < 0)
  insert(&(*p)->left, value);
 else 
  insert(&(*p)->right, value);
}//End insert
 
/* inorder binary tree print ... */
void print(struct tnode *root) {
 if(root != NULL) {
  print(root->left);
  printf("%s ", root->str); 
  print(root->right);
 }//End if
 
}//End print

int main(void) {
  //char line[1024];
  struct tnode *root;
  root = NULL;
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
    insert(&root, array[i]);         
  }//End for

  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted array\n");
  print(root);

  printf("\nTime spent sorting: %f\n", time_spent);
  return 0;
}//End main
