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
    printf("\nElements are:\n\n");

    for(int i = 0; i < array.length; i++)
    {
        printf("%d ", array.array[i]);
    }

    printf("\n");
}


struct Array * unSortedUnion(struct Array *arrayUnSortedOne, struct Array *arrayUnSortedTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array * array = (struct Arra *) malloc(sizeof(struct Array));

    for(i = 0; i < arrayUnSortedOne->length; i++)
    {
        array->array[i] = arrayUnSortedOne->array[i];
    }

    int l = i;

    while(j < arrayUnSortedTwo->length)
    {
        k = 0;

        while(k < i)
        {
            if(array->array[k] == arrayUnSortedTwo->array[j])
            {
                break;
            }

            k++;
        }

        if(k == i)
        {
            array->array[l++] = arrayUnSortedTwo->array[j];
        }

        j++;
    }

    array->length = l;

    array->size = 10;

    return array;
}

struct Array *sortedUnion(struct Array *arraySortedOne, struct Array *arraySortedTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arraySortedOne->length && j < arraySortedTwo->length)
    {
        if(arraySortedOne->array[i] < arraySortedTwo->array[j])
        {
            array->array[k++] = arraySortedOne->array[i++];
        }
        else if(arraySortedTwo->array[j] < arraySortedOne->array[i])
        {
            array->array[k++] = arraySortedTwo->array[j++];
        }
        else
        {
            array->array[k++] = arraySortedOne->array[i++];

            j++;
        }
    }

    for(; i < arraySortedOne->length; i++)
    {
        array->array[k++] = arraySortedOne->array[i];
    }

    for(; j < arraySortedTwo->length; j++)
    {
        array->array[k++] = arraySortedTwo->array[j];
    }

    array->length = k;

    array->size = 10;

    return array;
}

struct Array *unSortedIntersection(struct Array *arrayUnSortedOne, struct Array *arrayUnSortedTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arrayUnSortedOne->length)
    {
        j = 0;

        while(j < arrayUnSortedTwo->length)
        {
            if(arrayUnSortedOne->array[i] == arrayUnSortedTwo->array[j])
            {
                array->array[k++] = arrayUnSortedTwo->array[j];
            }

            j++;
        }

        i++;
    }

    array->length = k;

    array->size = 10;

    return array;
}

struct Array *sortedIntersection(struct Array *arraySortedOne, struct Array *arraySortedTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arraySortedOne->length && j < arraySortedTwo->length)
    {
        if(arraySortedOne->array[i] < arraySortedTwo->array[j])
        {
            i++;
        }
        else if(arraySortedTwo->array[j] < arraySortedOne->array[i])
        {
            j++;
        }
        else if(arraySortedOne->array[i] == arraySortedTwo->array[j])
        {
            array->array[k++] = arraySortedOne->array[i++];

            j++;
        }
    }

    array->length = k;

    array->size = 10;

    return array;
}

struct Array *unSortedDifference(struct Array *arrayUnSortedOne, struct Array *arrayUnSortedTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arrayUnSortedOne->length)
    {
        j = 0;

        while(j < arrayUnSortedTwo->length)
        {
            if(arrayUnSortedOne->array[i] == arrayUnSortedTwo->array[j])
            {
                break;
            }

            j++;
        }

        if(j == arrayUnSortedTwo->length)
        {
            array->array[k++] = arrayUnSortedOne->array[i];
        }

        i++;
    }

    array->length = k;

    array->size = 10;

    return array;
}

struct Array *sortedDifference(struct Array *arraySortedOne, struct Array *arraySortedTwo)
{
    int i = 0, j = 0, k = 0;

    struct Array *array = (struct Array *) malloc(sizeof(struct Array));

    while(i < arraySortedOne->length && j < arraySortedTwo->length)
    {
        if(arraySortedOne->array[i] < arraySortedTwo->array[j])
        {
            array->array[k++] = arraySortedOne->array[i++];
        }
        else if(arraySortedTwo->array[j] < arraySortedOne->array[i])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    for(; i < arraySortedOne->length; i++)
    {
        array->array[k++] = arraySortedOne->array[i];
    }

    array->length = k;

    array->size = 10;

    return array;
}

int main()
{
    struct Array arrayUnSortedOne = {{2, 1, 9, 28, 5}, 10, 5};

    printf("\nUnSorted Array One:\n");

    Display(arrayUnSortedOne);

    struct Array arrayUnSortedTwo = {{2, 32, 9, 18, 8}, 10, 5};

    printf("\nUnSorted Array Two:\n");

    Display(arrayUnSortedTwo);

    struct Array arraySortedOne = {{2, 9, 21, 28, 35}, 10, 5};

    printf("\nSorted Array One:\n");

    Display(arraySortedOne);

    struct Array arraySortedTwo = {{2, 3, 9, 18, 28}, 10, 5};

    printf("\nSorted Array Two:\n");

    Display(arraySortedTwo);

    struct Array *array;

    array = unSortedUnion(&arrayUnSortedOne, &arrayUnSortedTwo);

    printf("\nNew Array after Union based on UnSorted Lists:\n");

    Display(*array);

    array = sortedUnion(&arraySortedOne, &arraySortedTwo);

    printf("\nNew Array after Union based on Sorted Lists:\n");

    Display(*array);

    array = unSortedIntersection(&arrayUnSortedOne, &arrayUnSortedTwo);

    printf("\nNew Array after Intersection based on UnSorted Lists:\n");

    Display(*array);

    array = sortedIntersection(&arraySortedOne, &arraySortedTwo);

    printf("\nNew Array after Intersection based on Sorted Lists:\n");

    Display(*array);

    printf("\nNew Array after Difference based on UnSorted Lists:\n");

    array = unSortedDifference(&arrayUnSortedOne, &arrayUnSortedTwo);

    Display(*array);

    printf("\nNew Array after Difference based on Sorted Lists:\n");

    array = sortedDifference(&arraySortedOne, &arraySortedTwo);

    Display(*array);

    printf("\nSet Membership is nothing but Linear Search for Unsorted List and Binary Search for Sorted Lists\n");

    return 0;
}
