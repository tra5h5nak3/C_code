#include <stdio.h>
#include <stdlib.h>
/*
COP3223 Spring 2023 Assignment 3.2
Copyright 2023 Kelly Bryce
*/



// DESCRIPTION
// write a C program to create a dynamic array. The program should do following:
// ask user to input the size of the array and create a dynamic array
// ask user to input the numbers to initialize the array
// the program asks user to input the search number and check if the number is in the array.






int *int_array(siz){
    int *ptr;                           
    ptr = (int*)malloc(siz * sizeof(int));          // assigns ptr to first block of memory in array
    return ptr;
}

void search_array(search, fv, size){
    for(int n = 0; n<size; n++){                    // goes through each item in array and compares it with the value in "search"
        if(search == fv){
            printf("Find number %d in array[%d]\n", search, n);
        }
        fv++;
    }
}

int main (void){
    int size;
    int x;              // variable to store array elements from user input
    int *fv;            // stands for "first variable"
    int search;
    printf("Please enter the size of the array: ");
    scanf("%d",&size);
    fv = int_array(size);               
    
    for(int i = 0; i < size; i++){
        printf("Please enter the array element: ");     // takes user input and adds them to the array
        scanf("%d",&x);
        *fv = x; 
        fv++;                                   // increment to go to the next memory slot
    }
    for(int j = 0; j<size; j++){
        fv--;                       // brings the pointer back down to first index number
    }
    for(int z = 0; z<size; z++){
        printf("element %d = %i\n", z,*fv);     // prints out all elements of array
        fv++;
    }
    for(int y = 0; y<size; y++){    // prepares pointer for number search fucntion
        fv--;
    }
    printf("What number your want to check: ");     
    scanf("%d", &search);
    search_array(search, *fv, size);
}