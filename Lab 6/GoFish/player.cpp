// FILE:  player.cpp
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks
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

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
#include "player.h"

using namespace std;

//Adds a card to the players hand
//input parameters - Card
//output parameters - none
void Player::addCard(Card c) {
    myHand.push_back(c);
}

//books a pair of cards in the players hand
//input parameters - Card, Card
//output parameters - none
void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);

}

//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
//input parameters - Card, Card
//output parameters - boolean
bool Player::checkHandForBook(Card &c1, Card &c2) {
    if(myHand.size() > 0) {
        for (int j = 0; j < (myHand.size() - 1); j++) {
            for (int k = j + 1; k < myHand.size(); k++) {
                if (myHand[j] == myHand[k]) {
                    c1 = myHand[j];
                    c2 = myHand[k];
                    return true;
                }
            }
        }
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
//input parameters - none
//output parameters - Card
Card Player::chooseCardFromHand() const {
    int randCard = rand() % myHand.size();
    return myHand[randCard];
}

//Does the player have the card c in her hand?
//input parameters - Card
//output parameters - boolean
bool Player::cardInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i] == c){
            return true;
        }
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
//input parameters - Card
//output parameters - Card
Card Player::removeCardFromHand(Card c) {
    Card temp;
    bool cardFound = false;
    int i = 0;
    while(!cardFound) {
        if (myHand[i] == c) {
            temp = myHand[i];
            myHand.erase(myHand.begin()+i);
            cardFound = true;
        }
        i++;
    }
    return temp;
}

//outputs current player's hand of cards
//input parameters - none
//output parameters - String
string Player::showHand() const{
    string hand = "";

    for(int i = 0; i < myHand.size(); i++){
        hand = hand + myHand[i].toString() + " ";
    }
    return hand;
}

//outputs current player's books
//input parameters - none
//output parameters - String
string Player::showBooks() const{
    string books = "";

    for(int i = 0; i < myBook.size(); i++){
        books = books + myBook[i].toString() + " ";
    }
    return books;
}

//returns number of cards in player's hand
//input parameters - none
//output parameters - int
int Player::getHandSize() const{
    int handSize = myHand.size();
    return handSize;
}

//returns number of books player has
//input parameters - none
//output parameters - int
int Player::getBookSize() const{
    int bookSize = myBook.size()/2;
    return bookSize;
}
