/* mathStuff.c

Roger Priebe and Frank Le
cs1428 10/15/2007 (updated 3/24/09)
EE312  10/3/2018

Finish comments here
//
//mathStuff program
//Roger Priebe
//EE 312
Student information for project:
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
* Date: 10/16/18
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//
bool isPrime (int number);



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.
void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)
int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
void findFactors (int number);


//function isPrime_helper
//input parameter - postive integer, positive integer
//returns true if the number is prime, otherwise false
//
bool isPrime_helper(int num, int i);


//function findFactors_helper
//input parameter - positive integer, positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
//
void findFactors_helper (int num, int i);


//******************  MAIN  *****************************

int main () {

    int testNum;

    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);
    //testNum = 199;
    if (isPrime(testNum)) {
        printf("%d is prime.\n", testNum);
    }
    else {
        printf("%d is not prime.\n", testNum);
    }

    printf("\n");

    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);
    //testNum = 52;
    printPrimes(testNum);

    printf("\n");

    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);
    //testNum = 28;
    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum));
    printf("\n");

    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);
    //testNum = 63;
    findFactors(testNum);

    return 0;
}


//**********  Functions  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//
bool isPrime (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
    return isPrime_helper(number, number/START_DIVISOR);
}


//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.
//
void printPrimes (int n) {
    if(n==1){
        return;
    }
    printPrimes(n-1);
    if(isPrime(n)){
        printf("%d\n", n);
    }
}


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)
//
int findFibo (int n) {
    if(n==0){
        return 0;
    } else if(n==1){
        return 1;
    } else {
        return(findFibo(n-2) + findFibo(n-1));
    }
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
//
void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
    printf("%d = ", number);
    printf("%d", 1);
    return findFactors_helper(number, START_DIVISOR);
}


//function isPrime_helper
//input parameter - postive integer, positive integer
//returns true if the number is prime, otherwise false
//
bool isPrime_helper(int num, int i){
    if(num == 1){
        return false;
    } else if(i == 1){
        return true;
    } else {
        if(num % i == 0){
            return false;
        } else {
            return isPrime_helper(num, i-1);
        }
    }
}


//function findFactors_helper
//input parameter - positive integer, positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
//
void findFactors_helper (int num, int i){
    if (num == 1){
        return;
    } else if(num % i == 0) {
        printf("*%d", i);
        num = num / i;
        return findFactors_helper(num, i);
    }
    return findFactors_helper(num, i+1);
}