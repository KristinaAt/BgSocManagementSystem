#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "system_functions.h"
#include <stdbool.h>

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

    void list_records() {
        printf("\033[2J");
        FILE *fp = fopen("records.dat", "a+");
        if (fp == NULL) {
            perror("No input file");
            exit(EXIT_FAILURE);
        }

        if (!check_for_members(fp)) {
            printf("This club has no members!\n");
            menu_or_exit();
        }

        while (fscanf(fp, "%s %s %s %d/%d/%d %s %s %d", list.name, list.phone_number, list.status,
                      &list.date_of_birth.day, &list.date_of_birth.month, &list.date_of_birth.year,
                      list.hometown, list.course, &list.year_of_education) != EOF) {
            fprintf(fp, "%s %s %s %d/%d/%d %s %s %d \n", list.name, list.phone_number, list.status,
                    list.date_of_birth.day, list.date_of_birth.month, list.date_of_birth.year,
                    list.hometown, list.course, list.year_of_education);
        }
        menu_or_exit();
    }

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

        if (!check_for_members(fp_records)) {
            printf("There are no members in this society!\n");
            close();
        }

        char name[20];
        printf("Enter the name of the member you want to remove from the society list: ");
        scanf("%s", name);

        if (!check_name(fp_records, name)) {
            printf("There is no member with such name\n");
            menu_or_exit();
            return;
        }

    while (fscanf(fp_records, "%s %s %s %d/%d/%d %s %s %d", delete.name, delete.phone_number, delete.status,
                  &delete.date_of_birth.day, &delete.date_of_birth.month, &delete.date_of_birth.year,
                  delete.hometown, delete.course, &delete.year_of_education) != EOF){
        if(strcmp(delete.name, name)){
            fprintf(fp_new, "%s %s %s %d/%d/%d %s %s %d\n", delete.name, delete.phone_number, delete.status,
                    delete.date_of_birth.day, delete.date_of_birth.month, delete.date_of_birth.year,
                    delete.hometown, delete.course, delete.year_of_education);
        }
    }

    fclose(fp_records);
    fclose(fp_records);

    remove("records.dat");
    rename("new_records.dat", "records.dat");
    printf("Memeber successfully removed!\n");
}

    void modify_record() {

    }

    void menu() {
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
            case 0:
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
                fordelay(100000);
                printf("\033[2J");
                goto invalid_command;

        }

    }

//Returns true if the society has members
    bool check_for_members(FILE *fp) {
        bool check = true;
        int number_of_members = 0;

        while (fscanf(fp, "%s %s %s %d/%d/%d %s %s %d", list.name, list.phone_number, list.status,
                      &list.date_of_birth.day, &list.date_of_birth.month, &list.date_of_birth.year,
                      list.hometown, list.course, &list.year_of_education) != EOF) {
            printf("%s %s %s %d/%d/%d %s %s %d year of education \n", list.name, list.phone_number, list.status,
                   list.date_of_birth.day, list.date_of_birth.month, list.date_of_birth.year, list.hometown,
                   list.course, list.year_of_education);
            number_of_members++;
        }

        if (number_of_members == 0) {
            check = false;
        }
        fseek(fp, 0, SEEK_SET);
        return check;
    }

    //Checks if in the database there is a person with the given name
    bool check_name(FILE* fp, char* name){
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
        return result;
}

    void menu_or_exit() {
        printf("\033[2J");
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