#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper_functions.h"
#include "menu.h"

void menu() {
    printf("\033[2J");
    invalid_command:
    printf("#####Bulgarian Society Imperial college London#####\n");
    printf("[1]Add a new member\n");
    printf("[2]List all of the society members\n");
    printf("[3]Remove a member\n");
    printf("[4]Modify a member record\n");
    printf("[5]Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_member();
            break;
        case 2:
            list_records();
            break;
        case 3:
            delete_record();
            break;
        case 4:
            modify_record();
            break;
        case 5:
            close();
            break;
        default:
            printf("Invalid! Please try again!\n");
            delay(100000);
            printf("\033[2J");
            goto invalid_command;

    }

}