// FILE: deck.cpp
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
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


#include "card.h"
#include "deck.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

//Constuctor
Deck::Deck() {
    myIndex = 0;
    int index = 0;
    unsigned int currentTime1 = (unsigned) time(0);
    srand(currentTime1);
    for(int numSuit = 0; numSuit < 4; numSuit++){
        for(int numRank = 0; numRank < 13; numRank++){
            Card::Suit suit = (Card::Suit)numSuit;
            index = (numSuit*13) + numRank;
            myCards[index] = Card(numRank+1, suit);
        }
    }
}

//shuffles the deck
//input parameters - none
//output parameters - none
void Deck::shuffle() {
    myIndex = 0;
    int randCard;
    Card temp;

    for(int i = 0; i < SIZE; i++){
        randCard = rand() % SIZE;
        temp = myCards[i];
        myCards[i] = myCards[randCard];
        myCards[randCard] = temp;
    }
}

//Deals one card from the deck
//input parameters - none
//output parameters - Card
//precondition: cannot be an empty deck
Card Deck::dealCard() {
    Card top = myCards[myIndex];
    myIndex = myIndex + 1;
    return top;
}

//returns the remaining  umber of cards in the deck
//input parameters - none
//output parameters - int
int Deck::size() const {
    int rem = SIZE - myIndex;
    return rem;
}