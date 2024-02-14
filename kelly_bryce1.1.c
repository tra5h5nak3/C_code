#include<stdio.h>
/*
COP3223 Spring 2023 Assignment 1.1
Copyright 2023 Kelly Bryce
*/

// DESCRIPTION
// a program that inputs three different integers from the keyboard, then displays the sum,
// the average, the product, the smallest and the largest of these numbers. 


int main(void){
    int a;                  // "a" being the first integer inputed
    int b;                  // "b" being the second integer inputed
    int c;                  // "c" being the third integer inputed

    printf("Enter three different integers:   ");  // Gets three inputs from the keyboard
    scanf("%d%d%d", &a, &b, &c );                // Assigns values to variables "a" "b" and "c"

    int sum = a + b +c;     // adds all values together
    int avg = (a+b+c)/3;    // find average of all values
    int pro = a*b*c;        // finds product of all values

    int small =0;
    int large =0;
    if (b <= a)             // Beginning of finding small and large integers
    {
        small = b;
        large = a;
    }
    if (a <= b)
    {
        small = a;
        large =b;
    }
    if (c < small)          // after "a" and "b" have been compared, this will decide if "c" is smaller
    {
        small = c;
    }
    if (c > large)          // after "a" and "b" have been compared, this will decide if "c" is larger
    {
        large = c;
    }
    
    // Prints out all variable values
    printf("\nSum is %d\nAverage is %d\nProduct is %d\nSmallest is %d\nLargest is %d\n", sum, avg, pro, small, large);
}


