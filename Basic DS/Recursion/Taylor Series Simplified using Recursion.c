#include<stdio.h>

double  taylorSimplifiedRecursion(double power, double nthTerm)
{
    static double sum = 1.00;

    if(nthTerm == 0.00)
    {
        return sum;
    }
    else
    {
        sum = 1.00 + (power / nthTerm) * sum;

        return taylorSimplifiedRecursion(power, nthTerm - 1.00);
    }
}


int main()
{
    double power = 1.00, nthTerm = 20.00;

    printf("Using Simplified Taylor Series for Power %lf till %lf term, e = %lf\n", power, nthTerm, taylorSimplifiedRecursion(power, nthTerm));

    return 0;
}
