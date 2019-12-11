#include<stdio.h>

struct Array
{
    int array[10];
    int size;
    int length;
};

void Display(struct Array array)
{
    printf("\nElements are in Given Array List: ");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

void duplicateElements(struct Array array)
{
    int lastDuplicate = 0;

    printf("\nDuplicate Elements in Lists are: ");

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] == array.array[i + 1] && array.array[i] != lastDuplicate)
        {
            printf("%d ", array.array[i]);

            lastDuplicate = array.array[i];
        }
    }

    printf("\n");
}

int main()
{
    struct Array array = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 10, 10};

    Display(array);

    duplicateElements(array);

    return 0;
}
