#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "helper_functions.h"
#include <stdbool.h>
#include "delete_record.h"

void delete_record() {
    printf("\033[2J");
    FILE *fp_records = fopen("records.dat", "r");
    if (fp_records == NULL) {
        perror("No records.dat file");
        exit(EXIT_FAILURE);
    }
    FILE *fp_new = fopen("new_records.dat", "w");
    if (fp_new == NULL) {
        perror("No file");
        exit(EXIT_FAILURE);
    }

    check_for_members(fp_records);

    char name[20];
    printf("Enter the name of the member you want to remove from the society list: ");
    scanf("%s", name);

    check_name(fp_records, name);

    while (fscanf(fp_records, "%s %s %s %d/%d/%d %s %s %d", delete.name, delete.phone_number, delete.status,
                  &delete.date_of_birth.day, &delete.date_of_birth.month, &delete.date_of_birth.year,
                  delete.hometown, delete.course, &delete.year_of_education) != EOF) {
        if (strcmp(delete.name, name)) {
            fprintf(fp_new, "%s %s %s %d/%d/%d %s %s %d\n", delete.name, delete.phone_number, delete.status,
                    delete.date_of_birth.day, delete.date_of_birth.month, delete.date_of_birth.year,
                    delete.hometown, delete.course, delete.year_of_education);
        }
    }

    fclose(fp_records);
    fclose(fp_records);
    remove("records.dat");
    rename("new_records.dat", "records.dat");
    printf("Member successfully removed!\n");
    menu_or_exit();
}
