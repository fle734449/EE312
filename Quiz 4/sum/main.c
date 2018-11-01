#include <stdio.h>

//Write recursive function sum which adds up the first n numbers recursively

int sum(int n){
    if(n==0){
        return 0;
    } else {
        n = n + sum(n-1);
    }
    return n;
}

int main() {
    printf("Enter Number \n");
    int number;
    scanf("%d",&number);
    int result = sum(number);
    printf("Sum of first %d numbers is : %d",number,result);
    return 0;
}