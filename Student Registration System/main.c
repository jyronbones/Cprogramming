/*
 * Title: Lab Assessment #3 - Student Registration System
 * Course: CST8234 C Language
 * @Author: <<< Byron Jones (040585687) >>>
 * Lab Section: 011
 * Professor: Surbhi Bahri
 * Due date: 03/06/22
 * Submission date: 03/06/22
 */

#include "functions.h"

/*****************************************************************************
Function Name: main
Purpose: Control the flow of the student registration system
Function in parameters: void
Function out parameter: EXIT_SUCCESS
Version: 1
Author: Byron Jones
*****************************************************************************/
int main()
{
	printf("Welcome to Student Registration System.\n\n");

	/* Arrays for student IDs, Course Codes, and registration table */
	int *students;
	char **courses;
	int **registrations;
	int i;

	/* Input Student IDs and course codes from the user */
	int numStudents = inputStudents(&students);
	int numCourses = inputCourses(&courses);
	int studentInd, courseInd;

	registrations = (int **)malloc(sizeof(int *) * numStudents);
	for (i = 0; i < numStudents; i++) /* allocate memory of the amount of courses for each student */
		registrations[i] = (int *)malloc(sizeof(int) * numCourses);

	printf("\n");
	while (1)
	{
		/* Display menu and get user choice */
		switch (menu())
		{
		case REGISTER: /* Register student in a course */
			studentInd = findStudent(students, numStudents);
			courseInd = findCourse(courses, numCourses);
			if (registrations[studentInd][courseInd] == 1)
			{
				printf("Already on record.\n");
				printf("Student id %d cannot register to course %s.\n", students[studentInd], courses[courseInd]);
				printf("Registration UnSuccessful\n");
				break;
			}
			else if (registrations[studentInd][courseInd] == -1)
			{
				printf("Student id %d have dropped out from course %s.\n", students[studentInd], courses[courseInd]);
				printf("Student id %d cannot register to course %s.\n", students[studentInd], courses[courseInd]);
				printf("Registration UnSuccessful\n");
				break;
			}
			registrations[studentInd][courseInd] = 1;
			printf("Registration Successful\n");
			break;
		case DROP: /* Drop student from a course */
			displayRegistrations(students, numStudents, courses, numCourses, registrations);
			dropCourse(registrations, numStudents, numCourses);
			printf("Drop Course successful.\n");
			displayRegistrations(students, numStudents, courses, numCourses, registrations);
			break;
		case DISPLAY: /* Display the registration table */
			displayRegistrations(students, numStudents, courses, numCourses, registrations);
			break;
		case EXIT: /* Exit option */
			free(registrations);
			free(students);
			free(courses);
			printf("Exiting...\n");
			return (EXIT_SUCCESS);
		default: /* Invalid option */
			printf("Invalid option\n");
		}
	}
}