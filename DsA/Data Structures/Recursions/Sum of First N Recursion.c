#include<stdio.h>

int funcRecursion(int number)
{
    if(number == 0)
    {
        return 0;
    }
    else
    {
        return funcRecursion(number - 1) + number;
    }
}

int main()
{

    int number = 5;

    printf("For %d Sum is: %d Using Recursion\n", number, funcRecursion(number));

    return 0;
}
