#include<stdio.h>

struct Array
{
    int array[10];
    int size;
    int length
};

void Display(struct Array array)
{
    printf("\nDisplaying Array Elements: ");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

int Delete(struct Array *array, int index)
{
    int x = 0;

    if(index > 0 && index < array->length)
    {
        x = array->array[index];

        for(int i = index; i < array->length - 1; i++)
        {
            array->array[i] = array->array[i + 1];
        }

        array->length--;

        return x;
    }

    return 0;
}

int main()
{
    struct Array array = {{2, 3, 4, 5, 6, 7}, 10, 6};

    printf("\nBefore Deletion\n");

    Display(array);

    printf("\nDeleted Value from Array: %d\n", Delete(&array, 3));

    printf("\nAfter Deletion\n");

    Display(array);

    return 0;
}
