#include<stdio.h>
#include<stdlib.h>

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

void Insert(struct Array *array, int value)
{
    int i = array->length - 1;

    while(array->array[i] > value)
    {
        array->array[i + 1] = array->array[i];

        i--;
    }

    array->array[i + 1] = value;

    array->length++;
}

int isSorted(struct Array array)
{
    for(int i = 0; i < array.length - 1; i++)
    {
        if(array.array[i] > array.array[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

void Swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;

    *y = temp;
}

void positiveNegative(struct Array *array)
{
    int i = 0;

    int j = array->length - 1;

    while(i < j)
    {
        while(array->array[i] < 0)
        {
            i++;
        }

        while(array->array[j] >= 0)
        {
            j--;
        }

        if(i < j)
        {
            Swap(&array->array[i], &array->array[j]);
        }
    }
}

int main()
{
    struct Array array = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    Display(array);

    int value = 26;

    printf("\nInserting Value %d in List\n", value);

    Insert(&array, value);

    Display(array);

    if(isSorted(array) == 0)
    {
        printf("\nGiven List is not Sorted\n");
    }
    else
    {
        printf("\nGiven List is Sorted\n");
    }

    struct Array positiveNegativeArray = {{-2, 3, -9, 16, -18, 21, -28, 32, -35}, 10, 9};

    printf("\nNew Array, Positive and Negative Swapping\n");

    Display(positiveNegativeArray);

    positiveNegative(&positiveNegativeArray);

    Display(positiveNegativeArray);

    return 0;
}
