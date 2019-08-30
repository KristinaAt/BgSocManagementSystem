#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "helper_functions.h"
#include <stdbool.h>
#include "modify_record.h"

void modify_record() {
    printf("\033[2J");
    FILE *fp_records = fopen("records.dat", "r");
    if (fp_records == NULL) {
        perror("No records.dat file");
        exit(EXIT_FAILURE);
    }
    FILE *new_records = fopen("new_records.dat", "w");
    if (new_records == NULL) {
        perror("No new_records.dat file");
        exit(EXIT_FAILURE);
    }

    //Checks if there is a member with a given name
    char name[40];
    printf("Enter the name whose information is to be modified: ");
    scanf("%s", name);
    check_name(fp_records, name);

    printf("\n#####Choose which information you want to modify#####\n");
    printf("[1]Phone number\n");
    printf("[2]Membership status\n");
    printf("[3]Course\n");
    printf("[4]Year fo education\n");
    printf("[5]Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            modify_phone_number(fp_records, new_records, name);
            break;
        case 2:
            modify_status(fp_records, new_records, name);
            break;
        case 3:
            modify_course(fp_records, new_records, name);
            break;
        case 4:
            modify_year_of_education(fp_records, new_records, name);
            break;
        case 5:
            fclose(fp_records);
            fclose(new_records);
            menu_or_exit();
            break;
        default:
            printf("Invalid! Please try again!\n");
            fordelay(100000);
            printf("\033[2J");
            menu_or_exit();
    }
}

void modify_phone_number(FILE *fp_records, FILE *new_records, char *name) {
    printf("\033[2J");
    char new_phone_number[20];
    printf("Enter the new phone number: ");
    scanf("%s",new_phone_number);
    while(fscanf(fp_records, "%s %s %s %d/%d/%d %s %s %d", modify.name, modify.phone_number, modify.status,
                 &modify.date_of_birth.day, &modify.date_of_birth.month, &modify.date_of_birth.year,
                 modify.hometown, modify.course, &modify.year_of_education) != EOF){
        if(strcmp(name, modify.name) == 0){
            strcpy(modify.phone_number, new_phone_number);
        }
        fprintf(new_records, "%s %s %s %d/%d/%d %s %s %d\n", modify.name, modify.phone_number, modify.status,
                modify.date_of_birth.day, modify.date_of_birth.month, modify.date_of_birth.year,
                modify.hometown, modify.course, modify.year_of_education);
    }
    remove("records.dat");
    rename("new_records.dat", "records.dat");
    printf("Phone number successfully modified!\n");
    fclose(fp_records);
    fclose(new_records);
    menu_or_exit();
}

void modify_status(FILE *fp_records, FILE *new_records, char *name) {
    printf("\033[2J");
    char new_status[20];
    printf("Enter the new membership status: ");
    scanf("%s",new_status);
    while(fscanf(fp_records, "%s %s %s %d/%d/%d %s %s %d", modify.name, modify.phone_number, modify.status,
                 &modify.date_of_birth.day, &modify.date_of_birth.month, &modify.date_of_birth.year,
                 modify.hometown, modify.course, &modify.year_of_education) != EOF){
        if(strcmp(name, modify.name) == 0){
            strcpy(modify.status, new_status);
        }
        fprintf(new_records, "%s %s %s %d/%d/%d %s %s %d\n", modify.name, modify.phone_number, modify.status,
                modify.date_of_birth.day, modify.date_of_birth.month, modify.date_of_birth.year,
                modify.hometown, modify.course, modify.year_of_education);
    }
    fclose(fp_records);
    fclose(fp_records);
    remove("records.dat");
    rename("new_records.dat", "records.dat");
    printf("Status successfully modified!\n");
    menu_or_exit();
}

void modify_course(FILE *fp_records, FILE *new_records, char *name) {
    printf("\033[2J");
    char new_course[20];
    printf("Enter the new membership status: ");
    scanf("%s",new_course);
    while(fscanf(fp_records, "%s %s %s %d/%d/%d %s %s %d", modify.name, modify.phone_number, modify.status,
                 &modify.date_of_birth.day, &modify.date_of_birth.month, &modify.date_of_birth.year,
                 modify.hometown, modify.course, &modify.year_of_education) != EOF){
        if(strcmp(name, modify.name) == 0){
            strcpy(modify.course, new_course);
        }
        fprintf(new_records, "%s %s %s %d/%d/%d %s %s %d\n", modify.name, modify.phone_number, modify.status,
                modify.date_of_birth.day, modify.date_of_birth.month, modify.date_of_birth.year,
                modify.hometown, modify.course, modify.year_of_education);
    }
    fclose(fp_records);
    fclose(fp_records);
    remove("records.dat");
    rename("new_records.dat", "records.dat");
    printf("Course successfully modified!\n");
    menu_or_exit();
}

void modify_year_of_education(FILE *fp_records, FILE *new_records, char *name) {
    printf("\033[2J");
    int new_year_of_education;
    printf("Enter the new year of education: ");
    scanf("%d",&new_year_of_education);
    while(fscanf(fp_records, "%s %s %s %d/%d/%d %s %s %d", modify.name, modify.phone_number, modify.status,
                 &modify.date_of_birth.day, &modify.date_of_birth.month, &modify.date_of_birth.year,
                 modify.hometown, modify.course, &modify.year_of_education) != EOF){
        if(strcmp(name, modify.name) == 0){
            modify.year_of_education = new_year_of_education;
        }
        fprintf(new_records, "%s %s %s %d/%d/%d %s %s %d\n", modify.name, modify.phone_number, modify.status,
                modify.date_of_birth.day, modify.date_of_birth.month, modify.date_of_birth.year,
                modify.hometown, modify.course, modify.year_of_education);
    }
    fclose(fp_records);
    fclose(fp_records);
    remove("records.dat");
    rename("new_records.dat", "records.dat");
    printf("Year of education successfully modified!\n");
    menu_or_exit();
}

