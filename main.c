#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc/malloc.h>
//
//  file: main.c
//  project: PointersSwapper + BubbleSort in C
//
//  Created by Ido Sharon on 02/10/2020.
//

#include <stdlib.h>
#include "header.h"

int main()
{

    struct node *n;
    
    nodeptr head = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
        return 1;
    
    
    const int LENGTH = 2;

    head->next = NULL;
    head->info = 9;

    int arr[LENGTH] = { 10, -10};

    printf("Welcome to BubbleSort algorithem");

    for (int i = 0; i < LENGTH; i++)
    {
        n = (struct node*)malloc(sizeof(struct node));

        n->info = arr[i];
        n->next = head;
        head = n;
    }

    printList(head);

    head = bubbleSort(head);
    printf("\n");

    return 1;

}
