#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

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
 * Section 5 digit ID: 16185
 *
 */



/* Name: Frank Le
 * Date: 9/5/18
 * Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/
int hammingDistance(int aList[], int bList[], int len) {
    int diff = 0;                                   //difference of an int in A and an int in B
    int hamDist = 0;                                //Holds the Hamming Distance
        for(int i = 0;i < len; i++){
            diff = aList[i] - bList[i];
                if(diff != 0){
                    hamDist = hamDist+1;            //if the difference of the ints = 0, add 1 to the Hamming Distance
                } else {
                    hamDist = hamDist+0 ;           //otherwise don't add
                }
        }
    return hamDist;                                 //returns the Hamming Distance

}

/* Name: Frank Le
 * Date: 9/5/18
 * Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2.
   post: return true if x and y have the same last digit, false otherwise.
*/
bool lastDigit(int x, int y) {
    x = x%10;                                       //mods integer x by 10 to get the last digit
        if(x < 0){                                  //if the integer is negative, makes it positive
            x = x*(-1);
        }
    y = y%10;                                       //mods integer y by 10 to get last digit
        if(y < 0){                                  //if the integer is negative, make it positive
            y = y*(-1);
        }
    if(x-y != 0){                                   //if the difference of x and y does not equal zero they do not have the same last digit
        return false;
    } else {
        return true;                                //they have the same last digit if x - y = 0
    }
}

/* Name: Frank Le
 * Date: 9/5/18
 * Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/
int sum3or5Multiples() {
    int sum = 0;
        for(int i = 0; i < 1000; i++){                  //indexas through integers 0 - 1000
            if((i/3)*3 == i){                           //if the integer divided by 3 and multiplied by 3 equals the integer then it is divisible by 3
                sum = sum+i;                            //adds the integer to the sum
            } else if((i/5)*5 == i){                    //repeats the process for the integer 5 if the case for 3 fails
                sum = sum+i;
            }
        }
    return sum;

}

/* Name: Frank Le
 * Date: 9/6/18
 * Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return x with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/
int reverseInt(int x) {
    int revX = 0;
        if(x>0) {                                       //if the integer is positive
            while(x > 0) {                              //reversed integer is equal to the integer modded by 10 summed with the reversed integer
                revX = x%10 + revX*10;                  //multiplied by 10
                x = x/10;                               //the integer is divided by 10 in order to get rid of the last digit
                if(revX < 0){                           //if the integer became negative, an overflow occurred, revX is out of int range
                    return 0;
                }
            }
        } else if(x<0){                                 //if the integer is negative
            while(x < 0) {                              //repeat steps above
                revX = x%10 + revX*10;
                x = x/10;
                if(revX > 0){                           //if the integer became positive, an underflow occurred, revX is out of int range
                    return 0;
                }
            }
        }
    return revX;                                        //returns the reversed integer
}
