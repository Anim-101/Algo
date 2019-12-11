#include<stdio.h>

struct Array
{
    int array[10];
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

void findingPairSumUnSortedUnique(struct Array array, int sum)
{
    printf("\nMatched Pair for Sum %d are:\n", sum);

    for(int i = 0; i < array.length - 1; i++)
    {
        for(int j = i + 1; j < array.length; j++)
        {
            if(array.array[i] + array.array[j] == sum)
            {
                printf("\n%d + %d = %d\n", array.array[i], array.array[j], sum);
            }
        }
    }
}

int main()
{
    struct Array array = {{6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, 10, 10};

    Display(array);

    findingPairSumUnSortedUnique(array, 10);

    return 0;
}
