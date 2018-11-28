#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack312_arr.h"

//stack312_arr.c
//
//Stack Array driver program
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
    s -> top = -1;
}

bool isFull(Stack312 s){
    if(s.top >= 99){
        return true;
    } else {
        return false;
    }
}

bool isEmpty(Stack312 s){
    if(s.top == -1) {
        return true;
    } else {
        return false;
    }
}

void push(StackEntry e,Stack312 *s){
    s -> top++;
    s -> elements[s->top] = e;
}

StackEntry pop(Stack312 *s){
    StackEntry temp = s->elements[s->top];
    s->top--;
    return temp;
}


