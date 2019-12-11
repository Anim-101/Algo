#include<stdio.h>

struct Array
{
    int array[21];
    int size;
    int length;
};

void Display(struct Array array)
{
    printf("\nElements in Given Array List: ");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

void findingDuplicateUnSortedHash(struct Array array)
{
    struct Array hashArray;

    int max = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(max < array.array[i])
        {
            max = array.array[i];
        }
    }

    hashArray.size = max + 1;

    hashArray.length = max + 1;

    for(int i = 0; i <= hashArray.length; i++)
    {
        hashArray.array[i] = 0;
    }

    for(int i = 0; i < array.length; i++)
    {
        hashArray.array[array.array[i]]++;
    }

    for(int i = 0; i <= hashArray.length; i++)
    {
        if(hashArray.array[i] > 1)
        {
            printf("\n%d has Appeared %d Times in Given Array List\n", i, hashArray.array[i]);
        }
    }
}

int main()
{
    struct Array array = {{8, 3, 6, 4, 6, 5, 6, 8, 2, 7}, 10, 10};

    Display(array);

    findingDuplicateUnSortedHash(array);

    return 0;
}
