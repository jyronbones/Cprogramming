#include <stdio.h>

int main()
{
    int binNum;
    int tempNum;
    int decNum = 0;
    int base = 1;

    printf("Enter a binary number: ");
    scanf("%d", &binNum);

    tempNum = binNum;
    /* loops until tempNum is 0, acessing the last digit and multiplying by 2^(number position)
    and adding it to decNum and axing the last digit each iteration
    */
    while (tempNum != 0)
    {
        int lastDigit = tempNum % 10;
        tempNum /= 10;
        decNum += lastDigit * base;
        base = base * 2;
    }

    printf("The decimal equivalent of %d is %d\n", binNum, decNum);

    return 0;
}