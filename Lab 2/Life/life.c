// life.h
// -- EE 312 Project 2

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
 *///
// Created by priebe on 9/5/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef PROGLIFE_LIFE_H
#define PROGLIFE_LIFE_H

#endif //PROGLIFE_LIFE_H
#include "string.h"
#include "life.h"

//This function populates the Grid with the initial state from the text file
void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {
    *numRows = 0;                                               //initalize values to 0
    *numCols = 0;
    FILE *fptr;                                                 //open the file
    fptr = fopen(fname, "r");                                   //the r is for read

    /*if (fptr == NULL) {
        printf("hey you screwed up!\n");                        //check if the file opens
        exit(-1);
    } else {
        printf("file open\n");
    }*/

    /*char buf[BUFSIZ];
    while (fgets(buf, sizeof(buf), fptr)) {                     //prints file to check
        printf("%s", buf);
        (*numRows)++;
    }
    printf("%d\n", *numRows);                                   //used to check # of rows
    *numCols = strlen(buf)-1;                                   //used to check # of Columns
    printf("%d\n", *numCols);*/
    char buf[BUFSIZ];                                           //assigns buffer for text file
    while (fgets(buf, sizeof(buf), fptr)) {                     //goes through the whole text file buffer
        *numCols = strlen(buf);                                 //# of columns = a string length of buffer
        grid[*numRows] = malloc(sizeof(char)*(*numCols));       //every row has the number of columns*a byte for char
        for(int i = 0;i < *numCols;i++){
            grid[*numRows][i] = buf[i];                         //fills each column in a row with the string character
        }
        (*numRows)++;                                           //goes to next element in array/ next row
    }
}

//This function takes the updated world and outputs the state, iterating it showing * and .
void showWorld(char *grid[], int numRows, int numCols){
    for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(grid[i][j] == '1'){                          //if the character is a 1 it will print *
                    printf("%c", '*');                          //living cell
                }
                if(grid[i][j] == '0'){                          //if the character is a 0 it will print .
                    printf("%c", '.');                          //dead cell
                }
            }
            printf("\n");
    }
}

