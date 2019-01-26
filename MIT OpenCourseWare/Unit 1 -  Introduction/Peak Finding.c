/*
Divide & Conquer Approach - 1D Version
*/
#include<stdio.h>

int peakFinding(int arr[], int lowVal, int highVal, int n)
{
    int mid = lowVal + (highVal - lowVal)/2;

    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]))
    {
        return mid;
    }
    else if(mid > 0 && arr[mid-1] > arr[mid])
    {
        return peakFinding(arr, lowVal, (mid-1), n);
    }
    else
    {
        return peakFinding(arr, (mid+1), highVal, n);
    }
}

int main()
{
    printf("Size of Array to Pick Find: ");
    int n;
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d Elements to Find Pick From This Array:\n", n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Peak Finding Index is: %d", peakFinding(arr, 0, n-1, n));
    
    return 0;
}
