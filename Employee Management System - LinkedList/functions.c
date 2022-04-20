#include "functions.h"
/*****************************************************************************
Function Name: modMenu
Purpose: modMenu implements instructions that will allow the user to modify 
        the feature of employees. modMenu calls functions that allow 
        the user to search and modify employee's name, employee's gender, 
	employee's age, employee's job and so on. modMenu also calls 
	functions like clear buffer, validate gender, validate age etc. 
Function in parameters: emp *headEmp
Function out parameter: void
Version: 5
Author: Byron Jones, Jordan Kent, edited by Mariam Collins
*****************************************************************************/
void modMenu(emp *headEmp)
{
    int searchAge, i;
    char input[LENGTH], *searchName[LENGTH], searchGender, *searchJob[LENGTH];

    if (empCount == 0)
    {
        printf("No employees in database to modify\n");
        return;
    }
    while (1)
    {

        printf("Enter the employee feature you wish to modify(name, gender, age, job): ");
        scanf("%100s", input);
        clearBuffer();
        for (i = 0; i < strlen(input); i++)
        {
            input[i] = tolower(input[i]);
        }

        if (strcmp(input, NAME) == 0)
        {
            printf("Enter the name of the employee you wish to change: ");
            scanf("%100[^\n]s", searchName);
            clearBuffer();
            modifyEmpName(headEmp, searchName);
           
            break;
        }
        else if (strcmp(input, GENDER) == 0)
        {
            printf("Enter the gender of the employee you wish to change: ");
            searchGender = validateGender();
            modifyEmpGender(headEmp, searchGender);
            break;
        }
        else if (strcmp(input, AGE) == 0)
        {
            printf("Enter the age of the employee you wish to change: ");
            searchAge = validateAge();
            modifyEmpAge(headEmp, searchAge);
            break;
        }
        else if (strcmp(input, JOB) == 0)
        {
            printf("Enter the job of the employee you wish to change: ");
            scanf("%100[^\n]s", searchJob);
            clearBuffer();
            modifyEmpJob(headEmp, searchJob);
            break;
        }
        else
        {
            printf("Invalid specified feature\n");
        }
    }
}
/*****************************************************************************
Function Name: delMenu
Purpose: implements instructions that will allow the user to delete
        employees based on features. this function calls functions that allow 
        the user to search and delete an employee based on employee's name, 
	gender, age, and job. delMenu() also calls functions like clear buffer, 
	validate gender, validate age etc. 
Function in parameters: emp *headEmp
Function out parameter: void
Version: 5
Author: Byron Jones, Jordan Kent, edited by Mariam Collins,
*****************************************************************************/
void delMenu(emp *head)
{
    int searchAge, i;
    char input[LENGTH], *searchName[LENGTH], searchGender, *searchJob[LENGTH];

    if (empCount == 0)
    {
        printf("No employees in database to delete\n");
        return;
    }
    while (1)
    {
        printf("Enter the employee feature you wish to delete(name, gender, age, job): ");
        scanf("%100s", input);
        clearBuffer();
        for (i = 0; i < strlen(input); i++)
        {
            input[i] = tolower(input[i]);
        }

        if (strcmp(input, NAME) == 0)
        {
            printf("Enter the name of the employee you wish to delete: ");
            scanf("%100[^\n]s", searchName);
            clearBuffer();
            deleteEmpName(head, searchName);
            break;
        }
        else if (strcmp(input, GENDER) == 0)
        {
            printf("Enter the gender of the employee you wish to delete: ");
            searchGender = validateGender();
            deleteEmpGender(head, searchGender);
            break;
        }
        else if (strcmp(input, AGE) == 0)
        {
            printf("Enter the age of the employee you wish to delete: ");
            searchAge = validateAge();
            deleteEmpAge(head, searchAge);
            break;
        }
        else if (strcmp(input, JOB) == 0)
        {
            printf("Enter the job of the employee you wish to delete: ");
            scanf("%100[^\n]s", searchJob);
            clearBuffer();
            deleteEmpJob(head, searchJob);
            clearBuffer();
            break;
        }
        else
        {
            printf("Invalid specified feature\n");
        }
    }
}
/*****************************************************************************
Function Name: clearBuffer
Purpose: Clear the input buffer before or after accepting input from the user.
Function in parameters: void
Function out parameter: void
Version: 3
Author: Byron Jones
*****************************************************************************/
void clearBuffer(void)
{
    while (getchar() != '\n');
}
/*****************************************************************************
Function Name: validateAge
Purpose: validateAge() implements instructions that will allow the user to validate
        the input for the employee's age. validateAge() also calls the function of 
	clearbuffer. This function allows the user to valid if the input is whole 
	number and if the number is in a reasonable range. 
Function in parameters: void
Function out parameter: num
Version: 5
Author: Byron Jones, Jordan Kent
*****************************************************************************/
int validateAge(void)
{
    int num;
    char term;
    while (1) /* loop until valid age */
    {
        if (scanf(" %d%c", &num, &term) != 2 || term != '\n') /** checks for whole number **/
        {

            clearBuffer();
            printf("Invalid age, please enter a valid age: ");

            continue; /** cycle loop **/
        }
        else /** check if age less than 0 **/
        {
            if (num < 1 || num > 122) /** age less than 0 **/
            {
                printf("invalid age, please enter a valid age between 1-122: ");

                continue; /** cycle loop **/ 
            }
            else /* valid age **/
            {
                break;
            }
        }
    }
    return num;
}
/*****************************************************************************
Function Name: validateGender
Purpose: validateGender() implements instructions that will allow the user to validate
        the input for the employee's sex. validateGender() also calls the function of 
	clearbuffer. This function allows the user to probit invalid input if the user 
	enters a wrong input other than "M" or "F"
Function in parameters: void
Function out parameter: input[0]
Version: 5
Author: Byron Jones, Jordan Kent
*****************************************************************************/
char validateGender(void)
{
    char input[3];
    while (1)
    {
    scanf("%2s", input);
    input[0] = toupper(input[0]);
        if (strcmp(input, MALE) == 0 || strcmp(input, FEMALE) == 0)
        {
            return input[0];
        }
        else 
        {
            printf("Invalid entry, enter M for male or F for female: ");
            clearBuffer();
        }
    }
}
/*****************************************************************************
Function Name: validNum
Purpose: validNum() implements instructions that will allow the user to validate
        if the input is valid. validNum() also calls the function of clearbuffer. 
		This function allows the user to valid if the input is whole number and if the number
		is in a reasonable range. 
Function in parameters: void
Function out parameter: num
Version: 5
Author: Byron Jones, Jordan Kent
*****************************************************************************/
int validNum(void)
{
    int num;
    char term;
    while (1) /* loop until valid integer within range of indexes */
    {
        if (scanf(" %d%c", &num, &term) != 2 || term != '\n') /** checks for whole number **/
        {
            clearBuffer();
            printf("Invalid entry, re-enter: ");

            continue; /** cycle loop **/
        }
        else /** check if age less than 0 **/
        {
            if (num < 1 || num > displayCount) /** age less than 0 **/
            {
                printf("Invalid entry, re-enter: ");

                continue; /** cycle loop **/ 
            }
            else /* valid age **/
            {
                break;
            }
        }
    }
    return num;
}
/*****************************************************************************
Function Name: validateAnswer
Purpose: validateAnswer implements instructions that will allow the user to validate
        the input is valid. validateAnswer() also calls the function of clearbuffer. 
		This function allows the user to probit invalid input if the user enters a wrong input
		other than "Y" or "N"
Function in parameters: void
Function out parameter: input[0]
Version: 5
Author: Byron Jones, Jordan Kent
*****************************************************************************/
char validateAnswer(void)
{
    char input[3];
    while (1)
    {
    scanf("%2s", input);
    input[0] = toupper(input[0]);
        if (strcmp(input, YES) == 0 || strcmp(input, NO) == 0)
        {
            return input[0];
        }
        else 
        {
            printf("Invalid entry, enter Y for yes or N for no: ");
            clearBuffer();
        }
    }
}