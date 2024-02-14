#include<stdio.h>
#include<string.h>
#include <ctype.h>
/*
COP3223 Spring 2023 Assignment 3.3
Copyright 2023 Kelly Bryce
*/

// DESCRIPTION
// Write a C program that inputs a line of text
// use standard input/output library function to get user input
// print it out with uppercase
// reverse the string and print it out
// uses function strtok to count the total number of words. Assume that the words are separated by either spaces.




int main(void){

    char cap[20];                   // array where input is stored and altered from
    int w = 0;                      // interger to keep track of number of words
   
    printf("Please enter a line of text: \n");
    fgets(cap, sizeof(cap), stdin);     // puts all words from input into "cap" array
                                        // despite having whitespace in input

    printf("=====Change the string to upper case=====\n");
    for (int i = 0; cap[i]!='\0'; i++) {        // iterates through every letter and capitalizes it
        cap[i] = toupper(cap[i]);
    }
    printf("%s", cap);                          // prints string after change to uppercase

    printf("=====Reverse string=====");
    for(int x = strlen(cap); x != -1; x-- ){    // starts at the last value and 
        printf("%c", cap[x]);                   // decrements while printing each value
    }
    printf("\n=====Print the tokens=====\n");
    char* ptr = strtok(cap, " ");               // sets a pointer to " " in array "cap"

    while (ptr != NULL) {                       // will continue until no more " "
        printf(" %s\n", ptr);                   // exsist in sentence string
        ptr = strtok(NULL, " ");
        w++;                                    // keeps count of number of words
    }
    printf("There are %d words in the input text\n", w);
}