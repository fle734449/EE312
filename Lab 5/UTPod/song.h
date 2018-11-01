/* song.h

//song.h
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

#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song {
    private:
        string artist;
        string title;
        int size;

    public:
        //Constructors
        Song();
        Song(string artist, string title, int size);

        //Destructor
        ~Song() {};

        //set variables
        void setArtist(string a)
        {
            artist = a;
        }
        void setTitle(string t)
        {
            title = t;
        }
        void setSize(int s)
        {
            size = s;
        }

        //get variables
        string getArtist() const
        {
            return artist;
        }
        string getTitle() const
        {
            return title;
        }
        int getSize() const
        {
            return size;
        }

        //Overload
        bool operator >(const Song &rhs);
        bool operator <(const Song &rhs);
        bool operator ==(const Song &rhs);
        bool operator !=(const Song &rhs);
};

#endif