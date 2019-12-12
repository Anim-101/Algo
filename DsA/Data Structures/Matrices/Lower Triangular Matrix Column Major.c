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
        array->array[(array->length * (j - 1)) + (((j - 1) * (j - 2)) / 2) + (i - j)] = element;
    }
}

int Get(struct Array array, int i, int j)
{
    if(i >= j)
    {
        return array.array[(array.length * (j - 1)) + (((j - 1) * (j - 2)) / 2) + (i - j)];
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
                printf("%d ", array.array[(array.length * (j - 1)) + (((j - 1) * (j - 2)) / 2) + (i - j)]);
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

    printf("\nEnter Dimension of Lower Triangular Array: ");

    scanf("%d", &array.length);

    printf("\n\nEnter all Elements for Lower Triangular Array\n");

    array.array = (int *) malloc((((array.length * (array.length + 1)) / 2)) * sizeof(int));

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

    printf("\n\n");

    printf("\nGet Array[3, 3] Element: %d\n\n", Get(array, 3, 3));

    Display(array);

    return 0;
}
