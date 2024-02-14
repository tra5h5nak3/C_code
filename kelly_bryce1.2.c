#include <stdio.h>
/*
COP3223 Spring 2023 Assignment 1.2
Copyright 2023 Kelly Bryce
*/

// DESCRIPTION
// a program that will determine the gross pay for each of several employees. 
// The company pays “straight time” for the first 40 hours worked by each employee and 
// pays “time-and-a-half” for all hours worked in excess of 40 hours. You’re given a list
// of the company’s employees, the number of hours each worked last week and each 
// employee’s hourly rate. Your program should use scanf to input this information for each 
// employee and determine and display the employee’s gross pay.



int main(void){
    int hours;                  // number of hours worked
    float rate;                 // the hourly rate of the worker
    float sal;                  // the end salary 

    do
    {
        printf("Enter # of hours worked (-1 to end):  ");
        scanf("%d", &hours);
        if (hours == -1){           // if input is "-1" then the program ends
            break;
        }

        printf("Enter hourly rate of the worker ($00.00):  ");
        scanf("%f", &rate);

        if (hours > 40){                // if hours exceed 40, finds how many hours over 40 
            hours -= 40;                // and multiplies it by “time-and-a-half” rate 
            rate = 1.5*rate;            
            sal = (rate*hours)+400;     // adds back the 40 hours taken from line 23 by adding 400$ to salary

        }else{                          // normal salary rate when hours are less than or equal to 40
            sal = rate*hours;
        }
        printf("Salary is $%.2f\n", sal);
    } while (hours != -1);
}