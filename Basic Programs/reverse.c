#include <stdio.h>

int main()
{
    int num;
    int reverse = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);


    /* loops until num is 0, getting the last digit and adding it to the end of reverse, axing the last digit each iteration */
    while (num != 0)
    {
        int lastDigit = num % 10;
        num /= 10;
        reverse = reverse * 10 + lastDigit;
    }

    printf("The reverse number is %d\n", reverse);

    return 0;
}