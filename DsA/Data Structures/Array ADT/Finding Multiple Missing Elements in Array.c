#include<stdio.h>

struct Array
{
    int array[11];
    int size;
    int length;
};

void Display(struct Array array)
{
    printf("\nElements are in Given List: ");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

void multipleMissingElements(struct Array array)
{
    int difference = array.array[0] - 0;

    printf("\nMissing Elements are: ");

    for(int i = 0; i < array.length; i++)
    {
        if(array.array[i] != difference)
        {
            while(difference < array.array[i] - i)
            {
                printf("%d ", i + difference);

                difference++;
            }
        }
    }

    printf("\n");
}

int main()
{
    struct Array array = {{6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19}, 11, 11};

    Display(array);

    multipleMissingElements(array);

    return 0;
}
