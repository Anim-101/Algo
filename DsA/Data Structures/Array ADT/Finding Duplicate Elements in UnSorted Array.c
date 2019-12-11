#include<stdio.h>

struct Array
{
    int array[10];
    int size;
    int length;
};

void Display(struct Array array)
{
    printf("\nElements in Array List: ");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

void findingDuplicateUnSortedArray(struct Array array)
{
    int count = 0;

    for(int i = 0; i < array.length; i++)
    {
        count = 1;

        if(array.array[i] != -1)
        {
            for(int j = i + 1; j < array.length; j++)
            {
                if(array.array[i] == array.array[j])
                {
                    count++;

                    array.array[j] = -1;
                }
            }

            if(count > 1)
            {
                printf("\n%d has Appeared %d Times in Given Array List\n", array.array[i], count);
            }
        }
    }
}

int main()
{
    struct Array array = {{8, 3, 6, 4, 6, 5, 6, 8, 2, 7}, 10, 10};

    Display(array);

    findingDuplicateUnSortedArray(array);

    return 0;
}
