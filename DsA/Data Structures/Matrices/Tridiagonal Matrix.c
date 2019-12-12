#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *array;
    int length;
};

void Set(struct Array *array, int i, int j, int element)
{
    if(i - j == 0)
    {
        array->array[array->length - 1 + i - 1] = element;
    }
    else if(i - j == 1)
    {
        array->array[i - 1] = element;
    }
    else if(i - j == -1)
    {
        array->array[(2 * array->length) - 1 + i - 1] = element;
    }
}

int Get(struct Array array, int i, int j)
{
    if(i - j == 0)
    {
        return array.array[array.length - 1 + i - 1];
    }
    else if(i - j == 1)
    {
        return array.array[i - 1];
    }
    else if(i - j == -1)
    {
        return array.array[(2 * array.length) - 1 + i - 1];
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
            if(i - j == 0)
            {
                printf("%d ", array.array[array.length - 1 + i + 1]);
            }
            else if(i - j == 1)
            {
                printf("%d ", array.array[i - 1]);
            }
            else if(i - j == -1)
            {
                printf("%d ", array.array[(2 * array.length) - 1 + i - 1]);
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

    printf("\nEnter Dimension of Tridiagonal Array: ");

    scanf("%d", &array.length);

    array.array = (int *) malloc((3 * (array.length - 2)) * sizeof(int));

    int element;

    printf("\nEnter Elements\n");

    for(int i = 1; i <= array.length; i++)
    {
        for(int j = 1; j <= array.length; j++)
        {
            scanf("%d", &element);

            if(((i - j) == 0) || ((i - j) == 1) || ((i - j) == -1))
            {
                Set(&array, i, j, element);
            }
        }
    }

    printf("\nGet Array[2, 2] Element: %d\n\n", Get(array, 2, 2));

    Display(array);

    return 0;
}
