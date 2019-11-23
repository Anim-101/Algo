#include<stdio.h>

struct Array
{
    int array[10];
    int size;
    int length;
};

void Display(struct Array array)
{
    printf("In List: ");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;

    *y = temp;
}

int linearSearchTransposition(struct Array *array, int key)
{
    for(int i = 0; i < array->length; i++)
    {
        if(key == array->array[i])
        {
            swap(&array->array[i], &array->array[i - 1]);

            return i;
        }
    }

    return -1;
}

int main()
{
    struct Array array = {{2, 3, 14, 5, 9, 12, 5, 7}, 10, 8};

    printf("\nBefore using Transposition Method in List\n");

    Display(array);

    int position = linearSearchTransposition(&array, 9);

    if(position == -1)
    {
        printf("\nKey was not Found from List\n");
    }
    else
    {
        printf("\nKey was Found at %d Position from List\n", position);
    }

    printf("\nAfter using Transposition Method in List\n");

    Display(array);

    return 1;
}
