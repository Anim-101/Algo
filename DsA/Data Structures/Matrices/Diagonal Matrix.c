#include<stdio.h>

struct Matrix
{
    int arrayMatrix[10];
    int length;
};

void Display(struct Matrix arrayMatrix)
{
    for(int i = 0; i < arrayMatrix.length; i++)
    {
        for(int j = 0; j < arrayMatrix.length; j++)
        {
            if(i == j)
            {
                printf("%d ", arrayMatrix.arrayMatrix[i]);
            }
            else
            {
                printf("0 ");
            }
        }

        printf("\n");
    }
}

void Set(struct Matrix *arrayMatrix, int i, int j, int x)
{
    if(i == j)
    {
        arrayMatrix->arrayMatrix[i - 1] = x;
    }
}

int Get(struct Matrix arrayMatrix, int i, int j)
{
    if(i == j)
    {
        return arrayMatrix.arrayMatrix[i - 1];
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Matrix arrayMatrix;

    Set(&arrayMatrix, 1, 1, 5);

    Set(&arrayMatrix, 2, 2, 8);

    Set(&arrayMatrix, 3, 3, 9);

    Set(&arrayMatrix, 4, 4, 12);

    arrayMatrix.length = 4;

    Display(arrayMatrix);

    printf("\nGetting Diagonal Matrix 2nd Row 2nd Column Element, Calling Get Function: %d\n", Get(arrayMatrix, 2, 2));

    return 0;
}
