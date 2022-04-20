/*
 * Title: Assignment 2 -- Implement a program to maintain an employee database
 * Course: CST8234 C Language
 * @Author: Mariam Collins(040911894), Byron Jones (040585687), Jordan Kent(040607241), David Sun(041031332)
 * Professor: Surbhi Bahri
 * Due date: 04/10/22
 * files: main.c, employee.c, functions.c, functions.h, makefile
 */
#include "functions.h"

/*****************************************************************************
Function Name: main
Purpose: this program alphabetically manages a database of employees using a 
         linked list. The user can add or delete employees to and from the list, 
         aswell as modify employees in the list. This program can also display 
         all employees in the list. 
Function in parameters: void
Function out parameter: EXIT_SUCCESS
Version: 2
Author: Byron Jones, Jordan Kent, Mariam Collins, David
*****************************************************************************/

int main()
{
    int i;

    while (1)
    {
        char option[3];

        printf(
            "Choose one of the following options\n"
            "[1] insert data of another employee\n"
            "[2] modify existing employee information\n"
            "[3] delete an employee data\n"
            "[4] show all database entries\n"
            "[q] quit\n"
            "Enter choice: "
            );

    scanf("%2s", option);
    option[0] = tolower(option[0]);
        if (strcmp(option, INSERT_EMP) == 0)
        {
            
            head = insert(head);
            head = sort(head);
        }
        else if (strcmp(option, MOD_EMP) == 0)
        {
            modMenu(head);
            head = sort(head);
        }
        else if (strcmp(option, DELETE_EMP) == 0)
        {
            delMenu(head);
        }
        else if (strcmp(option, DISPLAY_ENTRIES) == 0)
        {   
            displayList(head);
        }
        else if (strcmp(option, QUIT) == 0)
        {
            printf("Have a nice time!\n");
                return EXIT_SUCCESS;
        }           
        else 
        {
            printf("Not accepted. Enter a valid option number [1-4 or q]\n");
            clearBuffer();
        }
    }
    return EXIT_SUCCESS;
}