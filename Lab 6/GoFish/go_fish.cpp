// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
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
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

//Function dealHand deals seven cards at the start of the game to both players
//input parameters - Deck, Player, int
//output parameters - none
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

//Function gameOver checks to see if 26 books are present
//input parameters - Player, Player
//output parameters - boolean value
bool gameOver(Player &p1, Player &p2) {
    if ((p1.getBookSize() + p2.getBookSize()) >= 26) {
        return true;
    } else {
        return false;
    }
}

//Function Turn runs through a players turn
//This includes booking all pairs in their hand, asking for a card, booking it, and continuing
//or having the other player say Go Fish, drawing a card and ending their turn
//input parameters - Player, Player, Deck
//output parameters - none
void Turn(Player &turnPlayer, Player &otherPlayer, Deck &deck, ofstream &myfile) {
    cout << endl;
    myfile << endl;
    Card c1;
    Card c2;
    int num;

    //checks initial hand to book any pairs in hand
    while (turnPlayer.checkHandForBook(c1, c2)) {
        turnPlayer.removeCardFromHand(c1);
        turnPlayer.removeCardFromHand(c2);
        turnPlayer.bookCards(c1, c2);
        cout << turnPlayer.getName() << " books the " << c1.toString() << " " << c2.toString() << endl;
        myfile << turnPlayer.getName() << " books the " << c1.toString() << " " << c2.toString() << endl;
    }

    while (otherPlayer.checkHandForBook(c1, c2)) {
        otherPlayer.removeCardFromHand(c1);
        otherPlayer.removeCardFromHand(c2);
        otherPlayer.bookCards(c1, c2);
        cout << otherPlayer.getName() << " books the " << c1.toString() << " " << c2.toString() << endl;
        myfile << otherPlayer.getName() << " books the " << c1.toString() << " " << c2.toString() << endl;
    }

    cout << endl;
    myfile << endl;

    //check to see if the game is over
    if(gameOver(turnPlayer, otherPlayer)){
        return;
    }

    //only take a turn if you have cards in your hand otherwise, draw a card and end your turn
    if (turnPlayer.getHandSize() > 0) {
        bool goFish = false;

        while (!goFish) {
            if(turnPlayer.getHandSize() > 0) {
                Card askCard = turnPlayer.chooseCardFromHand();
                int rank = askCard.getRank();
                cout << turnPlayer.getName() << " asks - Do you have a " << askCard.rankString(rank) << endl;
                myfile << turnPlayer.getName() << " asks - Do you have a " << askCard.rankString(rank) << endl;

                if (otherPlayer.cardInHand(askCard)) {
                    cout << otherPlayer.getName() << " says - Yes. I have a " << askCard.rankString(rank) << endl;
                    myfile << otherPlayer.getName() << " says - Yes. I have a " << askCard.rankString(rank) << endl;
                    turnPlayer.addCard(otherPlayer.removeCardFromHand(askCard));

                    while (turnPlayer.checkHandForBook(c1, c2)) {
                        turnPlayer.removeCardFromHand(c1);
                        turnPlayer.removeCardFromHand(c2);
                        turnPlayer.bookCards(c1, c2);
                        cout << turnPlayer.getName() << " books the " << c1.toString() << " " << c2.toString() << endl;
                        myfile << turnPlayer.getName() << " books the " << c1.toString() << " " << c2.toString() << endl;
                    }

                    if (gameOver(turnPlayer, otherPlayer)) {
                        return;
                    }
                } else {
                    cout << otherPlayer.getName() << " says - Go Fish" << endl;
                    myfile << otherPlayer.getName() << " says - Go Fish" << endl;
                    goFish = true;
                }
            } else {
                goFish = true;
            }
        }
    }

    //Only deal a card from a deck with cards
    if(deck.size() > 0){
        Card newCard = deck.dealCard();
        cout << turnPlayer.getName() << " draws " << newCard << endl;
        myfile << turnPlayer.getName() << " draws " << newCard << endl;
        turnPlayer.addCard(newCard);

        while (turnPlayer.checkHandForBook(c1, c2)) {
            turnPlayer.removeCardFromHand(c1);
            turnPlayer.removeCardFromHand(c2);
            turnPlayer.bookCards(c1, c2);
            cout << turnPlayer.getName() << " books the " << c1.toString() << " " << c2.toString() << endl;
            myfile << turnPlayer.getName() << " books the " << c1.toString() << " " << c2.toString() << endl;
        }

    } else {
        cout << "Deck is empty!" << endl << endl;
        myfile << "Deck is empty!" << endl << endl;
    }
    cout << endl;
    myfile << endl;
}

//Go Fish Game
int main(){
        ofstream myfile("gofish_results.txt");
        if (myfile.is_open()) {
            int numCards = 7;

            Deck d;
            d.shuffle();

            Player p1("Frank");
            Player p2("Andy");

            dealHand(d, p1, numCards);
            dealHand(d, p2, numCards);

            cout << p1.getName() << "'s Hand: " << p1.showHand() << endl;
            cout << p2.getName() << "'s Hand: " << p2.showHand() << endl;
            myfile << p1.getName() << "'s Hand: " << p1.showHand() << endl;
            myfile << p2.getName() << "'s Hand: " << p2.showHand() << endl;

            while (!gameOver(p1, p2)) {
                Turn(p1, p2, d, myfile);
                cout << p1.getName() << "'s Hand: " << p1.showHand() << endl;
                cout << p2.getName() << "'s Hand: " << p2.showHand() << endl;
                myfile << p1.getName() << "'s Hand: " << p1.showHand() << endl;
                myfile << p2.getName() << "'s Hand: " << p2.showHand() << endl;
                Turn(p2, p1, d, myfile);
                cout << p1.getName() << "'s Hand: " << p1.showHand() << endl;
                cout << p2.getName() << "'s Hand: " << p2.showHand() << endl;
                myfile << p1.getName() << "'s Hand: " << p1.showHand() << endl;
                myfile << p2.getName() << "'s Hand: " << p2.showHand() << endl;
            }
            if (p1.getBookSize() > p2.getBookSize()) {
                cout << p1.getName() << "'s Books: " << p1.showBooks() << endl;
                cout << p2.getName() << "'s Books: " << p2.showBooks() << endl;
                cout << p1.getName() << " wins!" << endl;
                myfile << p1.getName() << "'s Books: " << p1.showBooks() << endl;
                myfile << p2.getName() << "'s Books: " << p2.showBooks() << endl;
                myfile << p1.getName() << " wins!" << endl;
                myfile.close();
            } else if (p1.getBookSize() < p2.getBookSize()) {
                cout << p1.getName() << "'s Books: " << p1.showBooks() << endl;
                cout << p2.getName() << "'s Books: " << p2.showBooks() << endl;
                cout << p2.getName() << " wins!" << endl;
                myfile << p1.getName() << "'s Books: " << p1.showBooks() << endl;
                myfile << p2.getName() << "'s Books: " << p2.showBooks() << endl;
                myfile << p2.getName() << " wins!" << endl;
                myfile.close();
            } else {
                cout << p1.getName() << "'s Books: " << p1.showBooks() << endl;
                cout << p2.getName() << "'s Books: " << p2.showBooks() << endl;
                cout << p1.getName() << " and " << p2.getName() << " tied!" << endl;
                myfile << p1.getName() << "'s Books: " << p1.showBooks() << endl;
                myfile << p2.getName() << "'s Books: " << p2.showBooks() << endl;
                myfile << p1.getName() << " and " << p2.getName() << " tied!" << endl;
                myfile.close();
            }
        }
    return EXIT_SUCCESS;
}
