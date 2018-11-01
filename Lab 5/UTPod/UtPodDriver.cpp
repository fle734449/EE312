/* UtPodDriver.cpp
Demo Driver for the UtPod.
This is a basic driver for the UtPod.
You will want to do more complete testing.

//UtPodDriver.cpp
//
//UT Pod Driver program
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
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    int result;

    //UtPod
    UtPod t(400);
    UtPod s(0);
    UtPod r(-5);
    UtPod q(600);

    //Print inital memory
    cout << "Testing UtPod t in scope:" << endl;
    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;

    cout << "Testing UtPod s out of scope (size = 0):" << endl;
    cout << "UtPod s memory = " << s.getRemainingMemory() << endl << endl;

    cout << "Testing UtPod r in scope (size = -5):" << endl;
    cout << "UtPod r memory = " << r.getRemainingMemory() << endl <<endl;

    cout << "Testing UtPod q in scope (size = 600):" << endl;
    cout << "UtPod q memory = " << q.getRemainingMemory() << endl << endl;

    //Songs
    Song s1("Beatles", "Hey Jude", 8);
    Song s2("Beatles", "Lucy In The Sky", 18);
    Song s3("Beatles", "Yellow Submarine", 90);
    Song s4("Beatles", "Here Comes The Sun", 5);
    Song s5("Beach Boys", "Good Vibrations", 4);
    Song s6("Jimmi Hendrix", "Purple Haze", 7);
    Song s7("Beyonce", "Single Ladies", 9);
    Song s8("Drake", "God's Plan", 50);
    Song s9("Aerosmith", "Dream On", 17);
    Song s10("AC/DC", "Thunderstruck", 30 );
    Song s11("Lionel Richie", "Hello", 3);
    Song s12("Zack", "aaaa", 6);
    Song s13("Topo", "sdfsdf", 1);
    Song s14("Smash Mouth", "All-Star", 82);
    Song s15("", "", 50);
    Song s16("Smash Mouth", "All-Star", 0);
    Song s17("Darude", "Sandstorm", -5);
    Song s18("Beatles", "Hey Jude1", 10);
    Song s19("Beatles", "Hey Jude5", 10);
    Song s20("Beatles", "Hey Jude", 1);

    cout << "All tests are done with UtPod t" << endl << endl;

    //Add Songs, Show memory, Show List
    cout << "Testing addSong (within memory):" << endl;
    result = t.addSong(s1);
    cout << "result = " << result << endl;
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    result = t.addSong(s3);
    cout << "result = " << result << endl;
    result = t.addSong(s4);
    cout << "result = " << result << endl;
    result = t.addSong(s5);
    cout << "result = " << result << endl;
    result = t.addSong(s6);
    cout << "result = " << result << endl;
    result = t.addSong(s7);
    cout << "result = " << result << endl;
    result = t.addSong(s8);
    cout << "result = " << result << endl;
    result = t.addSong(s9);
    cout << "result = " << result << endl;
    result = t.addSong(s10);
    cout << "result = " << result << endl;
    result = t.addSong(s11);
    cout << "result = " << result << endl;
    result = t.addSong(s12);
    cout << "result = " << result << endl;
    result = t.addSong(s13);
    cout << "result = " << result << endl;
    result = t.addSong(s18);
    cout << "result = " << result << endl;
    result = t.addSong(s19);
    cout << "result = " << result << endl;
    result = t.addSong(s8);
    cout << "result = " << result << endl;
    result = t.addSong(s20);
    cout << "result = " << result << endl;
    cout << endl;

    cout << "Testing getRemainingMemory:" << endl;
    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;

    cout << "Testing showSongList:" << endl;
    t.showSongList();
    cout << endl;

    //Adding songs out of scope
    cout << "Testing addSong size is too large:" << endl;
    result = t.addSong(s14);
    cout << "result = " << result << endl << endl;

    cout << "Testing addSong title/artist is blank:" << endl;
    t.addSong(s15);
    cout << endl;

    cout << "Testing addSong size is zero:" << endl;
    t.addSong(s16);
    cout << endl;

    cout << "Testing addSong size is negative:" << endl;
    t.addSong(s17);
    cout << endl;

    //Sort, Shuffle, Shuffle, Shuffle, Sort
    cout << "Testing sortSongList:" << endl;
    t.sortSongList();
    t.showSongList();
    cout << endl;

    cout << "Testing shuffle:" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;

    cout << "Testing shuffle:" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;

    cout << "Testing shuffle:" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;

    cout << "Testing sortSongList:" << endl;
    t.sortSongList();
    t.showSongList();
    cout << endl;

    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;

    //Remove Songs
    cout << "Testing removeSong (s8 = Drake, God's Plan, 50):" << endl;
    result = t.removeSong(s8);
    cout << "result = " << result << endl;
    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;

    cout << "Testing removeSong (s8 = Drake, God's Plan, 50):" << endl;
    result = t.removeSong(s8);
    cout << "result = " << result << endl;
    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;

    cout << "Testing removeSong (s6 = Jimmi Hendrix, Purple Haze, 7):" << endl;
    result = t.removeSong(s6);
    cout << "result = " << result << endl;
    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;

    t.showSongList();
    cout << endl;

    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;

    cout << "Testing removeSong (removing song that's not in the list, s8):" << endl;
    result = t.removeSong(s8);
    cout << "result = " << result << endl;
    t.showSongList();
    cout << endl;
    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;
    cout << endl;

    //Clear Memory
    cout << "Testing clearMemory:" << endl;
    t.clearMemory();
    cout << "Testing getRemainingMemory:" << endl;
    cout << "UtPod t memory = " << t.getRemainingMemory() << endl;
    cout << "Testing showSongList:" << endl;
    t.showSongList();
    cout << endl;

    //Removing song from a empty list
    cout << "Testing removeSong empty list:" << endl;
    result = t.removeSong(s8);
    cout << "result = " << result << endl;
    cout << endl;


    cout << "Retesting addSong (within memory):" << endl;
    result = t.addSong(s1);
    cout << "result = " << result << endl;
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    result = t.addSong(s3);
    cout << "result = " << result << endl;
    result = t.addSong(s4);
    cout << "result = " << result << endl;
    result = t.addSong(s5);
    cout << "result = " << result << endl;
    result = t.addSong(s6);
    cout << "result = " << result << endl;
    result = t.addSong(s7);
    cout << "result = " << result << endl;
    result = t.addSong(s8);
    cout << "result = " << result << endl;
    result = t.addSong(s9);
    cout << "result = " << result << endl;
    result = t.addSong(s10);
    cout << "result = " << result << endl;
    result = t.addSong(s11);
    cout << "result = " << result << endl;
    result = t.addSong(s12);
    cout << "result = " << result << endl;
    result = t.addSong(s13);
    cout << "result = " << result << endl;
    result = t.addSong(s18);
    cout << "result = " << result << endl;
    result = t.addSong(s19);
    cout << "result = " << result << endl;
    result = t.addSong(s8);
    cout << "result = " << result << endl;
    result = t.addSong(s20);
    cout << "result = " << result << endl;
    cout << endl;

    cout << "Retesting getRemainingMemory:" << endl;
    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;

    cout << "Retesting showSongList:" << endl;
    t.showSongList();
    cout << endl;

    //Removal of all songs
    cout << "Testing removeSongs all songs:" << endl;
    result = t.removeSong(s1);
    cout << "result = " << result << endl;
    result = t.removeSong(s2);
    cout << "result = " << result << endl;
    result = t.removeSong(s3);
    cout << "result = " << result << endl;
    result = t.removeSong(s4);
    cout << "result = " << result << endl;
    result = t.removeSong(s5);
    cout << "result = " << result << endl;
    result = t.removeSong(s6);
    cout << "result = " << result << endl;
    result = t.removeSong(s7);
    cout << "result = " << result << endl;
    result = t.removeSong(s8);
    cout << "result = " << result << endl;
    result = t.removeSong(s9);
    cout << "result = " << result << endl;
    result = t.removeSong(s10);
    cout << "result = " << result << endl;
    result = t.removeSong(s11);
    cout << "result = " << result << endl;
    result = t.removeSong(s12);
    cout << "result = " << result << endl;
    result = t.removeSong(s13);
    cout << "result = " << result << endl;
    result = t.removeSong(s18);
    cout << "result = " << result << endl;
    result = t.removeSong(s19);
    cout << "result = " << result << endl;
    result = t.removeSong(s8);
    cout << "result = " << result << endl;
    result = t.removeSong(s20);
    cout << "result = " << result << endl;
    cout << endl;

    cout << "Testing getRemainingMemory:" << endl;
    cout << "UtPod t memory = " << t.getRemainingMemory() << endl << endl;

    cout << "Testing showSongList:" << endl;
    t.showSongList();
    cout << endl;


    return 0;
 }
