#include<stdio.h>

struct Array
{
    int array[10];
    int size;
    int length;
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

int linearSearch(struct Array *array, int key)
{
    for(int i = 0; i < array->length; i++)
    {
        if(key == array->array[i])
        {
            return i;
        }
    }

    return -1;
}

void Swap(int *x, int *y)
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
            Swap(&array->array[i], &array->array[i - 1]);

            return i;
        }
    }

    return -1;
}

int linearSearchMoveToFront(struct Array *array, int key)
{
    for(int i = 0; i < array->length; i++)
    {
        if(key == array->array[i])
        {
            Swap(&array->array[i], &array->array[0]);

            return i;
        }
    }

    return -1;
}

int main()
{
    struct Array arrayNormal = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};

    printf("\nNormal -> Array Element\n");

    Display(arrayNormal);

    int position = linearSearch(&arrayNormal, 10);

    if(position == -1)
    {
        printf("\nThrough Normal Linear Search, Key was not Found from Given Array List\n");
    }
    else
    {
        printf("\nThrough Normal Linear Search, Key was Found at %d Place from Given Array List\n", position);
    }

    struct Array arrayTranspose = {{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 10, 10};

    printf("\nTranspose -> Array Element\n");

    Display(arrayTranspose);

    position = linearSearchTransposition(&arrayTranspose, 5);

    if(position == -1)
    {
        printf("\nThrough Transposition Linear Search, Key was not Found from Given Array List\n");
    }
    else
    {
        printf("\nThrough Transposition Linear Search, Key was Found at %d Place from Given Array List\n", position);

        printf("\nAfter Transposition, Array Elements\n");

        Display(arrayTranspose);
    }

    struct Array arrayMove = {{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 10, 10};

    printf("\nMove to Front -> Array Elements\n");

    Display(arrayMove);

    position = linearSearchMoveToFront(&arrayMove, 15);

    if(position == -1)
    {
        printf("\nThrough Move to Front Linear Search, Key was not Found from Given Array List\n");
    }
    else
    {
        printf("\nThrough Move to Front Linear Search, Key was Found at %d Place from Given Array List\n", position);

        printf("\nAfter Move to Front, Array Elements\n");

        Display(arrayMove);
    }

    return 0;
}
