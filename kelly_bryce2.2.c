#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
COP3223 Spring 2023 Assignment 2.2
Copyright 2023 Kelly Bryce
*/


// DESCRIPTION
// Guess the Number game that has three levels of difficulty. The first level of difficulty
// would be a number between 1 and 10. The second difficulty set would be between 1 and 100. 
// The third difficulty set would be between 1 and 1000.
// Prompt for the difficulty level, and then start the game. The computer picks a random number
// in that range and prompts the player to guess that number. Each time the player guesses,
// the computer should give the player a hint as to whether the number is too high or too low. 
// The computer should also keep track of the number of guesses. if the number of guesses is 
// larger than 8, the computer will end the game and prompt "Better luck next time". Once the 
// player guesses the correct number, the computer should present the number of guesses and ask
// if the player would like to play again. (1 for yes or 0 for no)


void guess_number(int);

int random_number_gen(int level){       // this function takes input of 1,2, or 3 and
    int x;                              // returns a number from corresponding difficulty
    switch (level)                      // Switch Structure
    {
    case 1:
        x = rand()% 11;                 // difficulty 1
        return x;
        break;
    case 2:
        x = rand()% 101;                // difficulty 2
        return x;
        break;
    case 3:
        x = rand()% 1001;               // difficulty 3
        return x;
        break;
    default:
        return 0;
        break;
    }
}


void guess_number(int ans){                     // this function allows 8 guess and prints
    int guess;                              // corresponding text with outcomes
    int tries = 0;
    printf("\nI have my number. What's your guess? ");
    for(int i = 0; i<8; i++){               // only runs 8 times, so 8 guesses maximun
        scanf("%d",&guess);
        tries++;
        if(guess == ans){
            printf("You got it in %d guesses!", tries);
            break;
        }
        if (tries<8){
            if(guess > ans){
                printf("Too high. Guess again: ");
            }else{
                printf("Too low. Guess again: ");
            }
        }else{
            printf("Better luck next time");
        }
    }
}


int main (void) {
    int playAgain, diff, key;
    do                                              // Do While Structure
    {
        printf("Let's play Guess the Number\n");
        printf("Pick a difficulty level (1,2,3): ");
        scanf("%d", &diff);
        key = random_number_gen(diff);              // assigns return value to "key"
        guess_number(key);                          // which is the random number
        printf("\nYour number was %d",key);

        printf("\nPlay again? (1 for yes or 0 for no) ");
        scanf("%d", &playAgain);
    } while (playAgain != 0);                       // allows for replay when user types 1
}