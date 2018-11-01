#include<stdio.h>
#include<stdbool.h>
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int, int);
int reverseInt(int);

// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 *
 * Name: Frank Le
 * email address: frank.le@utexas.edu
 * UTEID: fpl227
 * Section 5 digit ID: 16185
 *
 */

int main() {

    // test 1, hammingDistance
    int h1[] = {1, 2, 3, 4, 5, 4, 0, 2, 1};
    int h2[] = {1, 2, 10, 4, 6, 4, 3, -10, 1};
    int expected = 4;
    int actual = hammingDistance(h1, h2, 9);
    printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 1, hamming distance\n\n");
    else printf("**** FAILED **** test 1, hamming distance\n\n");

    // test 2, hamming distance
    int h3[] = {1, 2, -6, 4, 5, 6, 7, 0, 9, 10};
    int h4[] = {-6, -6, -6, -6, -6, -6, -6, -6, -6, -6};
    expected = 9;
    actual = hammingDistance(h3, h4, 10);
    printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 2, hamming distance\n\n");
    else printf("**** FAILED **** test 2, hamming distance\n\n");

    // test 3, hamming distance
    int h5[100000] = {0};
    int h6[100000] = {0};
    expected = 0;
    actual = hammingDistance(h5, h6, 100000);
    printf("Test 3 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 3, hamming distance\n\n");
    else printf("**** FAILED **** test 3, hamming distance\n\n");

    // test 4, last digit
    int n1 = -10001;
    int n2 = 101;
    expected = true;
    actual = lastDigit(n1, n2);
    printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 4, last digit\n\n");
    else printf("**** FAILED **** test 4, last digit\n\n");

    // test 5, last digit
    n1 = -36;
    n2 = -1936;
    expected = true;
    actual = lastDigit(n1, n2);
    printf("Test 5 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 5, last digit\n\n");
    else printf("**** FAILED **** test 5, last digit\n\n");

    // test 6, last digit
    n1 = -12;
    n2 = -9021;
    expected = false;
    actual = lastDigit(n1, n2);
    printf("Test 6 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 6, last digit\n\n");
    else printf("**** FAILED **** test 6, last digit\n\n");

    // test 7, last digit
    n1 = -202;
    n2 = 201;
    expected = false;
    actual = lastDigit(n1, n2);
    printf("Test 7 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 7, last digit\n\n");
    else printf("**** FAILED **** test 7, last digit\n\n");

    // test 8, sum of multiples of 3 or 5
    expected = 233168;
    actual = sum3or5Multiples();
    printf("Test 8 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 8, sum of multiples of 3 or 5\n\n");
    else printf("**** FAILED **** test 8, sum of multiples of 3 or 5\n\n");

    // test 9, reverse int
    n1 = -687;
    expected = -786;
    actual = reverseInt(n1);
    printf("Test 9 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 9, reverse int\n\n");
    else printf("**** FAILED **** test 9, reverse int\n\n");

    // test 10, reverse int
    n1 = -2147483648;
    expected = 0;
    actual = reverseInt(n1);
    printf("Test 10 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 10, reverse int\n\n");
    else printf("**** FAILED **** test 10, reverse int\n\n");

    // test 11, reverse int
    n1 = 2147483647;
    expected = 0;
    actual = reverseInt(n1);
    printf("Test 11 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 11, reverse int\n\n");
    else printf("**** FAILED **** test 11, reverse int\n\n");

    // test 12, reverse int
    n1 = 100;
    expected = 1;
    actual = reverseInt(n1);
    printf("Test 12 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 12, reverse int\n\n");
    else printf("**** FAILED **** test 12, reverse int\n\n");

    // test 13, reverse int
    n1 = -002;
    expected = -2;
    actual = reverseInt(n1);
    printf("Test 13 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 13, reverse int\n\n");
    else printf("**** FAILED **** test 13, reverse int\n\n");

    // test 14, reverse int
    n1 = 0;
    expected = 0;
    actual = reverseInt(n1);
    printf("Test 14 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 14, reverse int\n\n");
    else printf("**** FAILED **** test 14, reverse int\n\n");

    // test 15, reverse int
    n1 = -2063847412;
    expected = -2147483602;
    actual = reverseInt(n1);
    printf("Test 15 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)  printf("passed test 15, reverse int\n\n");
    else printf("**** FAILED **** test 15, reverse int\n\n");
}

