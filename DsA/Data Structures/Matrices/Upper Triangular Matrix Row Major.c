#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *array;
    int length;
};

void Set(struct Array *array, int i, int j, int element)
{
    if(j >= 1)
    {
        array->array[(array->length * (i - 1)) + (((i - 2) + (i - 1)) / 2) + (j - i)] = element;
    }
}

int Get(struct Array array, int i, int j)
{
    if(j >= i)
    {
        return array.array[(array.length * (i - 1)) + (((i - 2) + (i - 1)) / 2) + (j - i)];
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
                printf("%d ", array.array[(array.length * (i - 1)) + (((i - 2) + (i - 1)) / 2) + (j - i)]);
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

    int i, j, element;

    printf("\nAfter Dimension of Upper Triangular Array: ");

    scanf("%d", &array.length);

    printf("\nEnter all Elements for Upper Triangular Array:\n");

    array.array = (int *) malloc(((array.length * (array.length + 1)) / 2) * sizeof(int));

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

    printf("\nGet Array[3, 3] Element: %d\n", Get(array, 3, 3));

    Display(array);

    return 0;
}
