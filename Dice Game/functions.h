/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <ctype.h>
#include <string.h>

/* Constants */
#define DEFAULT_MONEY 50
#define WON 1
#define LOSE 0
#define COLUMNS 5
#define MAX_ROUNDS 10
#define ENTER '\n'
#define QUIT 'q'
#define YES 'Y'
#define MAX_MESSAGE 3

/* Function prototypes */
int game(void);
int rollDice(void);
int playGame(void);
void clearBuffer(void);
char playerChoice(void);
char betChoice(void);
char playAgainChoice(void);
char startOver(void);
int betAmount(int money);
void roundPrint(int round);
void displayHeader(void);
void printTitle(void);
void headerLine(void);
