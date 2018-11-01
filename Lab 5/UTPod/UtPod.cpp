/* UtPod.cpp

//UtPod.cpp
//
//UT Pod program
//Roger Priebe
//EE 312 10/16/18
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
* Date: 10/30/18
*
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include "song.h"
#include "UtPod.h"

using namespace std;

//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod(){
    memSize = MAX_MEMORY;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){
    memSize = size;
    if((memSize > MAX_MEMORY) || (memSize <= 0)){
        memSize = MAX_MEMORY;
    }
    songs = NULL;
    unsigned int currentTime1 = (unsigned) time(0);
    srand(currentTime1);
}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms - An address to a string constant

 output parms - An integer for success or error
*/

int UtPod::addSong(Song const &s){
    if(s.getSize() <= 0){
        cout << "ERROR. Song not added. Size needs to be greater than 0." << endl;
    } else if(s.getTitle() == "" || s.getArtist() == ""){
        cout << "ERROR. Song not added. Title/Artist cannot be blank" << endl;
    } else if(s.getSize() > getRemainingMemory()){
        cout << "ERROR. Song not added. Song size is too large" << endl;
        return -1;
    } else {
        SongNode *traversePtr;
        SongNode *newNode;

        newNode = new SongNode;

        newNode->s = s;
        newNode->next = NULL;

        if (songs == NULL) {
            songs = newNode;
        } else {
            traversePtr = songs;

            while (traversePtr->next != NULL) {
                traversePtr = traversePtr->next;
            }

            traversePtr->next = newNode;
        }
    }
        return 0;
}


/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -2 if nothing is removed


   input parms - An address to a string constant

   output parms - integer for success or error
*/

int UtPod::removeSong(Song const &s){
    bool songRemove = false;

    SongNode *previousPtr;
    SongNode *traversePtr = songs;

    while(songRemove == false) {
        if (songs == NULL) {
            cout << "ERROR. Empty List." << endl;
            return -2;
        } else if (songs->s == s) {
            traversePtr = songs->next;
            delete songs;
            songs = traversePtr;
            songRemove = true;
        } else {
            while((traversePtr->next != NULL) && (traversePtr->s != s)){
                previousPtr = traversePtr;
                traversePtr = traversePtr->next;
            }
            if(traversePtr->s == s){
                previousPtr->next = traversePtr->next;
                delete traversePtr;
                songRemove = true;
            } else {
                cout << "ERROR. Song is not in list." << endl;
                return -2;
            }

        }

    }
    return 0;

}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    or will do nothing if there are less than two songs in the current list

   input parms - none

   output parms - none
*/

void UtPod::shuffle(){
    int cnt=0;
    SongNode temp;

    SongNode *traversePtr;
    SongNode *swapPtr;

    for(traversePtr = songs; traversePtr != NULL; traversePtr = traversePtr->next){
        cnt++;
    }

    if(cnt > 2) {
        for (int i = 0; i < cnt; i++) {
            traversePtr = songs;
            swapPtr = songs;

            int num1 = (rand() % cnt);
            int num2 = (rand() % cnt);

            for (int j = 0; j < num1; j++) {
                traversePtr = traversePtr->next;
            }

            for (int k = 0; k < num2; k++) {
                swapPtr = swapPtr->next;
            }

            temp = *swapPtr;
            swapPtr->s = traversePtr->s;
            traversePtr->s = temp.s;
        }
    }
}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

   input parms - none

   output parms - none
*/

void UtPod::showSongList(){
    SongNode *traversePtr = songs;

    while(traversePtr != NULL){
        cout << traversePtr -> s.getTitle()
             << ", " << traversePtr -> s.getArtist()
             << ", " << traversePtr -> s.getSize() << " MB"
             << endl;
        traversePtr = traversePtr->next;
    }
}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    or will do nothing if there are less than two songs in the current list

   input parms - none

   output parms - none
*/

void UtPod::sortSongList(){
    SongNode *traversePtr;
    SongNode *nodePtr=songs;
    int cnt =0;
    Song temp;

    for(nodePtr = songs; nodePtr != NULL; nodePtr = nodePtr->next){
        cnt++;
    }
    for (int i = 0; i < cnt; i++) {
        for (nodePtr = songs; nodePtr->next != NULL; nodePtr = nodePtr->next) {
            traversePtr = nodePtr->next;
            if ((traversePtr->s) > (nodePtr->s)) {
                temp = nodePtr->s;
                nodePtr->s = traversePtr->s;
                traversePtr->s = temp;
            }
        }
    }

}


/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms - none

   output parms - none
*/
void UtPod::clearMemory(){
    SongNode *traversePtr;
    traversePtr = songs;

    while(traversePtr != NULL){
        traversePtr = songs;
        songs= songs->next;
        delete traversePtr;
        traversePtr = songs;
    }
    songs = NULL;
}


/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms - None

   output parms - returns an integer
*/

int UtPod::getRemainingMemory(){
    int sum = 0;
    int rem;
    SongNode *traversePtr;
    traversePtr = songs;
    while(traversePtr != NULL){
        sum = sum + traversePtr->s.getSize();
        traversePtr = traversePtr->next;
    }
    rem = getTotalMemory() - sum;
    return rem;
}

//Destructor
UtPod::~UtPod() {
    clearMemory();
}

