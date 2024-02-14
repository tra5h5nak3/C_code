#include<stdio.h>
#include <stdlib.h>
#include <time.h>
/*
COP3223 Spring 2023 Assignment 3.1
Copyright 2023 Kelly Bryce
*/


// DESCRIPTION
// A small airline has just purchased a computer for its new automated reservations system.
// The president has asked you to program the new system. You’ll write a program to assign seats
// on each flight of the airline’s only plane (capacity: 6 seats).






int print_boarding_pass(p){
    if(p == 0 || p == 1 || p == 2){                             // confirms which section is printing
        printf("Your seat is assigned to first class seat %d\n", p+1);  
    }else{
        printf("Your seat is assigned to economy seat %d\n", p+1);
    }
    return 0;

}

int search_seat(int cho, int arr[]){
    int change = 0;                     // this variable changes values if any values were changed on iteration
    int random = 0;                     // holds the value from random library
    int move   = 0;                     // holds the user input if they want to change sections
    int pos2   = 0;                     // holds the position of the seat thats being changed

    if(cho == 1){                       // first class path start
        for(int y = 0; y<40;y++){           
            if(change==0){
                random = rand()% 3;
                if(arr[0]==0 || arr[1]==0|| arr[2]==0){ 
                    if(arr[random]== 0){                // makes sure seat isnt taken
                        change++;                       // records change so multiple changes dont occur
                        pos2 = random;
                        print_boarding_pass(pos2);      // prints boarding pass
                    }
                }
            }
        }
        if(change==0){                                  // if no seats are available, moves to check next section
            if(arr[3]==0 || arr[4]==0||arr[5]==0){      // if next section is full, doesnt ask question
                printf("no seat available in first class, do you want a seat in economy? ");
                scanf("%d",&move);
                if(move==1){
                    for(int z =0; z<40;z++){
                        if(change==0){
                            random = rand()% 3;
                            random+=3;                          // moves random values to 3-5
                            if(arr[3]==0 || arr[4]==0|| arr[5]==0){
                                if(arr[random]== 0){
                                    change++;
                                    pos2 = random;
                                    print_boarding_pass(pos2);
                                }
                            }
                        }
                    }
                }else{
                    printf("Next flight leaves in 3 hours\n");
                }
            }else{
                printf("Next flight leaves in 3 hours\n");
            }
        }
    }else if(cho == 2){                                         // economy class path start
        for(int y = 0; y<40;y++){
            if(change==0){
                random = rand()% 3;
                random+=3;                                  // adds to random number to 3-5
                if(arr[3]==0 || arr[4]==0|| arr[5]==0){     
                    if(arr[random]== 0){                    // confirms that seat isnt taken
                        change++;
                        pos2 = random;
                        print_boarding_pass(pos2);
                    }
                }
            }
        }
        if(change==0){
            if(arr[0]==0 || arr[1]==0||arr[2]==0){              // makes sure there is free space
                printf("no seat available in economy, do you want a seat in first class? ");
                scanf("%d",&move);
                if(move==1){
                    for(int z =0; z<40;z++){
                        if(change==0){
                            random = rand()% 3;                 // outputs numbers 0-2
                            if(arr[0]==0 || arr[1]==0|| arr[2]==0){     // makes sure there is free space again
                                if(arr[random]== 0){
                                    change++;
                                    pos2 = random;                      // assigns new seat to pos2 so
                                    print_boarding_pass(pos2);          // it can be removed from array
                                }
                            }
                        }
                    }
                }else{
                    printf("Next flight leaves in 3 hours\n");
                }
            }else{
                printf("Next flight leaves in 3 hours\n");
            }
        }
    }
    return pos2;
}


int main(void){

    srand(time(NULL));                  // generates random number each runtime
    int seats[] = {0,0,0,
                   0,0,0};
    int endCheck = 0;                   // ends program if user types 1
    int choice   = 0;                   // users choice of plane class
    int pos      = 0;                   // position from "seat_search" fucntion
    do
    {
        printf("Please type 1 for \"first class\"\n");
        printf("Please type 2 for \"economy\"\n");
        scanf("%d",&choice);
        pos = search_seat(choice, seats);
        seats[pos] = 1;
        printf("Does everyone boarded?");
        scanf("%d", &endCheck);
    } while (endCheck != 1);
}