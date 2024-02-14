#include<stdio.h>

int main (void){

    float Mercury = 0.38;
    float Venus = 0.91;
    float Mars = 0.38;
    float Jupiter = 2.34;
    float Saturn = 1.06;
    float Uranus = 0.92;
    float Neptune = 1.19;
    double Eweight = 0.00 ;
    int choice = 0 ;
    float end = 0.00;

    printf("1.) Mercury\n2.) Venus\n3.) Mars\n4.) Jupiter\n5.) Saturn\n6.) Uranus\n7.) Neptune\n");

    printf("\nEnter Weight\n");
    scanf("%lf", &Eweight);
    printf("Enter planet number\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            end = Mercury * Eweight;
            printf("%.2f\n", end);
            break;
        case 2:
            end = Venus * Eweight;
            printf("%.2f\n", end);
            break;
        case 3:
            end = Mars * Eweight;
            printf("%.2f\n", end);
            break;
        case 4:
            end = Jupiter * Eweight;
            printf("%.2f\n", end);
            break;
        case 5:
            end = Saturn * Eweight;
            printf("%.2f\n", end);
            break;
        case 6:
            end = Uranus * Eweight;
            printf("%.2f\n", end);
            break;
        case 7:
            end = Neptune * Eweight;
            printf("%.2f\n", end);
            break;
        case 8:
            end = Mercury * Eweight;
            printf("%.2f\n", end);
            break;
        default:

            break;











    }













    return 0;
}






