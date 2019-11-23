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

int linearSearchMoveToFront(struct Array *array, int key)
{
    for(int i = 0; i < array->length; i++)
    {
        if(key == array->array[i])
        {
            swap(&array->array[i], &array->array[0]);

            return i;
        }
    }

    return -1;
}

int main()
{
    struct Array array = {{1, 3, 5, 7, 9, 11, 13}, 10, 7};

    printf("\nBefore Traversing or Searching List using Move To Front Method\n");

    Display(array);

    int position = linearSearchMoveToFront(&array, 11);

    if(position == -1)
    {
        printf("\nValue doesn't Exist in this List\n");
    }
    else
    {
        printf("\nValue was Found at %d Position\n", position);
    }

    printf("\nAfter Traversing or Searching List using Move To Front Method\n");

    Display(array);

    return 0;
}
