#include "functions.h"

/*****************************************************************************
Function Name: inputStudents
Purpose: Function to take the number of students and student IDs from
		 the user and validate the input
Function in parameters: int **students
Function out parameter: int - numStudents
Version: 1
Author: Byron Jones
*****************************************************************************/
int inputStudents(int **students)
{
	int numStudents = 0, i, in;
	char input[10];
REPEAT:
	printf("Enter the number of students to register: ");
	scanf("%s", input);
	for (i = 0; input[i] != '\0'; i++) /* check if input is digits */
	{
		if (isdigit(input[i]) == 0)
		{
			goto ERROR;
		}
	}
	numStudents = atoi(input);
	/* Input validation */
	while (numStudents <= 0) /* loop for user to re-enter number of students if invalid entry */
	{ 
	ERROR:
		printf("Invalid input. Enter again\n");
		clearBuffer();
		goto REPEAT;
	}

	*students = (int *)malloc(sizeof(int) * numStudents);

	for (i = 0; i < numStudents; i++) /* loop to ask user for student numbers of students */
	{
		printf("Enter the student index[%d] student id [5-digits]: ", i);
		scanf("%s", input);
		in = atoi(input);
		/* Input validation */
		while (in < 10000 || in > 99999) /* ensure student ID is 5 digits */
		{
			printf("Student Id must be 5 digits\n");
			printf("Enter the student index[%d] student id [5-digits]: ", i);
			scanf("%s", input);
			in = atoi(input);
		}

		(*students)[i] = in;
	}
	return numStudents;
}

/*****************************************************************************
Function Name: isCourseCodeValid
Purpose: Function to validate the course code
Function in parameters: char *courseCode
Function out parameter: int - 0 invalid length, -1 invalid char, 1 valid course code
Version: 1
Author: Byron Jones
*****************************************************************************/
int isCourseCodeValid(char *courseCode)
{
	int j;
	if (strlen(courseCode) != 7) /* check for course length of 7 chars */
		return 0;
	for (j = 0; courseCode[j] != '\0'; j++) /* loop through course code entered */
	{
		if (j <= 2 && !(courseCode[j] >= 'a' && courseCode[j] <= 'z') && /* check for first 3 chars as letters */
			!(courseCode[j] >= 'A' && courseCode[j] <= 'Z'))
			return -1;
		if (j > 2 && !(courseCode[j] >= '0' && courseCode[j] <= '9')) /* check for last 4 chars as numbers */
			return -1;
	}
	return 1;
}

/*****************************************************************************
Function Name: inputCourses
Purpose: Function to take the number of courses and course codes from
		 the user and validate the input
Function in parameters: char ***courses
Function out parameter: int numCourses
Version: 1
Author: Byron Jones
*****************************************************************************/
int inputCourses(char ***courses)
{
	int numCourses = 0, i;
	char input[10];

	printf("\nEnter the number of courses available: ");
	scanf("%s", input);
	numCourses = atoi(input);
	while (numCourses <= 0) /* loop asking for number of courses is not greater than 0 */
	{ 
		printf("Invalid input. Enter again\n");
		printf("\nEnter the number of courses available: ");
		scanf("%s", input);
		numCourses = atoi(input);
	}

	*courses = (char **)malloc(sizeof(char *) * numCourses);
	for (i = 0; i < numCourses; i++) /* allocating memory for each course */
	{ 
		(*courses)[i] = (char *)malloc(10);
	}

	for (i = 0; i < numCourses; i++) /* loop through number of courses asking user for course codes */
	{ 
		printf("Enter the course index[%d] course id [3-Alphas][4-digits]: ", i);
		scanf("%s", (*courses)[i]);
		/* Input validation */
		int err = isCourseCodeValid((*courses)[i]);
		while (err != 1) /* loop to ask user to re-enter course code if invalid */
		{ 
			if (err == 0) /* incorrect course code length */
			{ 
				printf("Incorrect Course Id length [7-character Id]\n");
			}
			else /* incorrect characters entered */
			{ 
				printf("Incorrect Course Id input [3-Alphas][4-digits]\n");
			}
			printf("Enter the course index[%d] course id [3-Alphas][4-digits]: ", i);
			scanf("%s", (*courses)[i]);
			err = isCourseCodeValid((*courses)[i]);
		}
	}
	return numCourses;
}

/*****************************************************************************
Function Name: inputCourses
Purpose: Function to display menu to the user and get user choice
Function in parameters: void
Function out parameter: int - user selected option
Version: 1
Author: Byron Jones
*****************************************************************************/
int menu()
{
	printf("Main Menu:\n");
	printf(" [1] Register a student into a course.\n");
	printf(" [2] Drop a student from a course.\n");
	printf(" [3] Display Registration table.\n");
	printf(" [4] Exit\n");
	printf(" Enter an option from the menu: ");
	char choice[10];
	scanf("%s", choice);
	return atoi(choice);
}

