#include<iostream>
using namespace std;

void maxHeapify(int arr[],int i,int n)
{
    int j,temp;
    temp=arr[i];
    j=2*i;
    while(j<=n)
    {
        if(j<n && arr[j+1]>arr[j])
        {
            j=j+1;
        }
        if(temp>arr[j])
        {
            break;
        }
        else if(temp<=arr[j])
        {
            arr[j/2]=arr[j];
            j=2*j;
        }
    }
    arr[j/2]=temp;
    return;
}

void heapSort(int arr[],int n)
{
    int temp;
    for(int i=n;i>=2;i--)
    {
        temp=arr[i];
        arr[i]=arr[1];
        arr[1]=temp;
        maxHeapify(arr,1,i-1);
    }
}

void buildMaxHeap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        maxHeapify(arr,i,n);
    }
}

int main()
{
    int n;
    cout<<"\nEnter the Number of Data element to be Sorted:";
    cin>>n;
    int arr[n++];
    for(int i=1;i<n;i++)
    {
        cout<<"Enter Element "<<i<<" :";
        cin>>arr[i];
    }
    buildMaxHeap(arr,n-1);
    heapSort(arr,n-1);

    cout<<"\nSorted Data (Heap Sort):";
    for(int i=1;i<n;i++)
    {
        cout<<"->"<<arr[i];
    }
    return 0;
}
