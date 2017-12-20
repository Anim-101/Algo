#include<iostream>
#include<stdio.h>
using namespace std;

void quickSort(int [],int,int);

int main()
{
    int size;
    cout<<"Enter the Number of Element :";
    cin>>size;
    int arr[size];
    cout<<"\nEnter the Elements to be Sorted:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    quickSort(arr,0,size-1);
    cout<<"After Applying Quick Sort :\n";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}

void quickSort(int arr[],int low,int high)
{
    int pivot,temp,i,j;
    if(low<high)
    {
        pivot=low;
        i=low;
        j=high;
        while(i<j)
        {
            while(arr[i]<=arr[pivot] && i<=high)
            {
                i++;
            }
            while(arr[j]>arr[pivot] && j>=low)
            {
                j--;
            }
            if(i<j)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[j];
        arr[j]=arr[pivot];
        arr[pivot]=temp;
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}

