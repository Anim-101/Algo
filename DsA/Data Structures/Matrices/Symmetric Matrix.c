#include<stdio.h>

int symmetricMatrix(int size, int array[size][size])
{
    int flag = 0;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(array[i][j] != array[j][i])
            {
                flag = 1;

                break;
            }
        }
    }

    return flag;
}

int main()
{
    int array[5][5] = {{2, 2, 2, 2, 2}, {2, 3, 3, 3, 3}, {2, 3, 4, 4, 4}, {2, 3, 4, 5, 5}, {2, 3, 4, 5, 6}};

    int check = symmetricMatrix(5, array);

    if(check == 0)
    {
        printf("\nGiven Array is Symmetric Matrix\n");
    }
    else
    {
        printf("\nGiven Array is not Symmetric Matrix\n");
    }

    return 0;
}
