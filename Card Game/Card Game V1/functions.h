/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <ctype.h>
#include <string.h>

/* Constants */
#define INSTRUCTIONS 1
#define SHUFFLE_DECK 2
#define SHOW_DECK 3
#define PLAY_GAME 4
#define EXIT 5
#define DECK_SIZE 52
#define NUM_SUITS 4
#define SUIT_LENGTH 9
#define NUM_FACES 13
#define FACE_LENGTH 6
#define WIN 0
#define LOSS 1
#define QUIT 'Q'
#define ENTER '\n'
#define MAIN_MENU 3

/* Structs */
typedef struct card 
{
    char suits[SUIT_LENGTH];
    char faces[FACE_LENGTH];
} card;

/* Variables */
card *cardDeck, *player, *computer, *cardHand;
int cardCount;

/* Function prototypes */
int menu(void);
void printInstructions(void);
card *createDeck(int deck);
void displayDeck(card *cardDeck);
void shuffleDeck(card *cardDeck);
int playGame(card *cardDeck);
int validnumCards(void);
card *giveCard(int numCards, card *cardDeck);
int *dealCards(card *cardDeck);
int compareCards(card *player, card *computer);
int faceRank(card cards);
int suitRank(card cards);
void lineSeparator(void);
void clearBuffer(void);