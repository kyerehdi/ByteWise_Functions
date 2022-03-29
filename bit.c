#include "p1-support.h"
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
//
// File           : p1-support.c
// Description    : This is a set of general-purpose utility functions
//                  we use for the 257 project #1.
// Author         : ***Derrick Kyereh ***
// Date           : ***3/3/2021***
// Notes          :


////////////////////////////////////////////////////////////////////////
// Function Definitions
////////////////////////////////////////////////////////////////////////

//Function definitions as decribed in the project manual

//This function prints out the array of integer values
void display_array(unsigned int* arr, int size){
    int i;
    printf("{");
    for(i = 0;i<size;i++){
        printf("%4d%s",arr[i],(i==9)?"":",");
    }
    printf("}\n");

}


//Additional function definitions for helper functions
//Shortly describe each function above the function definition.

//finds the biggest number and adds 1 to the biggest number until the smallest number = 0.
int bitwise_add(int num1, int num2)
{
//complete the definition
    if(num2==0)
        return num1;
    if(num1==0)
        return num2;

    else
    {
        if(num1<num2 || num1==num2) {
            while (num2 > 0) {
                num1++;
                num2--;
            }
            return num1;
        }
        else {
            if (num2 < num1) {
                while (num1 > 0) {
                    num2++;
                    num1--;
                }
                return num2;

            }
        }

    }
}

//gets the binary number of num1 then shift to what ever integer num2 is.
int bitwise_shift_left(int num1, int num2)
{
    int k;

    k= num1<<num2;
    return k;
}

//counts checks if num is greather than zero, then checks if the right most digit =1. if it does the count increases.
int count_set_bits(int num){
    int k=0;
    while (num> 0){
        if(num & 1 ==1) {
            k++;
        }
        num = num >>1;
    }
    return k;
}


void binary_string(unsigned int num, char str[BUFSZ]) {


    str[0] = '0';
    str[1] = 'b';
    str[34] = '\0';

    int i = 33;
    while (i > 1) {
        char j;
        if (num & 1 == 1)
            str[i] = '1';

        else {
            str[i] = '0';
        }
        num = num >> 1;
        i--;

    }

}

//using & fuction with 31 gets you a number module 32.
int bitwise_mod32(int num){
    if (num <0){
        return 0;
    }

    return num & 31;
}

//if number is larger than 0 or equal to 0, returns that number, else it flips the binary numbers, and adds one, then returns that number.
int bitwise_abs(int num){
    if(num >=0){
        return num;
    }
    else {
        int f;
        f=~num;
        int r;
        r= bitwise_add(f,1);
        return r;
    }

}

//basically shifts to what ever index/offset number your looking for through the >> operator to get the right most number your looking for.
int bit_get(int num,int offset){

    if(offset ==0){
        return num & 1;
    }
    else {

        int k= num>>(offset);
        return k &1;
    }
}

// if a number at the first index from the right most, is 1 the number is negative and will return a 1, else it will return a 0
int odd_or_even(unsigned int num){

    return (num &1);
}

//swaps digits
void swap_ints(int *a,int *b){

    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
