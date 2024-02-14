#include<stdio.h>
/*
COP3223 Spring 2023 Assignment 1.3
Copyright 2023 Kelly Bryce
*/


// DESCRIPTION
// a program that reads in a five digit integer and determines whether or not it’s a palindrome. 




int main(void){

    int number;                             // The number the user inputs as well as the divison math variable

    int math;                               // The variable used to compute remainder operator

    int a,b,c,d,e;                          // The variables assigned to keep the order of numbers from right to left
                                            // "a" = rightmost number from user input, "e" being the left most number from user input

    int check =0;                           // Boolean variable, where "check = 0" means it is palindrome, "check != 0" means false 
    int original;
    
    printf("Please enter a five digit integer: ");
    scanf("%d", &number);
    printf("\n");
   
    // finds the fifth number from input and assigns it to "a"
    original  = number;                     // Keeps track of original input
    math = number;
    math %= 10;
    a = math;
    number /= 10;

    // finds the fourth number from input and assigns it to "b"
    math = number;
    math %= 10;
    b = math;
    number /= 10;

    // finds the third number from input and assigns it to "c"
    math = number;
    math %= 10;
    c = math;
    number /= 10;

    // finds the second number from input and assigns it to "d"
    math = number;
    math %= 10;
    d = math;
    number /= 10;

    // finds the first number from input and assigns it to "e"
    math = number;
    math %= 10;
    e = math;
    number /= 10;

    if (a != e){            // checks to see if last value is equal with first value
        check +=1;
    }
    if (b != d){            // checks to see if second value is equal with fourth value
        check +=1;
    }
    if (check == 0){        // if either "if" statement changed "check" value from 0, then it will not be a palindrome
        printf("%d is a palindrome number\n", original);
    }else{
        printf("%d is not a palindrome number\n", original);
    }



}