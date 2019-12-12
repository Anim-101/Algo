#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *array;
    int length;
};

void Set(struct Array *array, int i, int j, int element)
{
    if(j >= i)
    {
        array->array[((j * (j - 1)) / 2) + (i - 1)] = element;
    }
}

int Get(struct Array array, int i, int j)
{
    if(j >= i)
    {
        return array.array[((j * (j - 1)) / 2) + (i - 1)];
    }
    else
    {
        return 0;
    }
}

void Display(struct Array array)
{
    for(int i = 1; i <= array.length; i++)
    {
        for(int j = 1; j <= array.length; j++)
        {
            if(j >= i)
            {
                printf("%d ", array.array[((j * (j - 1)) / 2) + (i - 1)]);
            }
            else
            {
                printf("0 ");
            }
        }

        printf("\n");
    }
}

int main()
{
    struct Array array;

    printf("\nEnter Dimension of Upper Triangular Array: ");

    scanf("%d", &array.length);

    printf("\nEnter All Elements: \n");

    array.array = (int *) malloc(((array.length + (array.length + 1)) / 2) * sizeof(int));

    int element;

    for(int i = 1; i <= array.length; i++)
    {
        for(int j = 1; j <= array.length; j++)
        {
            scanf("%d", &element);

            if(j >= i)
            {
                Set(&array, i, j, element);
            }
        }
    }

    printf("\nGet Array[3, 3] Element: %d\n\n", Get(array, 3, 3));

    Display(array);

    return 0;
}
