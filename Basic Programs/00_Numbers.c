#include <stdio.h>

int main()
{
    /*prints numbers 1-100 and check if it is a multiple of 3 or 5 or both and displaying a message if so */
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            printf("%i I'm a multiple of 3 && 5!!!\n", i);
        else if (i % 5 == 0)
            printf("%i I'm a multiple of 5!!!\n", i);
        else if (i % 3 == 0)
            printf("%i I'm a multiple of 3!!!\n", i);
        else
        printf("%i \n", i);
    }
    return 0;
}