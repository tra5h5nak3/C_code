#include <stdio.h>
/*
COP3223 Spring 2023 Assignment 2.3
Copyright 2023 Kelly Bryce
*/


// DESCRIPTION
// The greatest common divisor of integers x and y is the largest integer that evenly divides 
// both x and y. Write a recursive function gcd that returns the greatest common divisor of x and y.
// The greatest common divisor of x and y is defined recursively as follows: If y is equal to 0, 
// then gcd(x, y) is x; otherwise gcd(x, y) is gcd(y, x % y), where % is the remainder operator.





int gcd(int a, int b){          // function that returns greatest common denominator by
    if(b == 0){                 // doing remainder division on both numbers until one of them
        return a;               // has no remainder or the value "1" is returned
    }else{
        return gcd(b, a%b);
    }
}

int main (void){
    int x,y;
    printf("Please input the first number: ");
    scanf("%d", &x);                            // collects user input for value 2
    printf("Please input the second number: ");
    scanf("%d", &y);                            // collects user input for value 2
    printf("the commom divisor for %d and %d is %d\n", x,y, gcd(x,y));
}
