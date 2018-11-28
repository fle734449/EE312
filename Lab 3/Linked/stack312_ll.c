#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"
#include "stack312_ll.h"

//stack312_ll.c
//Stack Linked List source file
//Roger Priebe
//EE 312
/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Frank Le, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Frank Le
 * email address: frank.le@utexas.edu
 * UTEID: fpl227
 * Section 5 digit ID: 16190
 *
 */

void makeStack(Stack312 *s){
    s -> top = NULL;
}

bool isFull(Stack312 s){
    return false;
}

bool isEmpty(Stack312 s){
    if(s.top == NULL){
        return true;
    } else {
        return false;
    }
}

void push(StackEntry e,Stack312 *s){
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode -> pixel = e;
    newNode -> next = s -> top;
    s->top = newNode;
}

StackEntry pop(Stack312 *s){
    StackNode *currentNode = s->top;
    Pixel p = currentNode->pixel;
    currentNode = currentNode->next;
    free(s->top);
    s->top = currentNode;
    return p;
}

