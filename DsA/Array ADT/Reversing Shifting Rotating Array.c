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
    printf("\nElements in List: ");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

void Swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;

    *y = temp;
}

void reverseUsingArray(struct Array *array)
{
    int *brray;

    brray = (int *) malloc(array->length * sizeof(int));

    for(int i = array->length - 1, j = 0; i >= 0; i--, j++)
    {
        brray[j] = array->array[i];
    }

    for(int i = 0; i < array->length; i++)
    {
        array->array[i] = brray[i];
    }
}

void reverseUsingSwapPointer(struct Array *array)
{
    for(int i = 0, j = array->length - 1; i < j; i++, j--)
    {
        Swap(&array->array[i], &array->array[j]);
    }
}

void leftShiftArray(struct Array *array, int shift)
{
    while(shift != 0)
    {
        for(int i = 0; i < array->length - 1; i++)
        {
            array->array[i] = array->array[i + 1];
        }

        array->array[array->length - 1] = 0;

        shift--;
    }
}

void rightShiftArray(struct Array *array, int shift)
{
    while(shift != 0)
    {
        for(int i = array->length - 1; i >= 0; i--)
        {
            array->array[i] = array->array[i - 1];
        }

        array->array[0] = 0;

        shift--;
    }
}

void leftRotateArray(struct Array *array, int rotate)
{
    int value;

    while(rotate != 0)
    {
        value = array->array[0];

        for(int i = 0; i < array->length - 1; i++)
        {
            array->array[i] = array->array[i + 1];
        }

        array->array[array->length - 1] = value;

        rotate--;
    }
}


void rightRotateArray(struct Array *array, int rotate)
{
    int value;

    while(rotate != 0)
    {
        value = array->array[array->length - 1];

        for(int i = array->length - 1; i >= 0; i--)
        {
            array->array[i] = array->array[i - 1];
        }

        array->array[0] = value;

        rotate--;
    }
}

int main()
{
    struct Array array = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    Display(array);

    reverseUsingArray(&array);

    printf("\nAfter Reversing Using Another Array\n");

    Display(array);

    reverseUsingSwapPointer(&array);

    printf("\nAfter Reversing Using Swap Pointer Within Array\n");

    Display(array);

    leftShiftArray(&array, 5);

    printf("\nAfter Left Shifting Array\n");

    Display(array);

    struct Array brray = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    printf("\nRe Assign Values in Another Array\n");

    Display(brray);

    leftRotateArray(&brray, 6);

    printf("\nAfter Left Rotating Array\n");

    Display(brray);

    rightRotateArray(&brray, 6);

    printf("\nAfter Right Rotating Array\n");

    Display(brray);

    rightShiftArray(&brray, 3);

    printf("\nAfter Right Shifting Array\n");

    Display(brray);

    return 0;
}
