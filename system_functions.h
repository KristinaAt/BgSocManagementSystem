#ifndef BGSOCMANAGEMENTSYSTEM_SYSTEM_FUNCTIONS_H
#define BGSOCMANAGEMENTSYSTEM_SYSTEM_FUNCTIONS_H

typedef struct Date{
    int day;
    int month;
    int year;
} Date;

struct Member{
    char name[50];
    char phone_number[20];
    char status[20];
    Date date_of_birth;
    char hometown[20];
    char course[20];
    int year_of_education;
} add, check, list, delete;

void add_member();
void list_records();
void delete_record();
void modify_record();
void menu();
bool check_for_members(FILE* fp);
void menu_or_exit();
void close();
int fordelay(int delay);
#endif