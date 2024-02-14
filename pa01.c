#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/*=============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Hill cipher
|
| Author: Bryce Kelly
| Language: c
|
| To Compile: 
| gcc -o pa01 pa01.c
| 
| 
|
| To Execute:
|
| or c -> ./pa01 kX.txt pX.txt
| 
| 
| 
| 
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Summer 2023
| Instructor: McAlpin
| Due Date: 6/23/2023
|
+=============================================================================*/

int main(int argc, char **argv) {

    //printf( "\ncommand line arguments including program name:\n\n");
    int i;
    for ( i = 0; i < argc; i++ ) {
        //printf( "argument %d: %s\n", i, argv[ i ] );
    }
    printf( "\n");

    char* kfile = argv[ 1 ];
    FILE *fptr1 ;
    fptr1 = fopen( kfile, "r" );
    if ( fptr1 == 0 )
    {
        printf( "Could not open file\n" );
    } else {
        //printf( "File 1 opened successfully\n" );
    
    }

    char* pfile = argv[ 2 ];
    FILE *fptr2;
    fptr2 = fopen( pfile, "r" );
    if ( fptr2 == 0 )
    {
        printf( "Could not open file\n" );
    } else {
        //printf( "File 2 opened successfully\n" );
        
    }
    int count = argc;
    //printf("\nArgument Count: %d\n", argc);

    char plaintext[10000];
    char plaintext1[10000];    // plaintext lowered
    char plaintext2[10000];     // plaintext alphaed
    int plaintext3[10000];
    int y = 0;
    int y3 = 0;
    //printf("PLAINTEXT: ");
    while(fgets(plaintext, 10000, fptr2)){
        //printf("%s", plaintext);
        for (int i = 0; i< strlen(plaintext); i++){
            plaintext1[y3]= tolower(plaintext[i]);
            y3++;
        }
    }
    
    for(int x = 0; x <strlen(plaintext1); x++){  
        if(isalpha(plaintext1[x])){
            plaintext2[y]= plaintext1[x];
            y++;
        }else{
        }  
    }
    //printf("\nPLAINTEXT2:%s\n", plaintext2);
    //printf("\nPLAINTEXT3:");
    for (int m = 0; m<strlen(plaintext2); m++){
        plaintext3[m]= plaintext2[m] -97;
        //printf(" %d ", plaintext3[m]);
    }
    //printf(" \nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");


    char cipher[10000];
    char cipher1[10000];
    int y2;
    int cipher2[10000];
    int blocksize;
    int format =0;
    printf("\nKey matrix: \n");
    while(fgets(cipher, 10000, fptr1)){
        if(format != 0){
            printf("    %s", cipher);
        }
        for (int u = 0; u<strlen(cipher); u++){
            if(isdigit(cipher[u])){
                cipher1[y2] = cipher[u];
                cipher2[y2] = cipher1[y2];
                y2++;
            }else{
            }
        }  
        format++;
    }
    //printf("\nCIPHER1: %s\n", cipher1);
    //printf("\n CHECK ---> %d", cipher1[3]- 48);
    //printf("\nCIPHER2: ");
    for (int s = 1; s<strlen(cipher1); s++){
        cipher2[s]= cipher1[s] -48;
        //printf(" %d ", cipher2[s]);
    }
    blocksize = cipher1[0] -48;
    //printf("\nBlocksize: %d\n", blocksize);

    int incValue0= 0;
    int incValue1= 1;
    int incValue2= 2;
    int incValue3= 3;
    int incValue4= 4;
    int incValue5= 5;
    int incValue6= 6;
    int incValue7= 7;
    int incValue8= 8;

    
    int cipValue1= 1;
    int cipValue2= 2;
    int cipValue3= 3;
    int cipValue4= 4;
    int cipValue5= 5;
    int cipValue6= 6;
    int cipValue7= 7;
    int cipValue8= 8;
    int cipValue9= 9;

    int end = 0;
    int end1 = strlen(plaintext2)/blocksize;
    int ciphertext[10000];
    int ciphercount =0;

    while(end != end1){
        for(int p = 0; p<blocksize; p++){
            ciphertext[ciphercount] = (plaintext3[incValue0] * cipher2[cipValue1])+(plaintext3[incValue1]*cipher2[cipValue2]);
            
            if(blocksize>2){
                ciphertext[ciphercount] = (plaintext3[incValue0] * cipher2[cipValue1])+(plaintext3[incValue1]*cipher2[cipValue2])+(plaintext3[incValue2]*cipher2[cipValue3]);

            }
            if(blocksize>3){
                ciphertext[ciphercount] = (plaintext3[incValue0] * cipher2[cipValue1])+(plaintext3[incValue1]*cipher2[cipValue2])+(plaintext3[incValue2]*cipher2[cipValue3])+(plaintext3[incValue3]*cipher2[cipValue4]);
            }
            if(blocksize>4){
                ciphertext[ciphercount] = (plaintext3[incValue0] * cipher2[cipValue1])+(plaintext3[incValue1]*cipher2[cipValue2])+(plaintext3[incValue2]*cipher2[cipValue3])+(plaintext3[incValue3]*cipher2[cipValue4])+(plaintext3[incValue4]*cipher2[cipValue5]);
            }
            if(blocksize>5){
                ciphertext[ciphercount] = (plaintext3[incValue0] * cipher2[cipValue1])+(plaintext3[incValue1]*cipher2[cipValue2])+(plaintext3[incValue2]*cipher2[cipValue3])+(plaintext3[incValue3]*cipher2[cipValue4])+(plaintext3[incValue4]*cipher2[cipValue5])+(plaintext3[incValue5]*cipher2[cipValue6]);
            }
            if(blocksize>6){
                ciphertext[ciphercount] = (plaintext3[incValue0] * cipher2[cipValue1])+(plaintext3[incValue1]*cipher2[cipValue2])+(plaintext3[incValue2]*cipher2[cipValue3])+(plaintext3[incValue3]*cipher2[cipValue4])+(plaintext3[incValue4]*cipher2[cipValue5])+(plaintext3[incValue5]*cipher2[cipValue6])+(plaintext3[incValue6]*cipher2[cipValue7]);
            }
            if(blocksize>7){
                ciphertext[ciphercount] = (plaintext3[incValue0] * cipher2[cipValue1])+(plaintext3[incValue1]*cipher2[cipValue2])+(plaintext3[incValue2]*cipher2[cipValue3])+(plaintext3[incValue3]*cipher2[cipValue4])+(plaintext3[incValue4]*cipher2[cipValue5])+(plaintext3[incValue5]*cipher2[cipValue6])+(plaintext3[incValue6]*cipher2[cipValue7])+(plaintext3[incValue7]*cipher2[cipValue8]);
            }
            if(blocksize>8){
                ciphertext[ciphercount] = (plaintext3[incValue0] * cipher2[cipValue1])+(plaintext3[incValue1]*cipher2[cipValue2])+(plaintext3[incValue2]*cipher2[cipValue3])+(plaintext3[incValue3]*cipher2[cipValue4])+(plaintext3[incValue4]*cipher2[cipValue5])+(plaintext3[incValue5]*cipher2[cipValue6])+(plaintext3[incValue6]*cipher2[cipValue7])+(plaintext3[incValue7]*cipher2[cipValue8])+(plaintext3[incValue8]*cipher2[cipValue9]);
            }
            ciphertext[ciphercount] = ciphertext[ciphercount] %26;
            cipValue1+=blocksize;
            cipValue2+=blocksize;
            cipValue3+=blocksize;
            cipValue4+=blocksize;
            cipValue5+=blocksize;
            cipValue6+=blocksize;
            cipValue7+=blocksize;
            cipValue8+=blocksize;
            cipValue9+=blocksize;
            ciphercount++;
        }
        cipValue1=1;
        cipValue2=2;
        cipValue3=3;
        cipValue4=4;
        cipValue5=5;
        cipValue6=6;
        cipValue7=7;
        cipValue8=8;
        cipValue9=9;

        incValue0 += blocksize;
        incValue1 += blocksize;

        end++;
    }
    char ciphertext1[10000];

    printf("\nPlaintext:\n");
    for (int r = 0; r<strlen(plaintext2); r++){
        if(r ==79 || r == 159 || r == 239 || r ==319 || r==359 || r==359+80|| r==359+80+80|| r==359+80+80+80||r==359+80+80+80+80||r==359+80+80+80+80+80||r==359+80+80+80+80+80+80||r==359+80+80+80+80+80+80+80){
            printf("\n%c", plaintext2[r]);
        }else{
            printf("%c", plaintext2[r]);
        }
    }

    printf("\n\nCiphertext:\n");
    for (int r = 0; r<strlen(plaintext2); r++){
        ciphertext1[r] = ciphertext[r];
        ciphertext1[r] = ciphertext1[r] %26 +97;
        if(r ==79 || r == 159 || r == 239 || r ==319 || r==359 || r==359+80|| r==359+80+80|| r==359+80+80+80||r==359+80+80+80+80||r==359+80+80+80+80+80||r==359+80+80+80+80+80+80||r==359+80+80+80+80+80+80+80){
            printf("\n%c", ciphertext1[r]);
        }else{
            printf("%c", ciphertext1[r]);
        }
    }

    fclose(fptr1);
    fclose(fptr2);
    return 0;

}


/*=============================================================================
| I [Bryce Kelly] (br284128) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/