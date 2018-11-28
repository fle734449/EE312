#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

//flood_fill.c
//
//Flood Fill Recursive Program
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
* Date:10/16/18
*
*/

//**********  Function Prototypes  ******************

//function floodfill
//input parameter - array of pointers to characters(char), integer(int), int, char, char, int, int
//Uses floodfill function to flood fill a selected coordinate color a new selected color
void floodfill(char grid[25][25], int i, int j, char oldColor, char newColor, int numRows, int numCols);

//******************  MAIN  *****************************

//Program flood fills a given picture
//Enter -1 for either row or column to exit
//Pre-Condition: passes in program name and picture name
//Post-Condition: Executes flood fill program
//Uses recursion to flood fill a selected color inside the grid with another color
int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    //char fName[] = "max.txt";
    char fName[80];
    strcpy(fName, argv[1]);
    int selRow=0;
    int selCol=0;
    char selColor;
    char nextColor;
    FILE *fptr;
    fptr = fopen(fName, "r");
    char buf[BUFSIZ];
    char grid[25][25];
    int numRows = 0;

    //create grid
    while (fgets(buf, sizeof(buf), fptr)) {
        int numCols = strlen(buf);
        for (int i = 0; i < numCols; i++) {
            grid[numRows][i] = buf[i];
        }
        numRows++;
    }

    //show world
    while (selRow != -1 && selCol != -1) {
        for (int i = 0; i < numRows; i++) {
            int numCols = strlen(buf);
            for (int j = 0; j < numCols; j++) {
                printf("%c", grid[i][j]);
            }
            printf("%c", '\n');
        }

        printf("%c", '\n');
        printf("Enter a row: ");
        scanf("%d", &selRow);
        printf("Enter a column: ");
        scanf("%d", &selCol);
        printf("Enter a color: ");
        scanf(" %c", &selColor);
        printf("%c", '\n');
        int numCols = strlen(buf);

        if (selRow != -1 || selCol != -1) {
            if (selRow >= 0 && selRow <= numRows - 1 && selCol >= 0 && selCol <= numCols - 1) {
                floodfill(grid, selRow, selCol, grid[selRow][selCol], selColor, numRows, numCols);
            }
        }
    }
}


//function floodfill
//input parameter - array of pointers to characters(char), integer(int), int, char, char, int, int
//Uses floodfill function to flood fill a selected coordinate color a new selected color
void floodfill(char grid[25][25], int i, int j, char oldColor, char newColor, int numRows, int numCols){
    if(grid[i][j] != oldColor){
        return;
    } else if(grid[i][j] == newColor){
        return;
    }
    grid[i][j] = newColor;

    //Top Left Corner
    if (i == 0 && j == 0){
        floodfill(grid, i+1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i+1, j+1, oldColor, newColor, numRows, numCols);
    }

    //Top Right Corner
    if (i == 0 && j == numCols-1){
        floodfill(grid, i+1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j-1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i+1, j-1, oldColor, newColor, numRows, numCols);
    }

    //Bottom Left Corner
    if (i == numRows-1 && j == 0){
        floodfill(grid, i-1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j+1, oldColor, newColor, numRows, numCols);
    }

    //Bottom Right Corner
    if (i == numRows-1 && j == numCols-1){
        floodfill(grid, i-1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j-1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j-1, oldColor, newColor, numRows, numCols);
    }

    //Top Row
    if (i == 0 && j > 0 && j < numCols - 1){
        floodfill(grid, i+1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j-1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i+1, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i+1, j-1, oldColor, newColor, numRows, numCols);
    }

    //Bottom Row
    if (i == numRows-1 && j > 0 && j < numCols - 1){
        floodfill(grid, i-1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j-1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j-1, oldColor, newColor, numRows, numCols);
    }

    //Left Row
    if (i < numRows-1 && i > 0 && j == 0){
        floodfill(grid, i+1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i+1, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j+1, oldColor, newColor, numRows, numCols);
    }

    //Right Row
    if (i < numRows-1 && i > 0 && j == numCols-1){
        floodfill(grid, i+1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j-1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i+1, j-1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j-1, oldColor, newColor, numRows, numCols);
    }

    //General
    if (i > 0 && i < numRows-1 && j > 0 && j < numCols-1){
        floodfill(grid, i+1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i, j-1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i+1, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j+1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i+1, j-1, oldColor, newColor, numRows, numCols);
        floodfill(grid, i-1, j-1, oldColor, newColor, numRows, numCols);
    }
}
