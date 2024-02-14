#include<stdio.h>
/*
COP3223 Spring 2023 Assignment 2.1
Copyright 2023 Kelly Bryce
*/


// DESCRIPTION
// a program that prints the following diamond shape. Your printf statements may 
// print either one asterisk (*) or one blank. Read an odd number in the range 1 to 19 to 
// specify the number of rows in the diamond. Your program should then display a 
// diamond of the appropriate size. 



int main(void){
    int choice;
    do
    {                                                   // Do while function to check if input is odd and under 19
        printf("please enter number of rows (odd nummber):"); 
        scanf("%d",&choice);
    } while (choice%2 != 1 || choice >19);

    int half = choice / 2;                                 // "half" the sum of user input divided by 2 and rounded down

    int counterVal = half;                                 // counterVal and counter are both used to determine when the diamond should 
    int counter = 0;                                       // start narrowing back out after reaching half length

    for(int i = 0; i < choice; i++){
        for(int firstSpace = 0; firstSpace < half; firstSpace++){   // this loop prints the first set of spaces based on user input
            printf(" ");
        }
        int mathAster1 = half*2;
        int mathAster2 = choice - mathAster1;
        for(int aster = 0; aster < mathAster2; aster++){                     // this loop prints the correct amount of asterisk based
            printf("*");                                                     // on both mathAster variables
        }
        for(int secSpace = 0; secSpace < half; secSpace++){         // this loop prints the end spaces based on user input
            printf(" ");
        }
        if( counter < counterVal){                                  // checks to see if diamond is halfwat complete
            half--;                                                 // if it is, it will start to decrement spaces and increment asterisk
            counter++;
        }else{
            half++;
            counter++;
        }
        printf("\n");                                       // end of the current line
    }
}