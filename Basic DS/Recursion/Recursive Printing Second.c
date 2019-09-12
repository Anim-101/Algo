#include<stdio.h>

void funcSecond(int number)
{
    if(number > 0)
    {
        funcSecond(number - 1);

        printf("%d\n", number);
    }
}

int main ()
{
    int number;

    printf("Enter Number: ");

    scanf("%d", &number);

    funcSecond(number);

    return 0;
}