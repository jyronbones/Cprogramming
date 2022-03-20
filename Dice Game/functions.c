/*
 * Title: Assignment 1 -- Dice Game Implementation
 * Course: CST8234 C Language
 * @Author: Mariam Collins(040911894), Byron Jones (040585687), Jordan Kent(040607241), David Sun(041031332)
 * Professor: Surbhi Bahri
 * Due date: 03/13/22
 * Submission date: 03/13/22
 */

#include "functions.h"

/*****************************************************************************
Function Name: game()
Purpose: game() implements instructions that will allow the user to play a 
        game of chance against the computer. game() calls functions that allow 
        the user to bet, roll dice, quit... etc. game() also records users wins, 
        losses and winnings, displaying them upon program exit.
Function in parameters: void
Function out parameter: int EXIT_SUCCESS
Version: 1
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
int game(void)
{
    int totalGames = 0, gamesWon = 0, money = DEFAULT_MONEY, bet;

    do
    {
        if (playerChoice() == YES)
        {
        START:
            if (money > 0)
            {
                printf("Let's begin\n");
                if (betChoice() == YES) /* play for money */
                {
                    bet = betAmount(money);
                    if (playGame() == 1)
                    {
                        money += (bet * 5 * 3);
                        gamesWon++;
                        totalGames++;
                    }
                    else
                    {
                        totalGames++;
                        money -= (bet * 5);
                        if (money == 0)
                        {
                            goto START;
                        }
                    }
                    if (playAgainChoice() == YES)
                        goto START;
                    else
                        goto GOODBYE;
                }
                else /*play for free */
                    printf("You are now playing for free\n");
                    if (playGame() == 1)
                    {
                        gamesWon++;
                        totalGames++;
                    }
                    else
                    {
                        totalGames++;
                    }
                    if (playAgainChoice() == YES)
                        goto START;
                    else
                        goto GOODBYE;
            }
            else
            {
                printf("You have no more funds. Start-over [y/n]? ");
                if (startOver() == YES)
                {
                    money = DEFAULT_MONEY;
                    printf("Game has reset, game on.\n");
                    goto START;
                }
                else
                    goto GOODBYE;
            }
        }
        else
        {
        GOODBYE:
            printf("You have $%d, won %d games and lost %d games \n", money, gamesWon, totalGames - gamesWon);
            printf("Thank you for playing. Goodbye\n");
            return EXIT_SUCCESS;
        }

    } while (1); /* loops the game until user quits */
}

/*****************************************************************************
Function Name: playGame()
Purpose: playGame() prompts the user to roll the dice (by calling rollDice()) 
        or quit the game and return to its calling function. playGame() compares 
        each round of dice rolls between the computer and determines the winner 
        of the round. 
Function in parameters: void
Function out parameter: int WON or int LOSE
Version: 2
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
int playGame(void)
{
    int i, j, sum, sum2, pMatch = 0, playerRoll1, playerRoll2, compRoll1, compRoll2, rollNum = 0;
    int(*arr)[COLUMNS] = calloc(MAX_ROUNDS, sizeof *arr);
    char choice;
REPEAT:
    printf("%60s\n", "ROLL THE DICE [ENTER], to QUIT enter[q]");
    while ((choice = getchar()) != QUIT && choice != ENTER)
    {
        printf("Invalid entry\n");
        clearBuffer();
        goto REPEAT;
    }
    switch (choice)
    {
    case ENTER: /* user pushed enter */
        displayHeader();
        playerRoll1 = rollDice();
        playerRoll2 = rollDice();
        compRoll1 = rollDice();
        compRoll2 = rollDice();

        arr[rollNum][0] = rollNum;
        arr[rollNum][1] = playerRoll1;
        arr[rollNum][2] = playerRoll2;
        arr[rollNum][3] = playerRoll1 + playerRoll2;
        arr[rollNum][4] = pMatch = arr[0][3];

        for (i = 0; i < rollNum + 1; i++) /* iterates each roll*/
        {
            for (j = 0; j < COLUMNS; j++) /* prints the results of the roll*/
                printf("%15d ", arr[i][j]);
            printf("\n");
        }
        break;

    case QUIT: /* user entered q */
        printf("You decided to quit and you loose this round and the money you bet\n");
        return (LOSE);
    }
    sum = playerRoll1 + playerRoll2;
    sum2 = compRoll1 + compRoll2;
    if (sum == 7 || sum == 11 || (sum == pMatch && rollNum != 0))
    {
        printf("Congratulations, you roll %d and win on your ", sum);
        roundPrint(rollNum);
        printf(" try\n");
        free(arr);
        return WON;
    }
    else if (sum == 2 || sum == 3 || sum == 12)
    {
        printf("You rolled %d the losing match. You lose.\n", sum);
        free(arr);
        return LOSE;
    }
    else if (sum2 == 7 || sum2 == 11 || (sum2 == pMatch && rollNum != 0))
    {
        printf("Sorry, computer rolled %d winning the match and you lose\n", sum2);
        free(arr);
        return LOSE;
    }
    else if (sum2 == 2 || sum2 == 3 || sum2 == 12)
    {
        printf("Congratulations computer rolled %d the losing match, and you WIN!!\n", sum2);
        free(arr);
        return WON;
    }
    else
    {
        printf("Computer rolled %d, game continues...\n", sum2);
    }
    rollNum++;
    goto REPEAT;
}

