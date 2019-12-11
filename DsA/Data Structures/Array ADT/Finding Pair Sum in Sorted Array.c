#include<stdio.h>

struct Array
{
    int array[10];
    int length;
    int size;
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

void pairSumSortedArray(struct Array array, int sum)
{
    int i = 0, j = array.length - 1;

    printf("\nSum Pair Found from Given Array List:\n");

    while(i < j)
    {
        if(array.array[i] + array.array[j] == sum)
        {
            printf("\n%d + %d = %d\n", array.array[i], array.array[j], sum);

            i++;

            j--;
        }
        else if(array.array[i] + array.array[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    struct Array array = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};

    Display(array);

    pairSumSortedArray(array, 10);

    return 0;
}
