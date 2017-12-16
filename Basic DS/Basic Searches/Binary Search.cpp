#include<iostream>
#include<stdio.h>
using namespace std;

int main ()
{
    printf("How many values you want to Input :");
    int val;
    scanf("%d",&val);
    int binary[val];
    printf("Input values:\n");

    for (int i=1;i<=val;i++)
    {
        scanf("%d",&binary[i]);
    }

    printf("Value you want to Search :");
    int item;
    scanf("%d",&item);

    int big=1,end=val,mid,loc;
    mid= (int) ((big+end)/2);

    while((big<=end) && (binary[mid]!=item))
    {
        if(item<binary[mid])
        {
            end=mid-1;
        }
        else
        {
            big=mid+1;
        }
        mid= (int) ((big+end)/2);
    }

    if(binary[mid]==item)
    {
        loc=mid;
    }
    else
    {
        loc=0;
    }

    if(loc!=0)
    {
        printf("\nYour value was found in %dth Position\n",loc);
    }
    else
    {
        printf("\nValue couldn't find");
    }
    return 0;
}
