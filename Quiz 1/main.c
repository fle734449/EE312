#include <stdio.h>
#include <stdlib.h>

int main(){

    //Step1: Read the N
    int num;
    scanf("%d", &num);
    //Step2: Allocate space for N integers
    int* ptr = (int *)malloc(sizeof(int)*num);
    //Step3: Read N pairs of Integers and store each sum in space allocated
    int num1,num2;
    int* fptr = ptr;
    for(int i = 0;i<num;i++){
        scanf("%d %d", &num1, &num2);
        int sum = num1 + num2;
        *fptr = sum;
        fptr++;
    }

    //Step4: Display the sums.
    for (int i = 0;i<num;i++){
        printf("%d\n", *ptr);
        ptr++;
    }
}