#include<stdio.h>
#include<iostream>
using namespace std;
int main ()
{
    int lo,hi,mid,n,x,f=1,loc=1;
    cout << "Number of Elements : ";
    scanf ("%d",&n);
    int arr[n];
    lo=1;
    mid=0;
    hi=n;
    cout <<"\nInput Elements : " << endl;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    cout <<"Elements are : " << endl;
    for (int i=1;i<=n;i++)
    {
        printf("%d\n",arr[i]);
    }
    cout <<"Number to be Searched : ";
    scanf ("%d",&x);
    while (x != arr[f])
    {
        if ((lo==hi) || (arr[lo]==arr[hi]))
        {
            break;
        }
        mid = lo+((hi-lo)/(arr[hi]-arr[lo]))*(x-arr[lo]);
        if (arr[mid]<x)
        {
            lo=mid+1;
        }
        else if (arr[mid]>x)
        {
            hi=mid-1;
        }
        loc++;
        f++;
    }
    if (arr[loc]==x)

    {
        cout << "Element Found !" << endl;
        cout << "Location : " << loc << endl;
    }
    else
    {
        cout << "Element doesn't Exits !" << endl;
    }
    return 0;
}
