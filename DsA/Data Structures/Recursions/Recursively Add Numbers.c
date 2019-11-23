#include<stdio.h>

int func(int number)
{
    if(number > 0)
    {
        return func(number - 1) + number;
    }

    return 0;
}

int main()
{

    int number = 5;

    printf("Number Adding Recursively 0 to %d: %d", number, func(number));

    return 0;

}
