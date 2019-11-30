/*********************************************************************
* Filename:  BucketSort_Int.Array.c
* Author:    Javier Montenegro (https://javiermontenegro.github.io/)
* Copyright:
* Details:   This code is the implementation of the bucketsort algorithm.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NARRAY 8  /* array size */
#define NBUCKET 5 /* bucket size */
#define INTERVAL 10 /* bucket range */

struct Node
{
    int data;
    struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

void BucketSort(int arr[])
{
    int i,j;
    struct Node **buckets;

    /* allocate memory for array of pointers to the buckets */
    buckets = (struct Node **)malloc(sizeof(struct Node*) * NBUCKET);

    /* initialize pointers to the buckets */
    for(i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = NULL;
    }//End for

    /* put items into the buckets */
    /* creates a link list in each bucket slot */
    for(i = 0; i < NARRAY; ++i)
    {
        struct Node *current;
        int pos = getBucketIndex(arr[i]);
        current = (struct Node *) malloc(sizeof(struct Node));
        current->data = arr[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }//End for

    /* check what's in each bucket */
    for(i = 0; i < NBUCKET; i++)
    {
        printf("Bucket[\"%d\"] : ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }//End for

    /* sorting bucket using Insertion Sort */
    for(i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = InsertionSort(buckets[i]);
    }//End for

    /* check what's in each bucket */
    printf("--------------\n");
    printf("Buckets after sorted\n");
    for(i = 0; i < NBUCKET; i++)
    {
        printf("Bucket[\"%d\"] : ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }//End for

    /* put items back to original array */
    for(j =0, i = 0; i < NBUCKET; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while(node)
        {

            // precondition for avoiding out of bounds by the array
            assert(j < NARRAY);
            arr[j++] = node->data;
            node = node->next;
        }//End while
    }//End for

    /* free memory */
    for(i = 0; i < NBUCKET; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while(node)
        {
            struct Node *tmp;
            tmp = node;
            node = node->next;
            free(tmp);
        }//End while
    }//End for
    free(buckets);
    return;
}//End BucketSort

/* Insertion Sort */
struct Node *InsertionSort(struct Node *list)
{
    struct Node *k,*nodeList;
    /* need at least two items to sort */
    if(list == NULL || list->next == NULL)
    {
        return list;
    }

    nodeList = list;
    k = list->next;
    nodeList->next = NULL; /* 1st node is new list */
    while(k != NULL)
    {
        struct Node *ptr;
        /* check if insert before first */
        if(nodeList->data > k->data)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next; // important for the while
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }//End if

        // from begin up to end
        // finds [i] > [i+1]
        for(ptr = nodeList; ptr->next != NULL; ptr = ptr->next)
        {
            if(ptr->next->data > k->data) break;
        }//End for

        // if found (above)
        if(ptr->next != NULL)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next; // important for the while
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next; // important for the while
            ptr->next->next = NULL;
            continue;
        }//End if
    }//End while
    return nodeList;
}

int getBucketIndex(int value)
{
    return value/INTERVAL;
}//End getBucketIndex

void print(int arr[])
{
    int i;
    for(i = 0; i < NARRAY; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}//End print

void printBuckets(struct Node *list)
{
    struct Node *cur = list;
    while(cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }//End while
}//End printBuckets

int main(void)
{
    int array[NARRAY] = {29,25,-1,49,9,37,21,43};
    
    printf("Initial array\n");
    print(array);
    printf("------------\n");
    
    clock_t start = clock();
    BucketSort(array);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("------------\n");
    printf("Sorted array\n");
    
    print(array);
    printf("Time spent sorting: %f\n", time_spent);
    return 0;
}//End main
