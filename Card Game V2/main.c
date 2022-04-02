/*
 * Title: Assignment 1 -- Dice Game Implementation
 * Course: CST8234 C Language
 * @Author: Byron Jones (040585687)
 * Professor: Surbhi Bahri
 * Due date: 03/13/22
 * Submission date: 03/13/22
 */

#include "functions.h"

/*****************************************************************************
Function Name: main()
Purpose: run the program with menu selection
Function in parameters: void
Function out parameter: EXIT_SUCCESS
Version: 1
Author: Byron Jones
*****************************************************************************/
int main()
{
    int i, wins = 0, losses = 0, numCards, score;
        int **cardDeck = createDeck();

    while (1)
    {
        switch(menu())
        {
            case INSTRUCTIONS: /* print game instructions */
            printInstructions();
            break;

            case SHUFFLE_DECK: /* shuffles card deck */
            shuffleDeck(cardDeck);
            break;

            case SHOW_DECK: /* displays current card deck order */
            displayDeck(cardDeck);
            break;

            case PLAY_GAME: /* plays card game against computer */
            if (cardCount == 52) {
                printf("You have no more cards left in the deck, re-shuffle to keep playing.\n");
                break;
            }
            if (cardCount == 0)
                printf("You have a fresh deck of %d Cards. How many rounds would you like to deal?\n", DECK_SIZE);
            else
                printf("You have %d cards left in the deck. How many rounds would you like to deal?\n", DECK_SIZE - cardCount);
            numCards = validnumCards();

            for (i = 0; i < numCards; i++) /* allows user to play as many hands as user entered */
            {
                score = playGame(cardDeck);
                if (score == WIN)
                    wins++;
                else if (score == LOSS)
                    losses++;
                else
                break;
            }
            break;

            case EXIT: /* quits the game relaying wins/losses */
            if (wins > losses)
                printf("Lucky you. You had %d wins and %d losses. Time to buy a lottery ticket\n", wins, losses);
            else if (wins < losses)
                printf("Unlucky. You had %d losses and %d wins. Maybe next time you'll get more lucky\n", losses, wins);
            else
                printf("Your luck went both ways. You had %d wins and %d losses\n", wins, losses);
            free(player);
            free(computer);
            return EXIT_SUCCESS;

            default:
            printf("Invalid selection\n");
            break;
        }
    }
    return EXIT_SUCCESS;
}