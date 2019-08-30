#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "helper_functions.h"
#include <stdbool.h>
#include "add_member.h"

void add_member() {
    FILE *fp = fopen("records.dat", "a+");
    if (fp == NULL) {
        perror("No input file");
        exit(EXIT_FAILURE);
    }

    printf("\033[2J");
    printf("#####ADDING A MEMBER TO THE BULGARIAN SOCIETY#####\n");
    printf("Enter name:");
    scanf("%s", add.name);

    while (fscanf(fp, "%s %s %s %d/%d/%d %s %s %d", check.name, check.phone_number, check.status,
                  &check.date_of_birth.day, &check.date_of_birth.month, &check.date_of_birth.year,
                  check.hometown, check.course, &check.year_of_education) != EOF) {
        if (strcmp(check.name, add.name) == 0) {
            printf("That person is already a member!\n");
            menu_or_exit();
        }
    }

    printf("Enter phone number:");
    scanf("%s", add.phone_number);
    printf("Enter the status of the member(President, Vice president, Treasurer, Secretary, Web Master, Member): ");
    scanf("%s", add.status);
    printf("Enter date of birth(1/4/1999):");
    scanf("%d/%d/%d", &add.date_of_birth.day, &add.date_of_birth.month, &add.date_of_birth.year);
    printf("Enter hometown:");
    scanf("%s", add.hometown);
    printf("Enter course:");
    scanf("%s", add.course);
    printf("Enter year of education:");
    scanf("%d", &add.year_of_education);

    fprintf(fp, "%s %s %s %d/%d/%d %s %s %d\n", add.name, add.phone_number, add.status,
            add.date_of_birth.day, add.date_of_birth.month, add.date_of_birth.year,
            add.hometown, add.course, add.year_of_education);
    fclose(fp);
    printf("The member was added successfully!\n");

    menu_or_exit();
}