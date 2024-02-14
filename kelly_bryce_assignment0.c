#include <stdio.h>
#include <string.h>
int main(void){
    
    char message1[100050];
    char message2[100050];
    int count = -1;             // starting at -1 since for loop accounts for same null character

    int compare;                    // value to hold result of strcmp function

    int pass;                   // bool used to stop multiple letters from being selected from one letter
    
    
    fgets(message1, sizeof(message1), stdin);
    fgets(message2, sizeof(message2), stdin);


    int message2Length = strlen(message2) -1; // Length of message 2 without null character
    for(int s = 0; s < message2Length; s++){
        if(message2[s] == ' '){                // counts number of whitespaces in the second message so
            count++;                           // that the whitespaces dont get counted for the final total
        }
    }  


    for (int i = 0; message1[i]!='\0'; i++) {   // for loop that iterates through all characters

        pass = 0;                               // value will reset to 0 for next letter iteration
        for (int j = 0; message2[j]!= '\0'; j++){
            if(message1[i] != ' '){
                if(pass == 0){
                    compare = strncmp(&message1[i], &message2[j],1);
                    if (compare == 0){
                        count++;                // keeps track of amount of duplicate characters

                        message2[j] = '0';      // replaces letter to not double count letters

                        pass++;                 // value will change if a letter has been altered on current iteration
                    }
                }
            }  
        }  
    }
    printf("%d", message2Length - count);
    return(0);
    
}