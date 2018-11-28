#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

//stack312_ll.h
//Stack Linked List header file
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


typedef struct Pixel {
    int row;
    int col;
    char color;
} Pixel;

typedef Pixel StackEntry;

typedef struct StackNode {
    StackEntry pixel;
    struct StackNode *next;
} StackNode;

typedef struct Stack312 {
    struct StackNode *top;
} Stack312;

//Pre-Condition: passes in potiner to a StackNode datatype
//Post-Condition: Initializes a Node at Null, beginning of Linked List
void makeStack(Stack312 *s);

//Pre-Condition: passes in pointer to Stack312 s
//Post-Condition: Returns True is full, and false if not full
bool isFull(Stack312 s);

//Pre-Condition: passes in pointer to Stack312 s
//Post-Condition: Returns True if stack is empty, and false if not empty
bool isEmpty(Stack312 s);

//Pre-Condition: passes in a Stackentry datatype, Pixel and a pointer to a StackNode
//Post-Condition: Pushes Stackentry onto Stack and add another node to linked list, updates top of linked list
void push(StackEntry e,Stack312 *s);

//Pre-Condition: passes in a pointer to a StackNode datatype
//Post-Condition: Returns StackEntry of current StackNode and updates top to previous linked list
StackEntry pop(Stack312 *s);
