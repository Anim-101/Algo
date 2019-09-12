#include <stdio.h>

int FibonacciIndexArray[10];

// Finding Nth- Passed Number's Value from Fibonacci Series in Recursive Way
int fibonacciRecursion(int number)
{
    if (number <= 1)
    {
        return number;
    }
    else
    {
        return fibonacciRecursion(number - 2) + fibonacciRecursion(number - 1);
    }
}

// Finding Nth - Passed Number's Value from Fibonacci Series in Modified Recursive Way (Memoization)
int fibonacciMemoizationRecursion(int number)
{
    if (number <= 1)
    {
        FibonacciIndexArray[number] = number;

        return number;
    }
    else
    {
        if (FibonacciIndexArray[number - 2] == -1)
        {
            FibonacciIndexArray[number - 2] = fibonacciMemoizationRecursion(number - 2);
        }

        if (FibonacciIndexArray[number - 1] == -1)
        {
            FibonacciIndexArray[number - 1] = fibonacciMemoizationRecursion(number - 1);
        }

        FibonacciIndexArray[number] = FibonacciIndexArray[number - 2] + FibonacciIndexArray[number - 1];

        return FibonacciIndexArray[number - 2] + FibonacciIndexArray[number - 1];
    }
}

int main()
{
    int series = 7;

    for (int i = 0; i < series; i++)
    {
        FibonacciIndexArray[i] = -1;
    }

    printf("Fibonacci Series's %d Number Value Through Recursive Method: %d\n", series, fibonacciRecursion(series));

    printf("Fibonacci Series's %d Number Value Through Modified Recursive Method (Memoization): %d\n", series, fibonacciMemoizationRecursion(series));

    return 0;
}
