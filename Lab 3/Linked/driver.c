#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"
#include "stack312_ll.h"

//driver.c
//
//Stack Linked List Driver program
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
int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    char fName[] = "max.txt";
    Stack312 s;                                                             //iniitialize stack
    makeStack(&s);
    int selRow;
    int selCol;
    char selColor;
    char nextColor;                                                         //color to change to
    FILE *fptr;                                                             //open the file
    fptr = fopen(fName, "r");                                               //the r is for read
    char buf[BUFSIZ];                                                       //assigns buffer for text file
    char grid[25][25];                                                      //max picture is 25x25
    int numRows = 0;

    while (fgets(buf, sizeof(buf), fptr)) {                                 //goes through the whole text file buffer
        int numCols = strlen(buf);
        for(int i = 0; i < numCols; i++){
            grid[numRows][i] = buf[i];
        }
        numRows++;                                                          //counts number of rows
    }

    while(!isFull(s)) {
        for (int i = 0; i < numRows; i++) {
            int numCols = strlen(buf);
            for (int j = 0; j < numCols; j++) {                             //while stack is not full print grid
                printf("%c", grid[i][j]);
            }
            printf("%c", '\n');
        }
        printf("%c", '\n');
        printf("Enter a row: ");                                            //enter a row,column,and color
        scanf("%d", &selRow);
        printf("Enter a column: ");
        scanf("%d", &selCol);
        printf("Enter a color: ");
        scanf(" %c", &selColor);
        printf("%c", '\n');
        /*selRow = -1;
        selCol = -1;
        selColor = 'R';*/
        nextColor = selColor;                                               //selected color is color to change into
        int numCols = strlen(buf);                                          //number of columns euqals string length
        if(grid[selRow][selCol] != nextColor) {
            if (selRow >= 0 && selRow <= numRows - 1 && selCol >= 0 && selCol <= numCols - 1) {
                Pixel p1 = {selRow, selCol, grid[selRow][selCol]};          //if current coordinate isnt the same color
                push(p1, &s);                                               //or coordinate is out of bounds, skip
                while (!isEmpty(s)) {                                       //while stack isnt empty
                    Pixel p2 = pop(&s);                                     //pop and change selected character
                    //Top Left Corner
                    if (p2.row == 0 && p2.col == 0) {                       //push valid neighbors
                        if (p2.color == grid[p2.row][p2.col]) {             //pops until all valid neighbors are changed
                            grid[p2.row][p2.col] = nextColor;
                        }
                        if (grid[p2.row + 1][p2.col] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col, grid[p2.row + 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row, p2.col + 1, grid[p2.row][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row + 1][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col + 1, grid[p2.row + 1][p2.col + 1]};
                            push(p, &s);
                        }
                    }
                    //Top Right Corner
                    if (p2.row == 0 && p2.col == (numCols - 1)) {
                        if (p2.color == grid[p2.row][p2.col]) {
                            grid[p2.row][p2.col] = nextColor;
                        }
                        if (grid[p2.row + 1][p2.col] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col, grid[p2.row + 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row, p2.col - 1, grid[p2.row][p2.col - 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row + 1][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col - 1, grid[p2.row + 1][p2.col - 1]};
                            push(p, &s);
                        }
                    }
                    //Bottom Left Corner
                    if (p2.row == (numRows - 1) && p2.col == 0) {
                        if (p2.color == grid[p2.row][p2.col]) {
                            grid[p2.row][p2.col] = nextColor;
                        }
                        if (grid[p2.row - 1][p2.col] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col, grid[p2.row - 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row, p2.col + 1, grid[p2.row][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col + 1, grid[p2.row - 1][p2.col + 1]};
                            push(p, &s);
                        }
                    }
                    //Bottom Right Corner
                    if (p2.row == (numRows - 1) && p2.col == (numCols - 1)) {
                        if (p2.color == grid[p2.row][p2.col]) {
                            grid[p2.row][p2.col] = nextColor;
                        }
                        if (grid[p2.row - 1][p2.col] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col, grid[p2.row - 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row, p2.col - 1, grid[p2.row][p2.col - 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col - 1, grid[p2.row - 1][p2.col - 1]};
                            push(p, &s);
                        }
                    }
                    //Top Row
                    if (p2.row == 0 && p2.col > 0 && p2.col < (numCols - 1)) {
                        if (p2.color == grid[p2.row][p2.col]) {
                            grid[p2.row][p2.col] = nextColor;
                        }
                        if (grid[p2.row + 1][p2.col] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col, grid[p2.row + 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row, p2.col + 1, grid[p2.row][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row, p2.col - 1, grid[p2.row][p2.col - 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row + 1][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col + 1, grid[p2.row + 1][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row + 1][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col - 1, grid[p2.row + 1][p2.col - 1]};
                            push(p, &s);
                        }
                    }
                    //Left Row
                    if (p2.row < (numRows - 1) && p2.row > 0 && p2.col == 0) {
                        if (p2.color == grid[p2.row][p2.col]) {
                            grid[p2.row][p2.col] = nextColor;
                        }
                        if (grid[p2.row + 1][p2.col] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col, grid[p2.row + 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row, p2.col + 1, grid[p2.row][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col, grid[p2.row - 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row + 1][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col + 1, grid[p2.row + 1][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col + 1, grid[p2.row - 1][p2.col + 1]};
                            push(p, &s);
                        }
                    }
                    //Right Row
                    if (p2.row < (numRows - 1) && p2.row > 0 && p2.col == (numCols - 1)) {
                        if (p2.color == grid[p2.row][p2.col]) {
                            grid[p2.row][p2.col] = nextColor;
                        }
                        if (grid[p2.row + 1][p2.col] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col, grid[p2.row + 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row, p2.col - 1, grid[p2.row][p2.col - 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col, grid[p2.row - 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row + 1][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col - 1, grid[p2.row + 1][p2.col - 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col - 1, grid[p2.row - 1][p2.col - 1]};
                            push(p, &s);
                        }
                    }
                    //Bottom Row
                    if (p2.row == (numRows - 1) && p2.col > 0 && p2.col < (numCols - 1)) {
                        if (p2.color == grid[p2.row][p2.col]) {
                            grid[p2.row][p2.col] = nextColor;
                        }
                        if (grid[p2.row - 1][p2.col] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col, grid[p2.row - 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row, p2.col + 1, grid[p2.row][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row, p2.col - 1, grid[p2.row][p2.col - 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col + 1, grid[p2.row - 1][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col - 1, grid[p2.row - 1][p2.col - 1]};
                            push(p, &s);
                        }
                    }
                    //General Case
                    if (p2.row > 0 && p2.row < (numRows - 1) && p2.col > 0 && p2.col < (numCols - 1)) {
                        if (p2.color == grid[p2.row][p2.col]) {
                            grid[p2.row][p2.col] = nextColor;
                        }
                        if (grid[p2.row + 1][p2.col] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col, grid[p2.row + 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row, p2.col + 1, grid[p2.row][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col, grid[p2.row - 1][p2.col]};
                            push(p, &s);
                        }
                        if (grid[p2.row][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row, p2.col - 1, grid[p2.row][p2.col - 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row + 1][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col + 1, grid[p2.row + 1][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row + 1][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row + 1, p2.col - 1, grid[p2.row + 1][p2.col - 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col + 1] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col + 1, grid[p2.row - 1][p2.col + 1]};
                            push(p, &s);
                        }
                        if (grid[p2.row - 1][p2.col - 1] == p2.color) {
                            Pixel p = {p2.row - 1, p2.col - 1, grid[p2.row - 1][p2.col - 1]};
                            push(p, &s);
                        }
                    }
                    /*Pixel p = {1, 1, 'B'};
                    push(p, &s);
                    Pixel p2 = pop(&s);
                     */
                }
            }
        }

    }
    return 0;
}