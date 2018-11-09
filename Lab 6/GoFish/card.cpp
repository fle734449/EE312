#include <iostream>
#include <string>
#include "string.h"
#include <cstring>
#include "card.h"


//File Name: card.cpp
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13
/*
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
* Date: 11/6/18
*
*/


using namespace std;

//Default Constructor
Card::Card() {}

//Constructor
Card::Card(int rank, Suit s)
     : myRank(rank), mySuit(s) {}

//Converts Card to a string
// input parameters - none
//output parameters - string
    string Card::toString() const {
        return rankString(myRank) + suitString(mySuit);
    }

//checks to see if two cards have the same suit
//input parameters - Card
//output parameters - boolean
    bool Card::sameSuitAs(const Card &c) const {
        return mySuit == c.mySuit;
    }

//returns the suit of a card
//input parameters - Suit
//output parameters - Suit
    int Card::getRank() const {
        return myRank;
    }

    //returns the suit of a card
    //input parameters - Suit
    //output parameters - String
    string Card::suitString(Suit s) const {
        string suitStr = "";

        switch(s) {
            case spades: suitStr = "s";
                break;
            case hearts: suitStr = "h";
                break;
            case diamonds: suitStr = "d";
                break;
            case clubs: suitStr = "c";
                break;
        };
        return suitStr;
    }

    //returns the rank of a Card
    //input parameters - int
    //output parameters - String
    string Card::rankString(int r) const {
        string rankStr = "";
        long long int s = myRank;

        switch(r) {
            case 1: rankStr = "A";
                break;
            default: rankStr = to_string(s);
                break;
            case 11: rankStr = "J";
                break;
            case 12: rankStr = "Q";
                break;
            case 13: rankStr = "K";
                break;
        };
        return rankStr;
    }

    //Overloads
    bool Card::operator==(const Card &rhs) const {
        return this->getRank() == rhs.getRank();
     }

     bool Card::operator!=(const Card &rhs) const {
         return this->getRank() != rhs.getRank();
     }

    ostream& operator << (ostream& out, const Card& c){
        return out << c.toString();
     }
