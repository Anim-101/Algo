#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *array;
    int length;
};

void Set(struct Array *array, int i, int j, int element)
{
    if(i <= j)
    {
        array->array[j - i] = element;
    }
    else if(i > j)
    {
        array->array[array->length + i - j - 1] = element;
    }
}

int Get(struct Array array, int i, int j)
{
    if(i <= j)
    {
        return array.array[j - i];
    }
    else if(i > j)
    {
        return array.array[array.length + i - j - 1];
    }
}

void Display(struct Array array)
{
    for(int i = 1; i <= array.length; i++)
    {
        for(int j = 1; j <= array.length; j++)
        {
            if(i <= j)
            {
                printf("%d ", array.array[j - i]);
            }
            else if(i > j)
            {
                printf("%d ", array.array[array.length + i - j - 1]);
            }
        }

        printf("\n");
    }
}

int main()
{
    struct Array array;

    printf("\nEnter Dimension of Toplitz Matrix: ");

    scanf("%d", &array.length);

    printf("\nEnter Elements:\n");

    array.array = (int *) malloc(((array.length * 2) - 1) * sizeof(int));

    int element;

    for(int i = 1; i <= array.length; i++)
    {
        for(int j = 1; j <= array.length; j++)
        {
            scanf("%d", &element);

            if(i == 1)
            {
                Set(&array, i, j, element);
            }
            else if((j == 1) && (i != 1))
            {
                Set(&array, i, j, element);
            }
        }
    }

    printf("\nGet Array[2, 2] Element: %d\n\n", Get(array, 2, 2));

    Display(array);

    return 0;
}
