#include<stdio.h>
#include<string.h>
/*
COP3223 Spring 2023 Assignment 4.1
Copyright 2023 Kelly Bryce
*/

int main(void){
    struct student {                // structure of all students
        char firstName[25];
        char lastName[25];
        int id;
        char grade[25];
    } class[6]={
        {"John",       "Johnson",    895645, "A"},
        {"Jake",       "Michaelson", 236598, "A"},
        {"Sally",      "Weber",      225584, "C"},
        {"Tou",        "Xiong",      364875, "B"},
        {"Jacquenlyn", "Jackson",    984587, "D"},
        {"John",       "White",      560258, "C"}
    };
    int type=0;                         // value to determine if user is searching by 
                                        // firstname, lastname, or ID number (0,1,2)
    char search[25];                                    
    int  search2;                       // value to search for ID number
    
    printf("Please enter your search type: ");
    scanf("%i", &type);
    
    switch (type)                           // switch statement with three cases
    {
    case 0:
        printf("Please enter the name you want to search: ");       // searching by firstname
        scanf("%s", search);
        for(int x; x <6; x++){
            if(!strcmp(search, class[x].firstName)){            // compare function from ch8
                printf("Find the record name %s %s, id %d, grade %s\n",
                class[x].firstName,
                class[x].lastName,
                class[x].id,
                class[x].grade);
            }
        }
        break;
    case 1:
        printf("Please enter the name you want to search: ");       // searching by lastname
        scanf("%s", search);
        for(int x; x <6; x++){
            if(!strcmp(search, class[x].lastName)){
                printf("Find the record name %s %s, id %d, grade %s\n",
                class[x].firstName,
                class[x].lastName,
                class[x].id,
                class[x].grade);
            }
        }
        break;
    case 2:
        printf("Please enter the number you want to search: ");     // searching by ID number
        scanf("%d", &search2);
        for(int x; x <6; x++){
            if(search2 == class[x].id){
                printf("Find the record name %s %s, id %d, grade %s\n",
                class[x].firstName,
                class[x].lastName,
                class[x].id,
                class[x].grade);
            }
        }
        break;
    default:
        break;
    }
}