/*****************************************************************************
Function Name: rollDice()
Purpose: rollDice() implements rand() to get a random number between 1 and 6. 
Function in parameters: void
Function out parameter: int randNum
Version: 4
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
int rollDice(void)
{
    srand(clock());
    int randNum = (rand() % 6) + 1;
    return randNum;
}

/*****************************************************************************
Function Name: clearBuffer(void)
Purpose: Clear the input buffer before or after accepting input from the user.
Function in parameters: void
Function out parameter: void
Version: 2
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
void clearBuffer(void)
{
    while (getchar() != '\n');
}

/*****************************************************************************
Function Name: playerChoice()
Purpose: prompts the user to enter either "Y" or "N" (representing yes or no) 
        and saves it in an array of characters. playChoice() validates the users 
        input and returns the character at index[0] if it is either 'Y' or 'N'
Function in parameters: void
Function out parameter: char input[0]
Version: 2
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
char playerChoice(void)
{
    char input[MAX_MESSAGE];
    int isValid = 0;
    char yes[] = "Y";
    char no[] = "N";

    printf("Please enter [y or Y] to play Dice or [n or N] to exit: ");
    scanf("%2s", &input);
    clearBuffer();

    int i;

    for (i = 0; i < strlen(input); i++) /* converts user entered input to uppercase */
    {
        input[i] = toupper(input[i]);
    }
    do
    {
        if ((strcmp(yes, input) == 0) || (strcmp(no, input) == 0))
        {
            isValid == 1;
            break;
        }
        else
        {
            printf("Invalid option\n");
            printf("Please enter [y or Y] to play Dice or [n or N] to exit: ");
            scanf(" %2s", &input);
            clearBuffer();
            for (i = 0; i < strlen(input); i++) /* converts user entered input to uppercase*/
            {
                input[i] = toupper(input[i]);
            }
            continue;
        }
    } while (isValid == 0); /* loop until input is valid */

    return input[0];
}

/*****************************************************************************
Function Name: betChoice()
Purpose: prompts the user to enter either "Y" or "N" (representing yes or no) 
        and saves it in an array of characters. betChoice() validates the users 
        input and returns the character at index[0] if it is either 'Y' or 'N'
Function in parameters: void
Function out parameter: char input[0]
Version: 2
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
char betChoice(void)
{
    char input[MAX_MESSAGE];
    int isValid = 0;
    char yes[] = "Y";
    char no[] = "N";

    printf("would you like to bet? [y/n]: ");
    scanf("%2s", &input);
    clearBuffer();

    int i;

    for (i = 0; i < strlen(input); i++) /* converts user entered input to uppercase*/
    {
        input[i] = toupper(input[i]);
    }
    do
    {
        if ((strcmp(yes, input) == 0) || (strcmp(no, input) == 0))
        {
            isValid == 1;
            break;
        }
        else
        {
            printf("Invalid option\n");
            printf("would you like to bet? [y/n]: ");
            scanf(" %2s", &input);
            clearBuffer();
            for (i = 0; i < strlen(input); i++) /* converts user entered input to uppercase*/
            {
                input[i] = toupper(input[i]);
            }
            continue;
        }
    } while (isValid == 0); /* loop until input is valid */

    return input[0];
}

/*****************************************************************************
Function Name: startOver()
Purpose: prompts the user to enter either "Y" or "N" (representing yes or no) 
        and saves it in an array of characters. startOver() validates the users 
        input and returns the character at index[0] if it is either 'Y' or 'N'
Function in parameters: void
Function out parameter: char input[0]
Version: 2
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
char startOver(void)
{
    char input[MAX_MESSAGE];
    int isValid = 0;
    char yes[] = "Y";
    char no[] = "N";

    scanf("%2s", &input);
    clearBuffer();

    int i;

    for (i = 0; i < strlen(input); i++) /* converts user entered input to uppercase*/
    {
        input[i] = toupper(input[i]);
    }
    do
    {
        if ((strcmp(yes, input) == 0) || (strcmp(no, input) == 0))
        {
            isValid == 1;
            break;
        }
        else
        {
            printf("Invalid option\n");
            printf("You have no more funds. Start-over [y/n]? ");
            scanf(" %2s", &input);
            clearBuffer();
            for (i = 0; i < strlen(input); i++) /* converts user entered input to uppercase*/
            {
                input[i] = toupper(input[i]);
            }
            continue;
        }
    } while (isValid == 0); /* loop until input is valid */

    return input[0];
}

