#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    printf("How many values to Input :");
    int arrVal;
    scanf("%d",&arrVal);
    int arr[arrVal],loc=0;

    printf("Put those values:\n");

    for(int i=1;i<=arrVal;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Value to Fine :");
    int val;
    scanf("%d",&val);

    for(int i=1;i<=arrVal;i++)
    {
        if(arr[i]==val)
        {
            loc=i;
            break;
        }
    }

    if(loc==0)
    {
        printf("\nItem couldn't be found\n");
    }
    else
    {
        printf("\nItem Found\nIt was available in %dth Postion\n",loc);
    }
    return 0;
}
