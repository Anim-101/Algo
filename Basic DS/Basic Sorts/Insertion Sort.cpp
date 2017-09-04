#include<iostream>
#include<stdio.h>

using namespace std;

int main ()
{
    cout << "What will be the Size of Array ?\n";
    int size,j,temp;
    scanf("%d",&size);
    int insesrtionSort[size];
    printf("Enter %d Values\n",size);
    for (int i=1;i<=size;i++)
    {
        cin >> insesrtionSort[i];
    }
    printf("Sorted Array using Insertion Sort Technique\n");
    for (int i=1;i<=size;i++)
    {
        j=i;
        while(j>=1)
        {
            if(insesrtionSort[j-1]>insesrtionSort[j])
            {
                temp=insesrtionSort[j];
                insesrtionSort[j]=insesrtionSort[j-1];
                insesrtionSort[j-1]=temp;
            }
            else
            {
                break;
            }
            j--;
        }
    }

    for (int i=0;i<size;i++)
    {
        cout << insesrtionSort[i] << endl;
    }
    return 0;
}
