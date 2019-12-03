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

int Get(struct Array array, int index)
{
    if(index >= 0 && index <= array.length)
    {
        return array.array[index];
    }

    return -1;
}

int Set(struct Array *array, int index, int setNumber)
{
    if(index >= 0 && index < array->length)
    {
        array->array[index] = setNumber;
    }
}

int Min(struct Array array)
{
    int min = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] < min)
        {
            min = array.array[i];
        }
    }

    return min;
}

int Max(struct Array array)
{
    int max = array.array[0];

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] > max)
        {
            max = array.array[i];
        }
    }

    return max;
}

int Sum(struct Array array)
{
    int sum = 0;

    for(int i = 0; i < array.length; i++)
    {
        sum = sum + array.array[i];
    }

    return sum;
}

float Avg(struct Array array)
{
    return (float) (Sum(array) / array.length);
}

int main()
{
    struct Array array = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    Display(array);

    int index = 4;

    printf("\nGet %d Position Element from List: %d\n", index, Get(array, index));

    index = 6;

    int setNumber = 20;

    printf("\nSet %d Position Element from %d to %d in List\n", index, Get(array, index), setNumber);

    Set(&array, index, setNumber);

    printf("\nAfter Set\n");

    Display(array);

    printf("\nMin Element from Given List: %d\n", Min(array));

    printf("\nMax Element from Given List: %d\n", Max(array));

    printf("\nSum of Elements from Given List: %d\n", Sum(array));

    printf("\nAverage of Elements from Given List: %.2f\n", Avg(array));

    return 0;
}
