#include<iostream>
#include<stdio.h>
using namespace std;
int Fibonacci(int n);
int main ()
{

    int n,i=0,c;
    cout << "Enter the number of Terms : ";
    scanf("%d",&n);
    printf("%dth terms are :\n",n);
    for (c=1;c<=n;c++)
    {
        printf("%d\n",Fibonacci(i));
        i++;
    }
}

int Fibonacci (int n)
{
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return (Fibonacci(n-1)+Fibonacci(n-2));
}
