
#include "functions.h"

/*****************************************************************************
Function Name: menu()
Purpose: Displays option menu allowing user input for menu selection.
Function in parameters: void
Function out parameter: int num
Version: 2
Author: Byron Jones
*****************************************************************************/
int menu(void)
{
    int num;
    char term;
	printf(
        "Choose an option which suits your needs!\n"
        "1. Show game instructions\n"
        "2. Generate a Shuffled Deck\n"
        "3. Show Deck\n"
        "4. Play a game\n"
        "5. Quit\n"
    );

	while (1) /* loop until valid whole number */
    {
        if (scanf(" %d%c", &num, &term) != 2 || term != '\n') /** checks for whole number **/
        {

            clearBuffer();
            printf(
                "Invalid selection\n"
                "Choose an option which suits your needs!\n"
                "1. Show game instructions\n"
                "2. Generate a Shuffled Deck\n"
                "3. Show Deck\n"
                "4. Play a game\n"
                "5. Quit\n"
            );

            continue; /** cycle loop **/
        }
        else /** valid whole number **/
        {
            break;
        }
    }
	return num;
}

/*****************************************************************************
Function Name: printInstructions(void)
Purpose: Prints a list of game instructions.
Function in parameters: void
Function out parameter: void
Version: 2
Author: Byron Jones
*****************************************************************************/
void printInstructions(void)
{
    printf(
        "\nWELCOME TO THE CARD GAME\n"
        "This card game is fairly straight forwards.\n"
        "The goal of the game is to draw cards from the deck and place them down against your opponent\n"
        "In this case, it's the computer but maybe one day there will be another live person :D\n"
        "Anyways, the rules are fairly straight forward. 13 card values and 4 suites.\n"
        "The card value rankings from highest to lowest are Ace,K,Q,J,10,9,8,7,6,5,4,3,2\n"
        "As for Suits, if the value of the drawn cards are the same, Spades beats Hearts, which beats Diamonds who beats Clubs.\n"
        "And that's it! Fairly straight forward right?!\n\n"
    );
}

/*****************************************************************************
Function Name: *createDeck(void)
Purpose: Creates a standard 52 card deck with 4 suits each with 13 faces.
Function in parameters: int deck
Function out parameter: int cardDeck
Version: 2
Author: Byron Jones
*****************************************************************************/
int ***createDeck(void) {
    static int cardDeck[NUM_SUITS][NUM_FACES]={
            {101,102,103,104,105,106,107,108,109,110,111,112,113},
            {201,202,203,204,205,206,207,208,209,210,211,212,213},
            {301,302,303,304,305,306,307,308,309,310,311,312,313},
            {401,402,403,404,405,406,407,408,409,410,411,412,413}
            }; 
    return cardDeck;
}

