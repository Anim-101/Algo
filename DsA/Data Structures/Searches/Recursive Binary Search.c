#include<stdio.h>

struct Array
{
    int array[10];
    int size;
    int length;
};

void Display(struct Array array)
{
    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}

int recursiveBinarySearch(int array[], int low, int high, int key)
{
    int mid = 0;

    if(low <= high)
    {
        mid = (low + high) / 2;

        if(key == array[mid])
        {
            return mid;
        }
        else if(key <= array[mid])
        {
            return recursiveBinarySearch(array, low, mid - 1, key);
        }
        else
        {
            return recursiveBinarySearch(array, mid + 1, high, key);
        }
    }

    return 1;
}

int main()
{
    struct Array array = {{2, 4, 6, 8, 10, 12, 14, 16}, 10, 8};

    printf("\nAvailable Values in List: ");

    Display(array);

    int position = recursiveBinarySearch(array.array, 0, array.length, 12);

    if(position == -1)
    {
        printf("\nValue was not Found in List\n");
    }
    else
    {
        printf("\nValues was Found at %d Position in List\n", position);
    }

    return 0;
}
