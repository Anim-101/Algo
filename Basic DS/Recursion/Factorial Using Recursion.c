#include <stdio.h>

int funcRecursion(int number)
{
    if (number == 0)
    {
        return 1;
    }
    else
    {
        return funcRecursion(number - 1) * number;
    }
}

int main()
{
    int number = 6;

    printf("Factorial of %d Using Recursion: %d\n", number, funcRecursion(number));

    return 0;
}
