#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include "header.h"

int main()
{

    struct node *n;
    
    nodeptr head = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        return 1;
    }

    head->next = NULL;
    head->info = 5;

    int arr[] = { 8, 100, -10, 2, 1};

    printf("Welcome to BubbleSort algorithem");

    for (int i = 0; i < 5; i++)
    {
        n = (struct node*)malloc(sizeof(struct node));

        n->info = arr[i];
        n->next = head;
        head = n;
    }

//    nodeptr firstNode = head;
//    nodeptr secondNode = head->next->next->next->next;
//    nodeptr thirdNode = head->next;


    printList(head);

    head = bubbleSort(head);
//    swap(firstNode, secondNode);
//    swap(secondNode, thirdNode);
    printList(head);

    return 1;

}
