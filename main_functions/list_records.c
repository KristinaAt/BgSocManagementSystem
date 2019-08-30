#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "helper_functions.h"
#include <stdbool.h>
#include "list_records.h"

void list_records() {
    printf("\033[2J");
    FILE *fp = fopen("records.dat", "a+");
    if (fp == NULL) {
        perror("No input file");
        exit(EXIT_FAILURE);
    }
    check_for_members(fp);

    while (fscanf(fp, "%s %s %s %d/%d/%d %s %s %d", list.name, list.phone_number, list.status,
                  &list.date_of_birth.day, &list.date_of_birth.month, &list.date_of_birth.year,
                  list.hometown, list.course, &list.year_of_education) != EOF) {
        printf("%s %s %s %d/%d/%d %s %s %d \n", list.name, list.phone_number, list.status,
               list.date_of_birth.day, list.date_of_birth.month, list.date_of_birth.year,
               list.hometown, list.course, list.year_of_education);
    }
    fclose(fp);
    menu_or_exit();
}