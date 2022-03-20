/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Constants */
#define REGISTER 1
#define DROP 2
#define DISPLAY 3
#define EXIT 4


/* Function prototypes */
int inputStudents(int **students);
int inputCourses(char ***courses);
int isCourseCodeValid(char *courseCode);
int menu(void);
void displayRegistrations(int *students, int numStudents, char **courses,
	int numCourses, int **registrations);
int findStudent(int *students, int num);
int findCourse(char **courses, int num);
void dropCourse(int** registrations, int numStudents, int numCourses);
void clearBuffer(void);