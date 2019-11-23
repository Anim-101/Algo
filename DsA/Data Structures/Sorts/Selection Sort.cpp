#include<iostream>
#include<stdio.h>

using namespace std;

int main ()
{
    int size,position=0,temp=0;
    cout << "How Many Values Do You Want to Take for Selection Sort :";
    cin >> size;
    int selectionSort[size];
    printf("Input %d Values :\n",size);
    for (int i=1;i<=size;i++)
    {
        scanf("%d",&selectionSort[i]);
    }
    cout << "Sorted Values of Array Using Selection Sort Technique :\n";
    for (int i=1;i<=size;i++)
    {
        temp=selectionSort[i];
        position=i;
        for (int j=i+1;j<=size;j++)
        {
            if(selectionSort[j]<=selectionSort[i])
            {
                selectionSort[i]=selectionSort[j];
                position=j;
            }
        }
        selectionSort[position]=temp;

    }
    for (int i=1;i<=size;i++)
    {
        cout << selectionSort[i] << endl;
    }
    return 0;
}
