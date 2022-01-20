#include <stdio.h>

int main()
{
    int num;
    int tempNum;
    int numCounter = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    tempNum = num;

    /* loops until tempNum is 0, axing the last digit and incrementing numCounter by 1 each iteration */
    while (tempNum != 0)
    {
        tempNum /= 10;
        numCounter++;
    }

    printf("Number of digits in %d is %d\n", num, numCounter);

    return 0;
}