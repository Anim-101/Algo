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

void Append(struct Array *array, int number)
{
    if(array->length < array->size)
    {
        array->array[array->length++] = number;
    }
}

void Insert(struct Array *array, int index, int number)
{
    for(int i = array->length; i > index; i--)
    {
        array->array[i] = array->array[i - 1];
    }

    array->array[index] = number;

    array->length++;
}

int main()
{
    struct Array array = {{2, 4, 3, 7, 8, 2}, 10, 5};

    Display(array);

    Append(&array, 10);

    printf("\nAfter Appending\n");

    Display(array);

    Insert(&array, 0, 12);

    printf("\nAfter Inserting\n");

    Display(array);

    return 0;
}
