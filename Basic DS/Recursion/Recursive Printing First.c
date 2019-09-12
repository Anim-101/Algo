#include<stdio.h>

void funcOne (int number)
{
    if(number > 0)
    {
        printf("%d\n", number);
		
		funcOne(number - 1);
    }
}

int main()
{
    int number;

    printf("Enter Number: ");

    scanf("%d", &number);

    funcOne(number);

    return 0;
}