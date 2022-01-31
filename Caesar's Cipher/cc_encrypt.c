/******************************************************************************/
/*Filename: cc_decrypt.c
 *Author/Student Name: Byron Jones 
 *Student Number: 040585687 
 *Assignment: Lab 2 - Caesar's Cipher
 *Course: C Language - CST8234
 *Professor: Surbhi Bahri
 *Due Date: 02-06-22
 *Purpose: Caesar's Cipher encryption of messages
*******************************************************************************/

/******************************************************************************/
/* Declare include files
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/******************************************************************************/
/* Files defines */
#define MAX_MESSAGE 80

/******************************************************************************/
/* Main
*******************************************************************************/
int main()
{
    char message[MAX_MESSAGE];
    int key = -1, i;

    /* Asks user for message to encrypt */
    printf("Enter message to Encrypt:\n");
    scanf("%[^\n]*c", message);

    /* Checks if message contains more than 80 characters, terminating if so */
    if (strlen(message) > MAX_MESSAGE)
    {
        printf("Error - Message is too long\n");
        exit(EXIT_FAILURE);
    }

    /* Continually asks user for key value until key is between 0 and 26 */
    while (key < 0 || key > 26)
    {
        printf("Enter rotation key:\n");
        scanf("%d", &key);
        
        /* Displays error message and clears input buffer if key is not between 0 and 26 */
        if (key < 0 || key > 26)
        {
            printf("Error - key must be in range 0 and 26. Try again.\n");
            while (getchar() != '\n');
        }
    }

    printf("\nEncrypting message (key = %i): %s\n", key, message);

    /* Loops through the message until null terminator */
    for (i = 0; i < strlen(message); i++)
    {
        /* Encrypts character in message if character is lowercase and between a and z */
        if (islower(i) == 0 && message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] + key) - 'a') % 26 + 'a';
        }
        /* Decrypts character in message if character is uppercase and between A and Z */
        else if (isalpha(i) == 0 && message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] + key) - 'A') % 26 + 'A';
        }
    }
    printf("\n%s\n", message);
    exit(EXIT_SUCCESS);
}