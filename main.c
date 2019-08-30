#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "system_functions.h"

int main() {
    char password[20] = "1";
    char pass[20];
    int choice;

    try_login:
    printf("Enter the password: ");
    scanf("%s", pass);
    if(strcmp(pass, password) == 0){
        printf("Your password is correct!\n");
        fordelay(1000000);
        printf("\033[2J");
        menu();
    } else {
        printf("Incorrect password!\n");
        invalid:
        printf("Enter 1 to try againg or 0 to exit: ");
        scanf("%d", &choice);
        if(choice == 1){
            fordelay(100000);
            printf("\033[2J");
            goto try_login;
        } else if(choice == 0){
            fordelay(100000);
            printf("\033[2J");
            close();
        } else {
            printf("Invalid!\n");
            fordelay(100000);
            printf("\033[2J");
            goto invalid;
        }
    }
}