/*****************************************************************************
Function Name: displayRegistrations
Purpose: Function to display the course registrations against each student
Function in parameters: int *students, int numStudents, char ** courses,
						int numCourses, int **registrations
Function out parameter: void
Version: 1
Author: Byron Jones
*****************************************************************************/
void displayRegistrations(int *students, int numStudents, char **courses,
						  int numCourses, int **registrations)
{
	int i, j, index = 0;
	printf("\n                      Registration Table\n");
	printf("Registration Index    Student ID      Course ID      Registration Status\n");
	for (i = 0; i < numStudents; i++) /* loop through students */
	{ 
		for (j = 0; j < numCourses; j++) /* loop through courses */
		{
			if (registrations[i][j] == 1) /* lists student course registered */
			{
				printf("        %-14d%-16d%-15s%c\n", index++, students[i],
					   courses[j], 'R');
			}
			else if (registrations[i][j] == -1) /* lists student course dropped */
			{
				printf("        %-14d%-16d%-15s%c\n", index++, students[i],
					   courses[j], 'D');
			}
		}
	}
}

/*****************************************************************************
Function Name: findStudents
Purpose: Function to take the student id from the user
		and find the index at which it stored
Function in parameters: int *students, int num
Function out parameter: int - index of student
Version: 1
Author: Byron Jones
*****************************************************************************/
int findStudent(int *students, int num)
{
	int in, i;
	char input[10];

	printf("List of Student Ids\n");
	for (i = 0; i < num; i++) /*lists students IDs */
	{
		printf("Index %-11d%d\n", i, students[i]);
	}
REPEAT:
	printf("Enter the Student's Id to register a course:");
	scanf("%s", input);
	for (i = 0; input[i] != '\0'; i++)
	{
		if (isdigit(input[i]) == 0)
		{
			goto ERROR;
		}
	}
	in = atoi(input);
	/* Input validation */
	while (in < 10000 || in > 99999) /* check for student ID 5 numbers long */
	{
	ERROR:
		printf("Student Id must be 5 digits\n");
		clearBuffer();
		goto REPEAT;
	}

	for (i = 0; i < num; i++) /* finds the matching student ID */
	{
		if (students[i] == in)
		{
			return i;
		}
	}
}

/*****************************************************************************
Function Name: findCourse
Purpose: Function to take the course code from the user
		 and find the index at which it stored
Function in parameters: char** courses, int num
Function out parameter: int - index of course
Version: 1
Author: Byron Jones
*****************************************************************************/
int findCourse(char **courses, int num)
{
	char course[10];
	int i;

	printf("List of Available Course Id\n");
	for (i = 0; i < num; i++) /* lists courses */
	{
		printf("Index %-11d%s\n", i, courses[i]);
	}

	printf("Enter the course id [3-Alphas][4-digits]: ");
	scanf("%s", course);

	int err = isCourseCodeValid(course);
	while (err != 1) /* loop asking user to re-enter course code if invalid */
	{
		if (err == 0) /* invalid course code length */
		{
			printf("Incorrect Course Id length [7-character Id]\n");
		}
		else /* invalid course code characters */
		{
			printf("Incorrect Course Id input [3-Alphas][4-digits]\n");
		}
		printf("Enter the course id [3-Alphas][4-digits]: ");
		scanf("%s", course);
		err = isCourseCodeValid(course);
	}

	for (i = 0; i < num; i++) /* finds the matching course code user entered */
	{
		if (strcmp(courses[i], course) == 0)
		{
			return i;
		}
	}
}

/*****************************************************************************
Function Name: dropCourse
Purpose: Function to drop a course
Function in parameters: int** registrations, int numStudents, int numCourses
Function out parameter: void
Version: 1
Author: Byron Jones
*****************************************************************************/
void dropCourse(int **registrations, int numStudents, int numCourses)
{
	printf("Please select Index number to drop student registration: ");
	int index, cur = 0;
	scanf("%d", &index);
	int i, j;
	for (i = 0; i < numStudents; i++) /* loop through students */
	{
		for (j = 0; j < numCourses; j++) /* loop through courses */
		{
			if (registrations[i][j] == 1 || registrations[i][j] == -1) /* check if student registered or dropped */
			{
				if (index == cur) /* checks user entered index */
				{
					registrations[i][j] = -1; /* drop course */
					return;
				}
				else /* increment registration index */
				{ 
					cur++;
				}
			}
		}
	}
}

/*****************************************************************************
Function Name: clearBuffer
Purpose: Function to drop a course
Function in parameters: void
Function out parameter: void
Version: 1
Author: Byron Jones
*****************************************************************************/
void clearBuffer()
{
	while (getchar() != '\n');
}