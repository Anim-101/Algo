#include<stdio.h>
#include<stdlib.h>

struct ArrayOne
{
    int *array;
    int size;
    int length;
};

struct ArrayTwo
{
    int array[10];
    int size;
    int length;
};

void DisplayArrayOne(struct ArrayOne array)
{
    printf("\nElements are:\n\n");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

void DisplayArrayTwo(struct ArrayTwo array)
{
    printf("\nElements are:\n\n");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

int main()
{
    struct ArrayOne arrayOne;

    printf("\nEnter Size of an Array(Pointer Array): ");

    scanf("%d", &arrayOne.size);

    arrayOne.array = (int *) malloc(arrayOne.size * sizeof(int));

    arrayOne.length = 0;

    int num;

    printf("\n\nEnter Number of Number in Array(Pointer Array): ");

    scanf("%d", &num);

    printf("\nEnter %d Numbers(Pointer Array):\n\n", num);

    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arrayOne.array[i]);
    }

    arrayOne.length = num;

    printf("\nDisplaying for Pointer Array:\n");

    DisplayArrayOne(arrayOne);

    struct ArrayTwo arrayTwo = {{2, 3, 4, 5, 8}, 10, 5};

    printf("\nDisplaying for Static Array:\n");

    DisplayArrayTwo(arrayTwo);

    return 0;
}
