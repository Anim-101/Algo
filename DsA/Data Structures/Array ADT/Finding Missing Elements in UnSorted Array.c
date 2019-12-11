#include<stdio.h>

struct Array
{
    int array[20];
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

void missingElements(struct Array array)
{
    struct Array frequencyArray;

    int max = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(max < array.array[i])
        {
            max = array.array[i];
        }
    }

    for(int i = 0; i <= max; i++)
    {
        frequencyArray.array[i] = 0;
    }

    frequencyArray.size = max;

    frequencyArray.length = max;

    for(int i = 0; i < array.length; i++)
    {
        frequencyArray.array[array.array[i]]++;
    }

    printf("\nMissing Elements from UnSorted Array: ");

    for(int i = 0; i < frequencyArray.length; i++)
    {
        if(frequencyArray.array[i] == 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main()
{
    struct Array array = {{2, 5, 4, 1, 7, 11, 9, 17, 13, 10}, 10, 10};

    Display(array);

    missingElements(array);

    return 0;
}
