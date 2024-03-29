#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "main_functions/add_member.h"
#include "main_functions/delete_record.h"
#include "main_functions/list_records.h"
#include "main_functions/modify_record.h"
#include "main_functions/menu.h"
#include "helper_functions.h"

int main() {
    char password[20] = "99";
    char pass[20];
    int choice;

    try_login:
    printf("Enter the password: ");
    scanf("%s", pass);
    if(strcmp(pass, password) == 0){
        printf("Your password is correct!\n");
        delay(1000000);
        printf("\033[2J");
        menu();
    } else {
        printf("Incorrect password!\n");
        invalid:
        printf("Enter 1 to try again or 0 to exit: ");
        scanf("%d", &choice);
        if(choice == 1){
            delay(100000);
            printf("\033[2J");
            goto try_login;
        } else if(choice == 0){
            delay(100000);
            printf("\033[2J");
            close();
        } else {
            printf("Invalid!\n");
            delay(100000);
            printf("\033[2J");
            goto invalid;
        }
    }
}