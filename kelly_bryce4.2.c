#include<stdio.h>
/*
COP3223 Spring 2023 Assignment 4.2
Copyright 2023 Kelly Bryce
*/
int main(void){
    int start;          // user input of fahrenheit
    float fin;          // end result of celsius
    printf("Please enter a temperature in Fahrenheit: ");
    scanf("%d",&start);

    fin = 5.0 / 9.0 *(start-32);        // calculates celsius from input
    printf("Fahrenheit\tCelsius\n");
    if(fin < 0){                        // if output is positive, it places a positive sign
        printf("%d \t\t%.3f", start,fin);
    }else{
        printf("%d \t\t+%.3f", start,fin);
    }
}