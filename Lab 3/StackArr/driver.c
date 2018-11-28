#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"
#include "stack312_arr.h"
//driver.c
//
//Stack Array program
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
 //This  program checks to see whther or not an equation is balanced or not
 //The program accounts for valid equations and will declare the missing delimiter that makes the equation invalid
 //Delimiters include parethesis, angled braces, and brackets
int main(int argc, char *argv[]) {
    char fName[] = "exp.dat";
    printf("Hello, World!\n");
    Stack312 s;                                                             //declare stack
    makeStack(&s);                                                          //initialize stack
    FILE *fptr;                                                             //open the file
    fptr = fopen(fName, "r");                                               //the r is for read
    char buf[BUFSIZ];                                                       //assigns buffer for text file
    while (fgets(buf, sizeof(buf), fptr)) {                                 //goes through the whole text file buffer
        while(!isFull(s)) {
            int numChar = strlen(buf);                                     //# of characters = a string length of buffer
            char grid[numChar];                                            //create array to hold string
            for (int i = 0; i < numChar; i++) {
                grid[i] = buf[i];                                           //copy buffer into array
            }
            for (int i = 0; i < numChar; i++) {
                if (grid[i] == '(' || grid[i] == ')' || grid[i] == '<' || grid[i] == '>' || grid[i] == '[' ||
                    grid[i] == ']') {                                       //only looks at delimiters in string
                    if (grid[i] == '(') {                                   //pushes only right facing delimiters
                        if(isFull(s)){
                            break;
                        }
                        push(grid[i], &s);
                    }
                    if (grid[i] == '<') {
                        if(isFull(s)){
                            break;
                        }
                        push(grid[i], &s);
                    }
                    if (grid[i] == '[') {
                        if(isFull(s)){
                            break;
                        }
                        push(grid[i], &s);
                    } else if (isEmpty(s)) {                                //if the stack is empty check to see if the
                        if (grid[i] == '>') {                               //the first delimiter in the string is
                            for (int j = 0; j < numChar - 1; j++) {         //a left facing delimiter
                                printf("%c", buf[j]);                       //if so, automatically prints missing
                            }                                               //corresponding right facing delimiter
                            printf("%s", " === missing <\n");               //and moves on to next equation
                            push(grid[i], &s);
                            break;
                        }
                        if (grid[i] == ')') {
                            for (int j = 0; j < numChar - 1; j++) {
                                printf("%c", buf[j]);
                            }
                            printf("%s", " === missing (\n");
                            push(grid[i], &s);
                            break;
                        }
                        if (grid[i] == ']') {
                            for (int j = 0; j < numChar - 1; j++) {
                                printf("%c", buf[j]);
                            }
                            printf("%s", " === missing [\n");
                            push(grid[i], &s);
                            break;
                        }
                    } else {                                                //if the stack is not empty, then there is
                        if (grid[i] == ')') {                               //at least on right facing delimiter on the
                            char c = pop(&s);                               //stack, and now we check the current
                            if (c == '(') {                                 //character and compare to the latest entry
                                push(c, &s);                                //on the stack
                                pop(&s);                                    //if the current character corresponds to
                            } else {                                        //the right facing character, pop the latest
                                push(c, &s);                                //entry off the stack
                                break;                                      //otherwise get out of comparing and skip
                            }
                        }
                        if (grid[i] == '>') {
                            char c = pop(&s);
                            if (c == '<') {
                                push(c, &s);
                                pop(&s);
                            } else {
                                push(c, &s);
                                break;
                            }
                        }
                        if (grid[i] == ']') {
                            char c = pop(&s);
                            if (c == '[') {
                                push(c, &s);
                                pop(&s);
                            } else {
                                push(c, &s);
                                break;
                            }
                        }
                    }
                }
            }


            if (isEmpty(s)) {                                               //if the stack is empty after looking at all
                for (int i = 0; i < numChar - 1; i++) {                     //characters than the equation is balanced
                    printf("%c", buf[i]);                                   //and valid
                }
                printf("%s", " === valid expression\n");
                break;
            }
            if (!isEmpty(s)){                                               //if the equation is not empty
                char c = pop(&s);
                if(c == ']' || c == ')' || c == '>'){                       //this pops remaining elements off the stack
                    while(!isEmpty(s)){                                     //so the stack is empty for the next string
                        pop(&s);
                    }
                    break;
                } else {
                    if(c == '('){                                           //prints out the cause of invalid equation
                        for (int i = 0; i < numChar - 1; i++) {             //equation might be balanced but invalid
                            printf("%c", buf[i]);                           //or imbalanced
                        }
                        printf("%s", " === missing )\n");
                    }
                    if(c == '['){
                        for (int i = 0; i < numChar - 1; i++) {
                            printf("%c", buf[i]);
                        }
                        printf("%s", " === missing ]\n");
                    }
                    if(c == '<'){
                        for (int i = 0; i < numChar - 1; i++) {
                            printf("%c", buf[i]);
                        }
                        printf("%s", " === missing >\n");
                    }
                }
                while(!isEmpty(s)){                                          //empties stack for next string
                    pop(&s);
                }
                break;
            }
        }
    }
}