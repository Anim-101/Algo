#include<iostream>
#include<stdio.h>

using namespace std;

int main ()
{
    int size,swap;
    cout << "What will be the size of Data Array ?" << endl;
    cin >> size;
    int bubbleSort[size];
    printf("\nInput %d Values :\n",size);
    for (int i=1;i<=size;i++)
    {
        scanf("%d",&bubbleSort[i]);
    }
    cout << "Sorted Values using Bubble Sort Technique :" << endl;
    for (int i=1;i<size;i++)
    {
        for (int j=1;j<size;j++)
        {
            if (bubbleSort[j]>bubbleSort[j+1])
            {
                swap=bubbleSort[j];
                bubbleSort[j]=bubbleSort[j+1];
                bubbleSort[j+1]=swap;
            }
        }
    }
    for (int i=1;i<=size;i++)
    {
        cout << bubbleSort[i] << endl;
    }
    return 0;
}