/*****************************************************************************
Function Name: getFace()
Purpose: Get the face of the card
Function in parameters: int card
Function out parameter: char face[n]
Version: 2
Author: Byron Jones
*****************************************************************************/
char *getFace(int card)
{
    int i;
    char *faces[NUM_FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    
    i = (card % 100) - 1;
    return faces[i];
}

/*****************************************************************************
Function Name: getSuit()
Purpose: Get the suit of the card
Function in parameters: int card
Function out parameter: char suit[n]
Version: 2
Author: Byron Jones
*****************************************************************************/
char *getSuit(int card)
{
    int i;
    char *suits[NUM_SUITS] = {"Spades", "Hearts", "Diamonds", "Clubs"};

    i = (card / 100) - 1;
    return suits[i];
}

/*****************************************************************************
Function Name: displayDeck()
Purpose: Displays the card deck in current order
Function in parameters: card *cardDeck
Function out parameter: void
Version: 2
Author: Byron Jones
*****************************************************************************/
void displayDeck(int cardDeck[NUM_SUITS][NUM_FACES])
{
     int i, j, counter = 0;

    printf("\nThe Deck in Hand Currently looks like:\n");
    lineSeparator();

    for(i = 0;i < NUM_SUITS; i++){    
        for(j = 0;j < NUM_FACES; j++){    
            printf("%s of %s  ",getFace(cardDeck[i][j]), getSuit(cardDeck[i][j]));  
            counter++;
            if (counter % 4 == 0)
            printf("\n");  
        } 
    }
    lineSeparator();
    printf("\n"); 

}

/*****************************************************************************
Function Name: displayDeck()
Purpose: Shuffles the card deck by randomly rearranging the card indexes.
Function in parameters: card *cardDeck
Function out parameter: void
Version: 2
Author: Byron Jones
*****************************************************************************/
void shuffleDeck(int cardDeck[NUM_SUITS][NUM_FACES])
{
    int i, j, k, r, tempCard;
    cardCount = faceCount = suitCount = 0;
    srand(clock());
    r = rand() % DECK_SIZE + NUM_FACES;
    printf("\nDeck made. Currently Shuffling...... Please Wait...\n\n");
    for (k = 0; k < r; k++) { /* shuffles the elements by a random number of times */
        for (i = 0; i< NUM_SUITS; i++) /* randomizes the row or suit */
        {
            r = i + (rand() % (NUM_SUITS - i));
            for (j = 0; j < NUM_FACES; j++) /* randomizes the column or face */
            {
                int r2 = i + (rand() % (NUM_FACES - i));
                tempCard = cardDeck[i][j];
                cardDeck[i][j] = cardDeck[r][r2];
                cardDeck[r][r2] = tempCard;
            }
        }
    }
}

/*****************************************************************************
Function Name: playGame()
Purpose: Allows the user to play and press enter to deal cards or Q to quit.
Function in parameters: card *cardDeck
Function out parameter: int WIN or int LOSS
Version: 2
Author: Byron Jones
*****************************************************************************/
int playGame(int cardDeck[NUM_SUITS][NUM_FACES]) {
    int i;
    char choice;

    REPEAT:
    printf("Enter to play or Q to quit\n");
    while ((choice = getchar()) != QUIT && choice != ENTER) /* input validation ensuring only enter and Q are selected */
    {
        printf("Invalid entry\n");
        clearBuffer();
        goto REPEAT;
    }
        
    switch (choice)
    {
    case ENTER: /* user pushes enter to play*/
        if (dealCards(cardDeck) == 0) {
            return WIN;
        }
        else {
            return LOSS;
        }
    break;

    case QUIT: /* user entered Q to quit*/
        return MAIN_MENU;
        break;
    }
}

/*****************************************************************************
Function Name: validNumCards()
Purpose: validates that user entry for number of cards to deal is an integer
        within the range of cards left within the deck.
Function in parameters: card *cardDeck
Function out parameter: int num
Version: 2
Author: Byron Jones
*****************************************************************************/
int validnumCards() {
    int num;
    char term;

        while (1) /* loop until valid number of cards to deal */
    {
        if (scanf(" %d%c", &num, &term) != 2 || term != '\n') /** checks for whole number **/
        {

            clearBuffer();
            if (cardCount == 50)
                printf("Invalid number of rounds, you only have enough cards for %d round:\n", (DECK_SIZE- cardCount) / 2);
            else
                printf("Invalid number of rounds, enter a number from 1-%d:\n", (DECK_SIZE- cardCount) / 2);

            continue; /** cycle loop **/
        }
        else /** check card deal condition **/
        {
            if (num < 1 || num > (DECK_SIZE - cardCount) / 2) /** card deal min and max condition **/
            {
            if (cardCount == 50)
                printf("Invalid number of rounds, only enough cards in the deck for %d round:\n", (DECK_SIZE- cardCount) / 2);
            else
                printf("Invalid number of rounds, enter a number from 1-%d:\n", (DECK_SIZE- cardCount) / 2);


                continue; /** cycle loop **/ 
            }
            else /* valid number of cards **/
            {
                break;
            }
        }
    }
    return num;
}

/*****************************************************************************
Function Name: *giveCard()
Purpose: Assigns the next card from the front of the deck to a hand
Function in parameters: int numCards, card *cardDeck
Function out parameter: card cardHand
Version: 2
Author: Byron Jones
*****************************************************************************/
card *giveCard(int numCards, int cardDeck[NUM_SUITS][NUM_FACES])
{

    cardHand = malloc(sizeof(card) * numCards);
    int i;
    for (i = 0; i < numCards; i++) { /* assigns a card from the deck to card the card hand*/
        strcpy(cardHand[i].faces, (getFace(cardDeck[suitCount][faceCount])));
        strcat(cardHand[i].suits, (getSuit(cardDeck[suitCount][faceCount++])));
    }

    if (faceCount >= NUM_FACES) {
    faceCount = 0;
    suitCount++;
    }
    cardCount++;
    return cardHand;
}

/*****************************************************************************
Function Name: *dealCards()
Purpose: Deals the card hands respectively to player and computer determining
        who wins or loses, relaying results back to main.
Function in parameters: card *cardDeck
Function out parameter: int WIN or int LOSS
Version: 2
Author: Byron Jones
*****************************************************************************/
int *dealCards(int cardDeck[NUM_SUITS][NUM_FACES])
{
    int card = 0;

    player = giveCard(1, cardDeck);
    computer = giveCard(1, cardDeck);
    printf("IN ONE SWIFT MOTION, YOU SLAM DOWN A %s of %s!!!!!!!!!!\n", player[card].faces, player[card].suits);
    printf("Up next, the computer whips out a.......\n");
    printf("%s of %s!!!!!\n", computer[card].faces, computer[card].suits);
    
    if (compareCards(player, computer) == 0) 
    {
        printf("You win this round. +1 wins to YOU!.\n\n");
        return WIN;
    }
    else
    {
        printf("The computer won the duel, +1 wins to the computer.\n\n");
        return LOSS;
    }
}

/*****************************************************************************
Function Name: compareCards()
Purpose: Boolean function comparing player and computer card hands used to
        determine which hand wins.
Function in parameters: card *player, card *computer
Function out parameter: int WIN or int LOSS
Version: 1
Author: Byron Jones
*****************************************************************************/
int compareCards(card *player, card *computer) {
    if (faceRank(*player) == faceRank(*computer)) 
    {
        if (suitRank(*player) > suitRank(*computer)) 
        {
            return WIN;
        }
        else 
        {
            return LOSS;
        }
    }
    else if (faceRank(*player) > faceRank(*computer)) 
    {
        return WIN;
    }
    else 
    {
        return LOSS;
    }
}

/*****************************************************************************
Function Name: faceRank()
Purpose: Ranks the faces of cards, Ace being the highest down to two.
Function in parameters: card cards
Function out parameter: int 2-14
Version: 1
Author: Byron Jones
*****************************************************************************/
int faceRank(card cards)
{
    if (strcmp(cards.faces,"Ace") == 0)
    return 14;
    if (strcmp(cards.faces,"King") == 0)
    return 13;
    if (strcmp(cards.faces,"Queen") == 0)
    return 12;
    if (strcmp(cards.faces,"Jack") == 0)
    return 11;
    if (strcmp(cards.faces,"Ten") == 0)
    return 10;
    if (strcmp(cards.faces,"Nine") == 0)
    return 9;
    if (strcmp(cards.faces,"Eight") == 0)
    return 8;
    if (strcmp(cards.faces,"Seven") == 0)
    return 7;
    if (strcmp(cards.faces,"Six") == 0)
    return 6;
    if (strcmp(cards.faces,"Five") == 0)
    return 5;
    if (strcmp(cards.faces,"Four") == 0)
    return 4;
    if (strcmp(cards.faces,"Three") == 0)
    return 3;
    if (strcmp(cards.faces,"Two") == 0)
    return 2;
}

/*****************************************************************************
Function Name: suitRank()
Purpose: Ranks the suits of cards, Spades followed by hearts, diamonds and
        clubs, each trumping the followings.
Function in parameters: card cards
Function out parameter: int 1-4
Version: 1
Author: Byron Jones
*****************************************************************************/
int suitRank(card cards)
{
    if (strcmp(cards.faces,"Spades") == 0)
    return 4;
    if (strcmp(cards.faces,"Hearts") == 0)
    return 3;
    if (strcmp(cards.faces,"Diamonds") == 0)
    return 2;
    if (strcmp(cards.faces,"Clubs") == 0)
    return 1;
}

/*****************************************************************************
Function Name: lineSeparator()
Purpose: Creates a row of - symbols used for line separation.
Function in parameters: void
Function out parameter: void
Version: 1
Author: Byron Jones
*****************************************************************************/
void lineSeparator(void)
{
    int i;
    for (i = 0; i < 70; i++) {
        printf("-");
    }
    printf("\n");
}

/*****************************************************************************
Function Name: clearBuffer(void)
Purpose: Clear the input buffer before or after accepting input from the user.
Function in parameters: void
Function out parameter: void
Version: 2
Author: Byron Jones
*****************************************************************************/
void clearBuffer(void)
{
    while (getchar() != '\n');
}
