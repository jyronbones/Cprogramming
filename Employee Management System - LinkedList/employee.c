#include "functions.h"
/*****************************************************************************
Function Name: nameSearch
Purpose:  to return a specific employee to the function that called it. this 
          function finds all the employee whos job match char *searchName, and 
          then to prompt user to select the employee they want to modify or delete
Function in parameters: emp *headEmp, char *searchName, int flag
Function out parameter: current
Version: 5
Author: Byron, Jordan, Mariam 
*****************************************************************************/
emp *nameSearch(emp *headEmp, char *searchName, int flag)
{
    int i = 0, j, k = 0, nameCount = 0;
    int nameIndex[empCount], entry;
    char answer, findName[LENGTH], nextName[LENGTH], currentName[LENGTH], firstEmpName[LENGTH];
    emp *current = headEmp;
    emp *nextNode = current->next;
    strcpy(firstEmpName, headEmp->name);
    for (j = 0; firstEmpName[j] != '\0'; j++)
    {
        firstEmpName[j] = tolower(firstEmpName[j]);
    }
    j = 0;
    strcpy(currentName, current->name);
    displayCount = 0;
    strcpy(findName, searchName);
    for (j = 0; findName[j] != '\0'; j++)
    {
        findName[j] = tolower(findName[j]);
    }
    j = 0;
    for (j = 0; currentName[j] != '\0'; j++)
    {
        currentName[j] = tolower(currentName[j]);
    }
    j = 0;
    if (flag == MODIFY)
    {
        if (strcmp(currentName, findName) == 0)
        {
            printf("%d) %s %c %d %s\n", displayCount + 1, current->name, current->gender, current->age, current->job);
            nameIndex[displayCount] = nameCount;
            displayCount++;
        }
        while (nextNode != NULL)
        {
            strcpy(nextName, nextNode->name);
            for (j = 0; nextName[j] != '\0'; j++)
            {
                nextName[j] = tolower(nextName[j]);
            }
            j = 0;
            if (strcmp(nextName, findName) == 0)
            {
                printf("%d) %s %c %d %s\n", displayCount + 1, nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
                nameIndex[displayCount] = nameCount + 1;
                displayCount++;
            }

            current = current->next;
            nextNode = nextNode->next;
            nameCount++;
        }
    }

    else if (flag == DELETE)
    {
        if (strcmp(currentName, findName) == 0)
        {
            printf("%d) %s %c %d %s\n", displayCount + 1, current->name, current->gender, current->age, current->job);
            nameIndex[displayCount] = nameCount;
            displayCount++;
        }
        while (nextNode != NULL && k < empCount - 1)
        {
            strcpy(nextName, nextNode->name);
            for (j = 0; nextName[j] != '\0'; j++)
            {
                nextName[j] = tolower(nextName[j]);
            }
            j = 0;
            if (strcmp(nextName, findName) == 0)
            {
                printf("%d) %s %c %d %s\n", displayCount + 1, nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
                nameIndex[displayCount] = nameCount;
                displayCount++;
            }
            k++;
            current = current->next;
            nextNode = nextNode->next;
            nameCount++;
        }
        k = 0;
    }
    if (displayCount == 0)
    {
        printf("\nNo employees of name %s\n\n", searchName);
        return NULL;
    }

 if (flag == MODIFY)
    {
        printf("Select which entry you'd like to modify: ");
        entry = validNum();
        entry = nameIndex[entry - 1];
        if (entry == 0 && (strcmp(firstEmpName, findName)) == 0)
            isFirst = 1;
        current = headEmp;
        nextNode = current->next;

        while (nextNode != NULL)
        {
            if (i == entry)
                break;
            current = current->next;
            nextNode = nextNode->next;
            i++;
        }
    }
    else if (flag == DELETE)
    {
        printf("Select which entry you'd like to delete: ");
        entry = validNum();
        entry = nameIndex[entry - 1];
        if (entry == 0 && (strcmp(firstEmpName, findName)) == 0)
            isFirst = 1;

        current = headEmp;
        nextNode = current->next;

        while (nextNode != NULL)
        {
            if (i == entry && isFirst == 1)
            {
                break;
                current = current->next;
                nextNode = nextNode->next;
                i++;
            }

            if (i == entry - 1)
                break;
            current = current->next;
            nextNode = nextNode->next;
            i++;
        }
    }

    if (flag == MODIFY)
        printf("Are you sure you want to modify %s %c %d %s?\n", current->name, current->gender, current->age, current->job);
    else if (flag == DELETE && isFirst == 0)
        printf("Are you sure you want to delete %s %c %d %s?\n", nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
    else if (flag == DELETE && isFirst == 1)
        printf("Are you sure you want to delete %s %c %d %s?\n", current->name, current->gender, current->age, current->job);
    answer = validateAnswer();
    if (answer == 'N')
    {
        if (flag == MODIFY)
            printf("No modifications to %s %c %d %s\n", current->name, current->gender, current->age, current->job);
        else if (flag == DELETE && isFirst == 0)
            printf("Employee %s %c %d %s not deleted\n", nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
        else if (flag == DELETE && isFirst == 1)
            printf("Employee %s %c %d %s not deleted\n", current->name, current->gender, current->age, current->job);
        return NULL;
    }
    else
        return current;
}
/*****************************************************************************
Function Name: genderSearch
Purpose:  to return a specific employee to the function that called it. this 
          function finds all the employee whos job match char *searchGender, 
          and then to prompt user to select the employee they want to modify or delete
Function in parameters: emp *headEmp, char *searchGender, int flag
Function out parameter: current
Version: 1
Author: Byron, Jordan, Mariam
*****************************************************************************/
emp *genderSearch(emp *headEmp, char *searchGender, int flag)
{
    int i = 0, genderCount = 0;
    int genderIndex[empCount], entry;
    char answer;
    emp *current = headEmp;
    emp *nextNode = current->next;
    displayCount = 0;

    if (flag == MODIFY)
    {
        if (current->gender == searchGender)
        {

            printf("%d) %s %c %d %s\n", displayCount + 1, current->name, current->gender, current->age, current->job);
            genderIndex[displayCount] = genderCount;
            displayCount++;
        }
        while (nextNode != NULL)
        {
            if (nextNode->gender == searchGender)
            {
                printf("%d) %s %c %d %s\n", displayCount + 1, nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
                genderIndex[displayCount] = genderCount + 1;
                displayCount++;
            }
            current = current->next;
            nextNode = nextNode->next;
            genderCount++;
        }
    }

    else if (flag == DELETE)
    {
        if (current->gender == searchGender)
        {
            printf("%d) %s %c %d %s\n", displayCount + 1, current->name, current->gender, current->age, current->job);
            genderIndex[displayCount] = genderCount;
            displayCount++;
        }
        while (nextNode != NULL)
        {
            if (nextNode->gender == searchGender)
            {
                printf("%d) %s %c %d %s\n", displayCount + 1, nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
                genderIndex[displayCount] = genderCount + 1;
                displayCount++;
            }
            current = current->next;
            nextNode = nextNode->next;

            genderCount++;
        }
    }
    if (displayCount == 0)
    {
        printf("\nNo employees of gender %c\n\n", searchGender);
        return NULL;
    }

    if (flag == MODIFY)
    {
        printf("Select which entry you'd like to modify: ");
        entry = validNum();
        entry = genderIndex[entry - 1];
        if (entry == 0 && headEmp->gender == searchGender)
            isFirst = 1;
        current = headEmp;
        nextNode = current->next;

        while (nextNode != NULL)
        {
            if (i == entry)
                break;
            current = current->next;
            nextNode = nextNode->next;
            i++;
        }
    }
    else if (flag == DELETE)
    {
        printf("Select which entry you'd like to delete: ");
        entry = validNum();
        entry = genderIndex[entry - 1];
        if (entry == 0 && headEmp->gender == searchGender)
            isFirst = 1;

        current = headEmp;
        nextNode = current->next;

        while (nextNode != NULL)
        {
            if (i == entry && isFirst == 1)
            {
                break;
                current = current->next;
                nextNode = nextNode->next;
                i++;
            }

            if (i == entry - 1)
                break;
            current = current->next;
            nextNode = nextNode->next;
            i++;
        }
    }

    if (flag == MODIFY)
        printf("Are you sure you want to modify %s %c %d %s?\n", current->name, current->gender, current->age, current->job);
    else if (flag == DELETE && isFirst == 0)
        printf("Are you sure you want to delete %s %c %d %s?\n", nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
    else if (flag == DELETE && isFirst == 1)
        printf("Are you sure you want to delete %s %c %d %s?\n", current->name, current->gender, current->age, current->job);
    answer = validateAnswer();
    if (answer == 'N')
    {
        if (flag == MODIFY)
            printf("No modifications to %s %c %d %s\n", current->name, current->gender, current->age, current->job);
        else if (flag == DELETE && isFirst == 0)
            printf("Employee %s %c %d %s not deleted\n", nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
        else if (flag == DELETE && isFirst == 1)
            printf("Employee %s %c %d %s not deleted\n", current->name, current->gender, current->age, current->job);
        return NULL;
    }
    else
        return current;
}
/*****************************************************************************
Function Name: ageSearch
Purpose:  to return a specific employee to the function that called it. this 
          function finds all the employee whos job match char *searchAge, and 
          then to prompt user to select the employee they want to modify or delete
Function in parameters: emp *headEmp, char *searchAge, int flag
Function out parameter: current
Version: 2
Author: Byron, Jordan
*****************************************************************************/
emp *ageSearch(emp *headEmp, int *searchAge, int flag)
{
    int i = 0, ageCount = 0;
    int ageIndex[empCount], entry;
    char answer;
    emp *current = headEmp;
    emp *nextNode = current->next;
    displayCount = 0;

    if (flag == MODIFY)
    {
        if (current->age == searchAge)
        {
            printf("%d) %s %c %d %s\n", displayCount + 1, current->name, current->gender, current->age, current->job);
            ageIndex[displayCount] = ageCount;
            displayCount++;
        }
        while (nextNode != NULL)
        {
            if (nextNode->age == searchAge)
            {
                printf("%d) %s %c %d %s\n", displayCount + 1, nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
                ageIndex[displayCount] = ageCount + 1;
                displayCount++;
            }
            current = current->next;
            nextNode = nextNode->next;
            ageCount++;
        }
    }

    else if (flag == DELETE)
    {
        if (current->age == searchAge)
        {
            printf("%d) %s %c %d %s\n", displayCount + 1, current->name, current->gender, current->age, current->job);
            ageIndex[displayCount] = ageCount;
            displayCount++;
        }
        while (nextNode != NULL)
        {
            if (nextNode->age == searchAge)
            {
                printf("%d) %s %c %d %s\n", displayCount + 1, nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
                ageIndex[displayCount] = ageCount;
                displayCount++;
            }
            current = current->next;
            nextNode = nextNode->next;
            ageCount++;
        }
    }
    if (displayCount == 0)
    {
        printf("\nNo employees of age %d\n\n", searchAge);
        return NULL;
    }
    if (flag == MODIFY)
    {
        printf("Select which entry you'd like to modify: ");
        entry = validNum();
        entry = ageIndex[entry - 1];
        if (entry == 0 && headEmp->age == searchAge)
            isFirst = 1;
        current = headEmp;
        nextNode = current->next;

        while (nextNode != NULL)
        {
            if (i == entry)
                break;
            current = current->next;
            nextNode = nextNode->next;
            i++;
        }
    }
    else if (flag == DELETE)
    {
        printf("Select which entry you'd like to delete: ");
        entry = validNum();
        entry = ageIndex[entry - 1];
        if (entry == 0 && headEmp->age == searchAge)
            isFirst = 1;

        current = headEmp;
        nextNode = current->next;

        while (nextNode != NULL)
        {
            if (i == entry && isFirst == 1)
            {
                break;
                current = current->next;
                nextNode = nextNode->next;
                i++;
            }

            if (i == entry - 1)
                break;
            current = current->next;
            nextNode = nextNode->next;
            i++;
        }
    }
    if (flag == MODIFY)
        printf("Are you sure you want to modify %s %c %d %s?\n", current->name, current->gender, current->age, current->job);
    else if (flag == DELETE && isFirst == 0)
        printf("Are you sure you want to delete %s %c %d %s?\n", nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
    else if (flag == DELETE && isFirst == 1)
        printf("Are you sure you want to delete %s %c %d %s?\n", current->name, current->gender, current->age, current->job);
    answer = validateAnswer();
    if (answer == 'N')
    {
        if (flag == MODIFY)
            printf("No modifications to %s %c %d %s\n", current->name, current->gender, current->age, current->job);
        else if (flag == DELETE && isFirst == 0)
            printf("Employee %s %c %d %s not deleted\n", nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
        else if (flag == DELETE && isFirst == 1)
            printf("Employee %s %c %d %s not deleted\n", current->name, current->gender, current->age, current->job);
        return NULL;
    }
    else
        return current;
}
/*****************************************************************************
Function Name: jobSearch
Purpose:  to return a specific employee to the function that called it. this 
          function finds all the employee whos job match char *searchJob, and 
          then to prompt user to select the employee they want to modify or delete
Function in parameters: emp *headEmp, char *searchJob, int flag
Function out parameter: current
Version: 3
Author: Jordan, Byron, Mariam
*****************************************************************************/
emp *jobSearch(emp *headEmp, char *searchJob, int flag)
{
    int i = 0, j, jobCount = 0;
    int jobIndex[empCount], entry;
    char answer, findJob[LENGTH], nextJob[LENGTH], currentJob[LENGTH], firstEmpJob[LENGTH];
    emp *current = headEmp;
    emp *nextNode = current->next;
    strcpy(firstEmpJob, headEmp->job);
    for (j = 0; firstEmpJob[j] != '\0'; j++)
    {
        firstEmpJob[j] = tolower(firstEmpJob[j]);
    }
    j = 0;
    strcpy(currentJob, current->job);
    displayCount = 0;
    strcpy(findJob, searchJob);
    for (j = 0; findJob[j] != '\0'; j++)
    {
        findJob[j] = tolower(findJob[j]);
    }
    j = 0;
    for (j = 0; currentJob[j] != '\0'; j++)
    {
        currentJob[j] = tolower(currentJob[j]);
    }
    j = 0;
    if (flag == MODIFY)
    {
        if (strcmp(currentJob, findJob) == 0)
        {
            printf("%d) %s %c %d %s\n", displayCount + 1, current->name, current->gender, current->age, current->job);
            jobIndex[displayCount] = jobCount;
            displayCount++;
        }
        while (nextNode != NULL)
        {
            strcpy(nextJob, nextNode->job);
            for (j = 0; nextJob[j] != '\0'; j++)
            {
                nextJob[j] = tolower(nextJob[j]);
            }
            j = 0;
            if (strcmp(nextJob, findJob) == 0)
            {
                printf("%d) %s %c %d %s\n", displayCount + 1, nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
                jobIndex[displayCount] = jobCount + 1;
                displayCount++;
            }

            current = current->next;
            nextNode = nextNode->next;
            jobCount++;
        }
    }

    else if (flag == DELETE)
    {
        if (strcmp(currentJob, findJob) == 0)
        {
            printf("%d) %s %c %d %s\n", displayCount + 1, current->name, current->gender, current->age, current->job);
            jobIndex[displayCount] = jobCount;
            displayCount++;
        }
        while (nextNode != NULL)
        {
            strcpy(nextJob, nextNode->job);
            for (j = 0; nextJob[j] != '\0'; j++)
            {
                nextJob[j] = tolower(nextJob[j]);
            }
            j = 0;
            if (strcmp(nextJob, findJob) == 0)
            {
                printf("%d) %s %c %d %s\n", displayCount + 1, nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
                jobIndex[displayCount] = jobCount;
                displayCount++;
            }

            current = current->next;
            nextNode = nextNode->next;
            jobCount++;
        }
    }
    if (displayCount == 0)
    {
        printf("\nNo employees work this job %s\n\n", searchJob);
        return NULL;
    }

    if (flag == MODIFY)
    {
        printf("Select which entry you'd like to modify: ");
        entry = validNum();
        entry = jobIndex[entry - 1];
        if (entry == 0 && headEmp->job == searchJob)
            isFirst = 1;
        current = headEmp;
        nextNode = current->next;

        while (nextNode != NULL)
        {
            if (i == entry)
                break;
            current = current->next;
            nextNode = nextNode->next;
            i++;
        }
    }
    else if (flag == DELETE)
    {
        printf("Select which entry you'd like to delete: ");
        entry = validNum();
        entry = jobIndex[entry - 1];
        if (entry == 0 && (strcmp(firstEmpJob, searchJob)) == 0)
            isFirst = 1;

        current = headEmp;
        nextNode = current->next;

        while (nextNode != NULL)
        {
            if (i == entry && isFirst == 1)
            {
                break;
                current = current->next;
                nextNode = nextNode->next;
                i++;
            }

            if (i == entry - 1)
                break;
            current = current->next;
            nextNode = nextNode->next;
            i++;
        }
    }
    if (flag == MODIFY)
        printf("Are you sure you want to modify %s %c %d %s?\n", current->name, current->gender, current->age, current->job);
    else if (flag == DELETE && isFirst == 0)
        printf("Are you sure you want to delete %s %c %d %s?\n", nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
    else if (flag == DELETE && isFirst == 1)
        printf("Are you sure you want to delete %s %c %d %s?\n", current->name, current->gender, current->age, current->job);
    answer = validateAnswer();
    if (answer == 'N')
    {
        if (flag == MODIFY)
            printf("No modifications to %s %c %d %s\n", current->name, current->gender, current->age, current->job);
        else if (flag == DELETE && isFirst == 0)
            printf("Employee %s %c %d %s not deleted\n", nextNode->name, nextNode->gender, nextNode->age, nextNode->job);
        else if (flag == DELETE && isFirst == 1)
            printf("Employee %s %c %d %s not deleted\n", current->name, current->gender, current->age, current->job);
        return NULL;
    }
    else
        return current;
}
/*****************************************************************************
Function Name: modifyEmpName
Purpose:  to modify the name of the employee that is returned by nameSearch() function
Function in parameters: emp *headEmp, char *nameSearch
Function out parameter: temp
Version: 3
Author: Byron, Jordan, Mariam 
*****************************************************************************/
emp *modifyEmpName(emp *headEmp, char *searchName)
{
    int modFlag = 0;
    char empName[LENGTH];
    emp *temp = nameSearch(headEmp, searchName, modFlag);

    if (temp == NULL)
    {
        return NULL;
    }
    clearBuffer();
    printf("Enter the new Name: ");
    scanf("%[^\n]100s", empName);

    strcpy(temp->name, empName);

    printf("\nEntry successfully modified"
           "\nModified Employee Information: %s %c %d %s\n\n",
           temp->name, temp->gender, temp->age, temp->job);
    return temp;
}
/*****************************************************************************
Function Name: modifyEmpGender
Purpose:  to modify the age of the employee that is returned by genderSearch() function
Function in parameters: emp *headEmp, char *genderSearch
Function out parameter: temp
Version: 3
Author: Byron, Jordan
*****************************************************************************/
emp *modifyEmpGender(emp *headEmp, char *searchGender)
{
    int modFlag = 0;
    char empGender;

    emp *temp = genderSearch(headEmp, searchGender, modFlag);
    if (temp == NULL)
    {
        return NULL;
    }

    printf("Enter the new Gender: ");
    empGender = validateGender();

    temp->gender = empGender;

    printf("\nEntry successfully modified"
           "\nModified Employee Information: %s %c %d %s\n\n",
           temp->name, temp->gender, temp->age, temp->job);
    return temp;
}
/*****************************************************************************
Function Name: modifyEmpAge
Purpose:  to modify the age of the employee that is returned by ageSearch() function
Function in parameters: emp *headEmp, char *ageSearch
Function out parameter: temp
Version: 2
Author: 
*****************************************************************************/
emp *modifyEmpAge(emp *headEmp, int *searchAge)
{
    int modFlag = 0;
    int empAge;

    emp *temp = ageSearch(headEmp, searchAge, modFlag);
    if (temp == NULL)
    {
        return NULL;
    }

    printf("Enter the new Age: ");
    empAge = validateAge();

    temp->age = empAge;

    printf("\nEntry successfully modified"
           "\nModified Employee Information: %s %c %d %s\n\n",
           temp->name, temp->gender, temp->age, temp->job);
    return temp;
}
/*****************************************************************************
Function Name: modifyEmpJob
Purpose:  to modify the job of the employee that is returned by nameSearch() function
Function in parameters: emp *headEmp, char *jobSearch
Function out parameter: temp
Version: 2
Author: Byron, Jordan
*****************************************************************************/
emp *modifyEmpJob(emp *headEmp, char *searchJob)
{
    int modFlag = 0;
    char empJob[LENGTH];
    emp *temp = jobSearch(headEmp, searchJob, modFlag);
    if (temp == NULL)
    {
        return NULL;
    }
    clearBuffer();
    printf("Enter the new Job: ");
    scanf("%[^\n]100s", empJob);

    strcpy(temp->job, empJob);

    printf("\nEntry successfully modified"
           "\nModified Employee Information: %s %c %d %s\n\n",
           temp->name, temp->gender, temp->age, temp->job);
    return temp;
}
/*****************************************************************************
Function Name: deleteEmpName
Purpose:  to delete the employee that is returned by nameSearch() function and 
          then to decrement the total number of employees
Function in parameters: emp *headEmp, char *nameSearch
Function out parameter: void
Version: 2
Author: Byron, Jordan, Mariam
*****************************************************************************/
emp *deleteEmpName(emp *headEmp, char *searchName)
{
    int delFlag = 1;
    emp *current = nameSearch(headEmp, searchName, delFlag);
    emp *nextNode;

    if (current == NULL)
        return NULL;

    if (isFirst == 1)
    {
        head = head->next;
    }
    else
    {
        nextNode = current->next;
        current->next = nextNode->next;
        free(nextNode);
    }
    printf("Entry successfully deleted\n");
    isFirst = 0;
    empCount--;
}
/*****************************************************************************
Function Name: deleteEmpGender
Purpose:  to delete the employee that is returned by genderSearch() function and 
          then to decrement the total number of employees
Function in parameters: emp *headEmp, char *genderSearch
Function out parameter: void
Version: 2
Author: Byron, Jordan, Mariam
*****************************************************************************/
emp *deleteEmpGender(emp *headEmp, char *searchGender)
{
    int delFlag = 1;
    emp *current = genderSearch(headEmp, searchGender, delFlag);
    emp *nextNode;

    if (current == NULL)
        return NULL;

    if (isFirst == 1)
    {
        head = head->next;
    }
    else
    {
        nextNode = current->next;
        current->next = nextNode->next;
        free(nextNode);
    }
    printf("Entry successfully deleted\n");
    isFirst = 0;
    empCount--;
}
/*****************************************************************************
Function Name: deleteEmpAge
Purpose:  to delete the employee that is returned by ageSearch() function and 
          then to decrement the total number of employees
Function in parameters: emp *headEmp, char *searchAge
Function out parameter: void
Version: 2
Author: Byron, Jordan
*****************************************************************************/
emp *deleteEmpAge(emp *headEmp, int *searchAge)
{
    int delFlag = 1;
    emp *current = ageSearch(headEmp, searchAge, delFlag);
    emp *nextNode;

    if (current == NULL)
        return NULL;

    if (isFirst == 1)
    {
        head = head->next;
    }
    else
    {
        nextNode = current->next;
        current->next = nextNode->next;
        free(nextNode);
    }
    printf("Entry successfully deleted\n");
    isFirst = 0;
    empCount--;
}
/*****************************************************************************
Function Name: deleteEmpJob
Purpose:  to delete the employee that is returned by jobSearch() function and 
          then to decrement the total number of employees
Function in parameters: emp *headEmp, char *searchJob
Function out parameter: void
Version: 2
Author: Byron, Jordan, Mariam
*****************************************************************************/
emp *deleteEmpJob(emp *headEmp, char *searchJob)
{
    int delFlag = 1;
    emp *current = jobSearch(headEmp, searchJob, delFlag);
    emp *nextNode;

    if (current == NULL)
        return NULL;

    if (isFirst == 1)
    {
        head = head->next;
    }
    else
    {
        nextNode = current->next;
        current->next = nextNode->next;
        free(nextNode);
    }
    printf("Entry successfully deleted\n");
    isFirst = 0;
    empCount--;
}
/*****************************************************************************
Function Name: sort
Purpose:  the purpose of this function is to sort through the linked list and 
          rearrange the employees in alphabetical order
Function in parameters: emp *headEmp
Function out parameter: emp1
Version: 4
Author: Byron, Jordan, (earlier version by Mariam)
*****************************************************************************/
emp *sort(emp *headEmp)
{
    emp *emp1, *emp2, *temp;
    char firstName[LENGTH], secondName[LENGTH];
    int changed = 1, j = 0;

    if ((temp = (emp *)malloc(sizeof(emp))) == NULL)
    {
        fprintf(stderr, "Memory Allocation error.\n");

        exit(1);
    }

    temp->next = headEmp;
    if (headEmp != NULL && headEmp->next != NULL)
    {

        while (changed)
        {
            changed = 0;
            emp2 = temp;
            emp1 = temp->next;
            while (emp1->next != NULL)
            {

                strcpy(firstName, emp1->name);
                for (j = 0; firstName[j] != '\0'; j++)
                {
                    firstName[j] = tolower(firstName[j]);
                }
                j = 0;

                strcpy(secondName, emp1->next->name);
                for (j = 0; secondName[j] != '\0'; j++)
                {
                    secondName[j] = tolower(secondName[j]);
                }
                j = 0;

                if (strcmp(firstName, secondName) > 0)
                {
                    emp2->next = swap(emp1, emp1->next);
                    changed = 1;
                }
                emp2 = emp1;
                if (emp1->next != NULL)
                    emp1 = emp1->next;
            }
        }
    }
    emp1 = temp->next;
    free(temp);
    return emp1;
}
/*****************************************************************************
Function Name: swap
Purpose:  this function is called by sort and will swap the places of two 
          employees passed in as arguments
Function in parameters: emp *emp1, emp *emp2
Function out parameter: returnEmp
Version: 3
Author: Jordan
*****************************************************************************/
emp *swap(emp *emp1, emp *emp2)
{
    emp1->next = emp2->next;
    emp2->next = emp1;
    return emp2;
}
/*****************************************************************************
Function Name: append
Purpose:  to add an employee to the end of the list
Function in parameters: emp *start
Function out parameter: returnEmp
Version: 5
Author: Jordan, Byron, (earlier version by Mariam)
*****************************************************************************/
emp *insert(emp *headEmp)
{
    emp *newEmp, *lastEmp, *returnEmp;
    char empName[LENGTH], empJob[LENGTH], empGender;
    int empAge;

    if ((newEmp = (emp *)malloc(sizeof(emp))) == NULL)
    {
        fprintf(stderr, "Memory Allocation error.\n");
        exit(1);
    }

    if (headEmp == NULL)
        returnEmp = newEmp;
    else
    {
        returnEmp = headEmp;
        lastEmp = headEmp;
        while (lastEmp->next != NULL)
            lastEmp = lastEmp->next;
        lastEmp->next = newEmp;
    }
    clearBuffer();
    printf("Enter name: ");
    scanf("%100[^\n]s", empName);
    clearBuffer();
    printf("Enter Gender: ");
    empGender = validateGender();
    printf("Enter age: ");
    empAge = validateAge();
    printf("Job Profile: ");
    scanf("%100[^\n]s", empJob);
    clearBuffer();
    strcpy(newEmp->name, empName);
    strcpy(newEmp->job, empJob);
    newEmp->gender = empGender;
    newEmp->age = empAge;
    printf("%s", newEmp->name);
    empCount++;

    newEmp->next = NULL;
    return returnEmp;
}
/*****************************************************************************
Function Name: displayList
Purpose:  to print all of the employees in the linked list
Function in parameters: emp *headEmp
Function out parameter: void
Version: 4
Author: Jordan, Byron, Mariam , David
*****************************************************************************/
void displayList(emp *headEmp)
{
    int j = 1;
    if (empCount == 0)
    {
        printf("\nNo employees to display\n");
    }
    else
    {
        printf("\nTotal number of employees: %d\n", empCount);
        while (headEmp != NULL)
        {
            printf("%d) Employee name: %s    Gender: %c    Age: %d    Job profile: %s\n",
                   j, headEmp->name, headEmp->gender, headEmp->age, headEmp->job);
            headEmp = headEmp->next;
            j++;
        }
    }
}