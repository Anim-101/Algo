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

struct Array *Merge(struct Array *arrayOne, struct Array *arrayTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arrayOne->length && j < arrayTwo->array[j])
    {
        if(arrayOne->array[i] < arrayTwo->array[j])
        {
            array->array[k++] = arrayOne->array[i++];
        }
        else
        {
            array->array[k++] = arrayTwo->array[j++];
        }
    }

    for(i; i < arrayOne->length; i++)
    {
        array->array[k++] = arrayOne->array[i];
    }

    for(; j < arrayTwo->length; j++)
    {
        array->array[k++] = arrayTwo->array[j];
    }

    array->length = arrayOne->length + arrayTwo->length;

    array->size = 10;

    return array;
}

int main()
{
    struct Array arrayOne = {{2, 9, 21, 28, 35}, 10, 5};

    printf("\nFor First Array\n");

    Display(arrayOne);

    struct Array arrayTwo = {{2, 3, 16, 18, 28}, 10, 5};

    printf("\nFor Second Array\n");

    Display(arrayTwo);

    struct Array *array;

    array = Merge(&arrayOne, &arrayTwo);

    printf("\nAfter Merging, New Array\n");

    Display(*array);

    return 0;
}
