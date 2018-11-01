/* song.cpp

//song.cpp
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
#include "song.h"
#include <string>

using namespace std;

//Default Constructor
Song::Song(){
    setArtist("");
    setTitle("");
    setSize(0);
}

//Constructor
Song::Song(string a, string t, int s){
    setArtist(a);
    setTitle(t);
    setSize(s);
}

//Overload
bool Song::operator >(const Song &rhs) {
    if(artist < rhs.artist){
        return true;
    }
    if(artist == rhs.artist){
        if(title < rhs.title){
            return true;
        }
        if(title == rhs.title){
            if(size < rhs.size){
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}


bool Song::operator <(const Song &rhs) {
    if(artist > rhs.artist){
        return true;
    }
    if(artist == rhs.artist){
        if(title > rhs.title){
            return true;
        }
        if(title == rhs.title){
            if(size > rhs.size){
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

bool Song::operator ==(const Song &rhs) {
    return (title == rhs.title) && (artist == rhs.artist) && (size == rhs.size);
}

bool Song::operator !=(const Song &rhs) {
    return (title != rhs.title) || (artist != rhs.artist) || (size != rhs.size);
}
