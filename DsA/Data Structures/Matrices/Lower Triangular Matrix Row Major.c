#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *array;
    int length;
};

void Set(struct Array *array, int i, int j, int element)
{
    if(i >= j)
    {
        array->array[((i * (i - 1)) / 2) + (j - 1)] = element;
    }
}

int Get(struct Array array, int i, int j)
{
    if(i >= j)
    {
        return array.array[((i * (i - 1)) / 2) + (j - 1)];
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
            if(i >= j)
            {
                printf("%d ", array.array[((i * (i - 1)) / 2) + (j - 1)]);
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

    printf("\nEnter Dimension of Lower Triangular Array: ");

    scanf("%d", &array.length);

    array.array = (int *) malloc(((array.length + (array.length + 1)) / 2) * sizeof(int));

    int element;

    printf("\nEnter Elements:\n");

    for(int i = 1; i <= array.length; i++)
    {
        for(int j = 1; j <= array.length; j++)
        {
            scanf("%d", &element);

            if(i >= j)
            {
                Set(&array, i, j, element);
            }
        }
    }

    printf("\nGet Array[1, 1] Element: %d\n\n", Get(array, 1, 1));

    Display(array);

    return 0;
}
