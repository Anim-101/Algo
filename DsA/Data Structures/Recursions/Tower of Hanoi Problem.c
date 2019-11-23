#include<stdio.h>

void towerOfHanoi(int n, int A, int B, int C)
{
    if(n > 0)
    {
        towerOfHanoi(n - 1, A, C, B);

        printf("(%d, %d)\n", A, C);

        towerOfHanoi(n - 1, B, A, C);
    }
}

int main()
{
    towerOfHanoi(5, 1, 2 , 3);

    return 0;
}
