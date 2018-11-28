#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//stack_arr.h
//Stack Array header file
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
//Add documentation including Pre and Post conditions for functions
//

#define MAX_ELEMENTS 100

typedef char StackEntry;

typedef struct Stack312 {
    int top;
    StackEntry elements[MAX_ELEMENTS];
} Stack312;

//Pre-Condition: Passes a pointer of datatype Stack312
//Post-Condition: Creates/Initializes Stack ADT
void makeStack(Stack312 *s);

//Pre-Condition: Passes datatype Stack312 s
//Post-Condition: Checks to see is stack is full, returns false if full
bool isFull(Stack312 s);

//Pre-Condition: Passes datatype Stack312 s
//Post-Condition: Checks to see is stack is empty, returns true is empty and false if not
bool isEmpty(Stack312 s);

//Pre-Condition: Passes and element and pointer, both of type Stack312
//Post-Condition: Pushes element onto stack after incrementing pointer
void push(StackEntry e,Stack312 *s);

//Pre-Condition: Passes pointer of datatype Stack312
//Post-Condition: Pops element that pointer is currently pointing at and decrements pointer
StackEntry pop(Stack312 *s);

