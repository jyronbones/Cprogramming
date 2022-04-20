/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Constants */
#define INSERT_EMP "1"
#define MOD_EMP "2"
#define DELETE_EMP "3"
#define DISPLAY_ENTRIES "4"
#define QUIT "q"
#define LENGTH 101
#define NUM_EMPLOYEES 150
#define MALE "M"
#define FEMALE "F"
#define NAME "name"
#define AGE "age"
#define GENDER "gender"
#define JOB "job"
#define YES "Y"
#define NO "N"
#define MODIFY 0
#define DELETE 1

/* Structs */
typedef struct emp
{
    char name[LENGTH];
    char gender;
    int age;
    char job[LENGTH];
    struct emp *next;
} emp;

/* Variables */
int empCount;
int displayCount;
int isFirst;
emp *head;

/* Function prototypes */
emp *insert(emp *headEmp);
emp *nameSearch(emp *headEmp, char *searchName, int flag);
emp *genderSearch(emp *headEmp, char *searchGender, int flag);
emp *ageSearch(emp *headEmp, int *searchAge, int flag);
emp *jobSearch(emp *headEmp, char *searchJob, int flag);
emp *modifyEmpName(emp *headEmp, char *searchName);
emp *modifyEmpGender(emp *headEmp, char *searchGender);
emp *modifyEmpAge(emp *headEmp, int *searchAge);
emp *modifyEmpJob(emp *headEmp, char *searchJob);
emp *modifyEmp(emp *headEmp, char *searchName);
emp *deleteEmpName(emp *headEmp, char *searchName);
emp *deleteEmpGender(emp *headEmp, char *searchGender);
emp *deleteEmpAge(emp *headEmp, int *searchAge);
emp *deleteEmpJob(emp *headEmp, char *searchJob);
emp *sort(emp *headEmp);
emp *swap(emp *emp1, emp *emp2);
void modMenu(emp *headEmp);
void delMenu(emp *headEmp);
void displayList(emp *headEmp);
int validateAge(void);
char validateGender(void);
int validNum(void);
char validateAnswer(void);
void clearBuffer(void);