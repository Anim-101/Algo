#include<stdio.h>

double taylor(int power, int nThTerm)
{
    static double pow = 1.00, fact = 1.00;

    double taylorSumE;

    if(nThTerm == 0.00)
    {
        return 1;
    }
    else
    {
        taylorSumE = taylor(power, nThTerm - 1);

        pow = pow * power;

        fact = fact * nThTerm;

        return taylorSumE + (pow / fact);
    }
}

int main()
{
    double power = 4.00, nThTerm = 100.00;

    printf("For Power %lf till %lf Term, Taylor Series Provides Value of e: %lf", power, nThTerm, taylor(power, nThTerm));

    return 0;
}
