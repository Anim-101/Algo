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

void findingPairSumUnSortedUniqueHash(struct Array array, int sum)
{
    int max = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(max < array.array[i])
        {
            max = array.array[i];
        }
    }

    struct Array arrayHash;

    arrayHash.size = max + 1;

    arrayHash.length = max + 1;

    for(int i = 0; i < arrayHash.length; i++)
    {
        arrayHash.array[i] = 0;
    }

    printf("\nSum Pair in Given List:\n");

    for(int i = 0; i < array.length; i++)
    {
        if((arrayHash.array[sum - array.array[i]] != 0) && (array.array[i] <= sum))
        {
            printf("\n%d + %d = %d\n", array.array[i], sum - array.array[i], sum);
        }

        arrayHash.array[array.array[i]]++;
    }
}

int main()
{
    struct Array array = {{6, 3, 8, 10, 16, 7, 5, 2, 9, 14, 11, 4}, 12, 12};

    Display(array);

    findingPairSumUnSortedUniqueHash(array, 10);

    return 0;
}
