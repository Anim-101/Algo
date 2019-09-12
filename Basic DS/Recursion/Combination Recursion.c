#include<stdio.h>

// Recursive Factorial Function for NCR Combination Finding Function
int factorial(int number)
{
    if(number == 0)
    {
        return 1;
    }
    else
    {
        return factorial(number - 1) * number;
    }
}

// NCR Combination Finding Function in Recursive Method
int nCr(int n, int r)
{
    int numerator, denominator;

    numerator = factorial(n);

    denominator = factorial(r) * factorial(n - r);

    return numerator / denominator;
}

// NCR Combination Finding Function Using Pascal's Triangle Based Recursive Method
int nCrPascalTriangle(int n, int r)
{
    if(n == r || r == 0)
    {
        return 1;
    }

    return nCrPascalTriangle(n - 1, r - 1) + nCrPascalTriangle(n - 1, r);
}


int main()
{
    int n = 7;

    int r = 2;

    printf("Combination nCr of %d and %d is, in Normal Recursive Method: %d\n", n, r, nCr(n, r));

    printf("Combination nCr of %d and %d is, in Pascal Triangle Based Recursive Method: %d\n", n, r, nCrPascalTriangle(n, r));

    return 0;
}
