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

void minMaxArraySingleScan(struct Array array)
{
    int min = array.array[0], max = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(min > array.array[i])
        {
            min = array.array[i];
        }
        else if(max < array.array[i])
        {
            max = array.array[i];
        }
    }

    printf("\nMin from Array: %d\n", min);

    printf("\nMax from Array: %d\n", max);
}

int main()
{
    struct Array array = {{5, 8, 3, 9, 6, 2, 10, 7, -1, 4}, 10, 10};

    Display(array);

    minMaxArraySingleScan(array);

    return 0;
}
