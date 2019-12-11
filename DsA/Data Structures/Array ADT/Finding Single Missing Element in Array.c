#include<stdio.h>

struct Array
{
    int array[11];
    int size;
    int length;
};

void Display(struct Array array)
{
    printf("\nElements are in Given List: ");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

int naturalNumberMissingElement(struct Array array)
{
    int sumElements = 0, sumEquation = 0;

    for(int i = 0; i < array.length; i++)
    {
        sumElements += array.array[i];
    }

    sumEquation = (array.array[array.length - 1] * (array.array[array.length - 1] + 1)) / 2;

    int naturalMissingNumber = sumEquation - sumElements;

    return naturalMissingNumber;
}

int numberMissingElement(struct Array array)
{
    int difference = array.array[0] - 0;

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] - i != difference)
        {
            return i + difference;
        }
    }

    return -1;
}

int main()
{
    struct Array arrayNatural = {{1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12}, 11, 11};

    printf("\nStarting from 1 to Onward, Naturals Numbers\n");

    Display(arrayNatural);

    int element = naturalNumberMissingElement(arrayNatural);

    printf("\nFor Natural Numbers of List, Missing Element is: %d\n", element);

    struct Array arrayNumber = {{6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17}, 11, 11};

    printf("\nStarting from any Number to Onward, Numbers\n");

    Display(arrayNumber);

    element = numberMissingElement(arrayNumber);

    if(element == -1)
    {
        printf("\nNo Missing Element in List\n");
    }
    else
    {
        printf("\nFor Numbers of List, Missing Element is: %d\n", element);
    }

    return 0;
}