/*****************************************************************************
Function Name: playAgainChoice()
Purpose: prompts the user to enter either "Y" or "N" (representing yes or no) 
        and saves it in an array of characters. playAgainChoice() validates the users 
        input and returns the character at index[0] if it is either 'Y' or 'N'
Function in parameters: void
Function out parameter: char input[0]
Version: 2
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
char playAgainChoice(void)
{
    char input[MAX_MESSAGE];
    int isValid = 0;
    char yes[] = "Y";
    char no[] = "N";

    printf("play another game? [y/n] ");
    scanf("%2s", &input);
    clearBuffer();

    int i;

    for (i = 0; i < strlen(input); i++) /* converts user entered input to uppercase*/
    {
        input[i] = toupper(input[i]);
    }
    do
    {
        if ((strcmp(yes, input) == 0) || (strcmp(no, input) == 0))
        {
            isValid == 1;
            break;
        }
        else
        {
            printf("Invalid option\n");
            printf("play another game? [y/n] ");
            scanf(" %2s", &input);
            clearBuffer();
            for (i = 0; i < strlen(input); i++) /* converts user entered input to uppercase*/
            {
                input[i] = toupper(input[i]);
            }
            continue;
        }
    } while (isValid == 0); /* loop until input is valid */

    return input[0];
}

/*****************************************************************************
Function Name: betAmount()
Purpose: Prompt the user for a bet amount and validates that the bet is of type
        int and that the user has enough funds for the bet.
Function in parameters: int money
Function out parameter: int bet
Version: 2
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
int betAmount(int money)
{
    int bet;
    char term;
    printf("You have $%d, minimum bet is $5, you can make %d total bet(s) ", money, money / 5);
    while (1) /* loop until valid bet */
    {
        if (scanf(" %d%c", &bet, &term) != 2 || term != '\n') /** checks for whole number **/
        {

            clearBuffer();
            printf("Invalid bet\n");
            printf("Enter a number between 1 - %d\n", money / 5);
            printf("You have $%d, minimum bet is $5, you can make %d total bet(s) ", money, money / 5);

            continue; /** cycle loop **/
        }
        else /** then checks bet condition **/
        {
            if (bet < 1 || bet > (money / 5)) /** bet min and max condition **/
            {
                printf("Invalid bet\n");
                printf("Enter a number between 1 - %d\n", money / 5);
                printf("You have $%d, minimum bet is $5, you can make %d total bet(s) ", money, money / 5);

                continue; /** cycle loop **/ 
            }
            else /* bet is accepted **/
            {
                printf("Your bet is $%d\n", bet * 5);
                break;
            }
        }
    }
    return bet;
}

/*****************************************************************************
Function Name: roundPrint()
Purpose: takes the round number and prints the round with the appropriate 
        string ending.
Function in parameters: int round
Function out parameter: void
Version: 1
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
void roundPrint(int round)
{
    switch (round)
    {
        case 0: /* first roll */
            printf("first");
            break;
        case 1: /* second roll */
            printf("%dnd", round + 1);
            break;
        case 2: /* third roll */
            printf("%drd", round + 1);
            break;
        default: /* roll 4 or higher */
            printf("%dth", round + 1);
            break;
    }
}

/*****************************************************************************
Function Name: displayHeader()
Purpose: Displays the header for the table.
Function in parameters: void
Function out parameter: void
Version: 1
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
void displayHeader()
{
    printTitle();
}

/*****************************************************************************
Function Name: printTitle()
Purpose: Prints the column names in the header for the table displayed.
Function in parameters: void
Function out parameter: void
Version: 1
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
void printTitle()
{
    headerLine();
    printf("\n %14s %15s %15s %15s %16s", "ROLL NUM", "DICE#1", "DICE#2", "TOTAL ROLL", "POINT MATCH\n");
    headerLine();
    printf("\n");
}

/*****************************************************************************
Function Name: headerLine()
Purpose: Creates a line of '-' characters used for header separation.
Function in parameters: void
Function out parameter: void
Version: 1
Author: Mariam Collins, Byron Jones, Jordan Kent, David Sun
*****************************************************************************/
void headerLine()
{
    int i;
    for (i = 0; i < 79; i++)
    {
        printf("-");
    }
}
