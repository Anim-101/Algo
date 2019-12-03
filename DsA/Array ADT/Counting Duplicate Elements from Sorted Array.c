#include<stdio.h>

struct Array
{
    int array[10];
    int size;
    int length;
};

void Display(struct Array array)
{
    printf("\nElements are in List: ");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

void countingDuplicateElements(struct Array array)
{
    int j = 0;

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] == array.array[i + 1])
        {
            j = i + 1;

            while(array.array[j] == array.array[i])
            {
                j++;
            }

            printf("\n%d is Appearing %d Times in List\n", array.array[i], j - i);

            i = j - 1;
        }
    }
}

int main()
{
    struct Array array = {{3, 6, 8, 9, 10, 12, 15, 15, 15, 20}, 10, 10};

    Display(array);

    countingDuplicateElements(array);

    return 0;
}
