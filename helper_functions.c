#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "helper_functions.h"
#include <stdbool.h>
#include "menu.h"

//Returns true if the society has members
void check_for_members(FILE *fp) {
    bool result = true;
    int number_of_members = 0;

    while (fscanf(fp, "%s %s %s %d/%d/%d %s %s %d", list.name, list.phone_number, list.status,
                  &list.date_of_birth.day, &list.date_of_birth.month, &list.date_of_birth.year,
                  list.hometown, list.course, &list.year_of_education) != EOF) {
        number_of_members++;
    }

    if (number_of_members == 0) {
        result = false;
    }
    fseek(fp, 0, SEEK_SET);
    if (!result) {
        printf("This club has no members!\n");
        menu_or_exit();
    }
}

//Checks if in the database there is a person with the given name
void check_name(FILE *fp, char *name) {
    bool result = false;
    while (fscanf(fp, "%s %s %s %d/%d/%d %s %s %d", check.name, check.phone_number, check.status,
                  &check.date_of_birth.day, &check.date_of_birth.month, &check.date_of_birth.year,
                  check.hometown, check.course, &check.year_of_education) != EOF) {
        printf("%s\n", check.name);
        if (strcmp(check.name, name) == 0) {
            result = true;
        }
    }
    fseek(fp, 0, SEEK_SET);
    if (!result) {
        printf("There is no member with such name\n");
        menu_or_exit();
        return;
    }
}

void menu_or_exit() {
    int choice;
    invalid:
    printf("Enter 1 to go to menu or 0 to exit: ");
    scanf("%d", &choice);
    if (choice == 1) {
        fordelay(100000);
        printf("\033[2J");
        menu();
    } else if (choice == 0) {
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

void close() {
    printf("\033[2J");
    printf("Closing");
    for (int i = 0; i < 3; ++i) {
        fordelay(1000000);
        printf(". ");
    }
    printf("\033[2J");
}

int fordelay(int delay) {
    int k;
    for (int i = 0; i < delay; i++) {
        k = i;
    }
    return k;
}