//This function takes the state of the grid in 1s and 0s and iterates the grid
//A new cell is born on an empty square if is surrounded by exactly three neighboring cells
//A cell dies of overcrowding if it has four or more neighbors
//A cell dies of loneliness if it has zero or one neighbor
//Any live cell with two or three live neighbors lives, unchanged, to the next generation.
//Living Cell == 1, Dead Cell == 0
void iterateGeneration(char *grid[], int numRows, int numCols) {
    char *tempGrid[numRows];
    int cnt =0;							//cnt is used to count the # of alive cells
    for (int i = 0; i < numRows; i++) { 			//allocates memory for temporary grid 
            tempGrid[i] = malloc(sizeof(char)*numCols);
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            tempGrid[i][j] = grid[i][j];			//copies grid state into temporary grid
        }
    }
    /*for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {                     //code used to check if memory was allocated
            printf("%c", tempGrid[i][j]);                       //correctly for tempGrid
        }
    }*/
    for (int i = 0; i < numRows; i++){
        for(int j = 0; j< numCols; j++){
            //accounts for top left corner
            if(i==0 && j==0){
                if(grid[i][j] == '1'){
                    cnt=0;
                    if(grid[i][j+1] == '1') {			//these first four cases are the four corners
                        cnt++;					//top left,top right, bottom, left, bottom right
                    }						//each corner can have at most three neighbors
                    if(grid[i+1][j] == '1') {			//so an alive cell can only die if it has 0 or 1 
                        cnt++;					//neighbor surrounding it
                    }						//checks amount of live cells to determine
                    if(grid[i+1][j+1] == '1') {			//state of cell
                        cnt++;					//if there are 2 or 3 neighbors nothing changes
                    }						//grid is copied to tempGrid, so state stays the same
                    if(cnt <= 1){
                        tempGrid[i][j] = '0';
                    }
                }
                if(grid[i][j] == '0'){
                    cnt = 0;
                    if(grid[i][j+1] == '1') {			//since corners only have three neighbors
                        cnt++;					//check to see if an empty space can be alive
                    }
                    if(grid[i+1][j] == '1') {
                        cnt++;
                    }
                    if(grid[i+1][j+1] == '1') {
                        cnt++;
                    }
                    if(cnt == 3){
                        tempGrid[i][j] = '1';
                    }
                }
            }
            //accounts for top right corner
            if(i==0 && j==numCols-1){				//same for the rest of the corner cases
                if(grid[i][j] == '1'){
                    cnt=0;
                    if(grid[i][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j-1] == '1'){
                        cnt++;
                    }
                    if(cnt <= 1){
                        tempGrid[i][j] = '0';
                    }
                }
                if(grid[i][j] == '0'){
                    cnt=0;
                    if(grid[i][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j-1] == '1'){
                        cnt++;
                    }
                    if(cnt == 3){
                        tempGrid[i][j] = '1';
                    }
                }
            }
            //accounts for bottom left corner
            if(i==numRows-1 && j==0){
                if(grid[i][j] == '1'){
                    cnt=0;
                    if(grid[i][j+1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j+1] == '1'){
                        cnt++;
                    }
                    if(cnt <= 1){
                        tempGrid[i][j] = '0';
                    }
                }
                if(grid[i][j] == '0'){
                    cnt=0;
                    if(grid[i][j+1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j+1] == '1'){
                        cnt++;
                    }
                    if(cnt == 3){
                        tempGrid[i][j] = '1';
                    }
                }
            }
            //accounts for bottom right corner
            if(i==numRows-1 && j==numCols-1){
                if(grid[i][j] == '1'){
                    cnt=0;
                    if(grid[i][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j-1] == '1'){
                        cnt++;
                    }
                    if(cnt <= 1){
                        tempGrid[i][j] = '0';
                    }
                }
                if(grid[i][j] == '0'){
                    cnt=0;
                    if(grid[i][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j-1] == '1'){
                        cnt++;
                    }
                    if(cnt == 3){
                        tempGrid[i][j] = '1';
                    }
                }
            }
            //accounts for top row
            if(i==0 && j>0 && j<(numCols-1)){
                if(grid[i][j] == '1'){
                    cnt=0;
                    if(grid[i][j+1] == '1'){				//top most, bottomost, rightmost, and leftmost rows
                        cnt++;						//are another special case, each has at most
                    }							//5 neighbors and we need to check if an alive cell
                    if(grid[i][j-1] == '1'){				//has o or 1 neigbor or 4 or more alive neigbors
                        cnt++;						//if so the alive cell dies
                    }
                    if(grid[i+1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j+1] == '1'){
                        cnt++;
                    }
                    if(cnt <= 1 || cnt >= 4){
                        tempGrid[i][j] = '0';
                    }
                }
                if(grid[i][j] == '0'){
                    cnt=0;
                    if(grid[i][j+1] == '1'){				//to check if the empty cell becomes alive
                        cnt++;						//count the amount of alive cells surrounding it
                    }							//if alive cell neigbors = 3, it becomes alive
                    if(grid[i][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j+1] == '1'){
                        cnt++;
                    }
                    if(cnt == 3){
                        tempGrid[i][j] = '1';
                    }
                }
            }
            //accounts for left row
            if(0<i<numRows-1 && j==0){					//same for the rest of the row cases
                if(grid[i][j] == '1') {
                    cnt = 0;
                    if (grid[i][j + 1] == '1') {
                        cnt++;
                    }
                    if (grid[i - 1][j] == '1') {
                        cnt++;
                    }
                    if (grid[i + 1][j] == '1') {
                        cnt++;
                    }
                    if (grid[i + 1][j + 1] == '1') {
                        cnt++;
                    }
                    if (grid[i - 1][j + 1] == '1') {
                        cnt++;
                    }
                    if (cnt <= 1 || cnt >= 4) {
                        tempGrid[i][j] = '0';
                    }
                }
                if(grid[i][j] == '0'){
                    cnt=0;
                    if(grid[i][j+1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j+1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j+1] == '1'){
                        cnt++;
                    }
                    if(cnt == 3){
                        tempGrid[i][j] = '1';
                    }
                }
            }
            //accounts for right row
            if(0<i<numRows-1 && j==numCols-1){
                if(grid[i][j] == '1'){
                    cnt=0;
                    if(grid[i][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j-1] == '1'){
                        cnt++;
                    }
                    if(cnt <= 1 || cnt >= 4){
                        tempGrid[i][j] = '0';
                    }
                }
                if(grid[i][j] == '0'){
                    cnt=0;
                    if(grid[i][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i+1][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j-1] == '1'){
                        cnt++;
                    }
                    if(cnt == 3){
                        tempGrid[i][j] = '1';
                    }
                }
            }
            //accounts for bottom row
            if(i==numRows-1 && 0<j<numCols-1){
                if(grid[i][j] == '1'){
                    cnt=0;
                    if(grid[i][j+1] == '1'){
                        cnt++;
                    }
                    if(grid[i][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j+1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j-1] == '1'){
                        cnt++;
                    }
                    if(cnt <= 1 || cnt >= 4){
                        tempGrid[i][j] = '0';
                    }
                }
                if(grid[i][j] == '0'){
                    cnt=0;
                    if(grid[i][j+1] == '1'){
                        cnt++;
                    }
                    if(grid[i][j-1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j+1] == '1'){
                        cnt++;
                    }
                    if(grid[i-1][j-1] == '1'){
                        cnt++;
                    }
                    if(cnt == 3){
                        tempGrid[i][j] = '1';
                    }
                }
            }
            //General iteration for everything else other than top row, left row, right row, bottom row
            //top left corner, top right corner, bottom left corner, and bottom right corner
            else if(grid[i][j] == '1'){
                cnt=0;
                if(grid[i][j+1] == '1'){				//the rest of the grid cells have at most 8 neighbors
                    cnt++;						//counts how many live cells surround a live cell
                }							
                if(grid[i][j-1] == '1'){
                    cnt++;
                }
                if(grid[i-1][j] == '1'){
                    cnt++;
                }
                if(grid[i+1][j] == '1'){
                    cnt++;
                }
                if(grid[i+1][j+1] == '1'){
                    cnt++;
                }
                if(grid[i+1][j-1] == '1'){
                    cnt++;
                }
                if(grid[i-1][j+1] == '1'){
                    cnt++;
                }
                if(grid[i-1][j-1] == '1'){
                    cnt++;
                }
                if(cnt <= 1 || cnt >= 4){				//if the amount of live cell is 0,1, or 4 or more
                    tempGrid[i][j] = '0';				//cell dies
                }
            } else if(grid[i][j] == '0'){
                cnt=0;
                if(grid[i][j+1] == '1'){
                    cnt++;						//counts # of alive cell around dead cell
                }
                if(grid[i][j-1] == '1'){
                    cnt++;
                }
                if(grid[i-1][j] == '1'){
                    cnt++;
                }
                if(grid[i+1][j] == '1'){
                    cnt++;
                }
                if(grid[i+1][j+1] == '1'){
                    cnt++;
                }
                if(grid[i+1][j-1] == '1'){
                    cnt++;
                }
                if(grid[i-1][j+1] == '1'){
                    cnt++;
                }
                if(grid[i-1][j-1] == '1'){
                    cnt++;
                }
                if(cnt == 3){						//if the number equals 3 then the dead cell becomes alive
                    tempGrid[i][j] = '1';
                }
            }

        }
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {				//copies the tempGrid into grid, showworld will
            grid[i][j] = tempGrid[i][j];				//show iterated world
        }
    }
    for (int i = 0; i < numRows; i++){
            free(tempGrid[i]);
    }
}

