//
//  file: header.h
//  project: PointersSwapper + BubbleSort in C
//
//  Created by Ido Sharon on 02/10/2020.
//

#ifndef header_h
#define header_h

#include <stdio.h>
#include "header.h"
#include <malloc/malloc.h>
#include <math.h>

typedef struct node
{
    int info;
    struct node *next;

}*nodeptr;

nodeptr swap(nodeptr p, nodeptr n, nodeptr head)
{
    if (p == n || n == NULL || p == NULL)
        return head;
    
    nodeptr steper = head;
    
    while (steper->next != NULL)
    {
        if (steper->next == p || head == p)
        {
            nodeptr inside_stepper = p;
            nodeptr temp = p->next;

            while(inside_stepper != NULL) {
                if (inside_stepper->next == n) {
                    inside_stepper->next = p;
                    break;
                }
                inside_stepper = inside_stepper->next;
            }
            
            p->next = n->next;
            
            if (temp == n) n->next = p;
            else n->next = temp;
            
            if (p == head) head = n;
            else steper->next = n;
            
            break;
        }

        steper = steper->next;
    }
    
    return head;
}

void printList(nodeptr head)
{
    nodeptr temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("-> (%p) %d (%p) ", &temp, temp->info, &temp->next);
        temp = temp->next;
    }
}

nodeptr bubbleSort(nodeptr head) {
    
    int swapped = 0;
    
    if(head == NULL)
        return head;
    
    do {
        swapped = 0;
        nodeptr p = head;
        
        while (p->next != p && p->next != NULL) {
            if (p->info > p->next->info) {
                head = swap(p, p->next, head);
                swapped = 1;
                printList(head);
            }
            if (p->next == NULL)
                break;
            
            p = p->next;
        }
    } while(swapped);
    
    return head;
};

#endif /* header_h */
