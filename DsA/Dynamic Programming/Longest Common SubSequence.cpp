#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int maxVal(int a,int b);

int LongestCommonSubSequence(char *A,char *B,int x,int y)
{
    int LCS[x+1][y+1];

    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 || j==0)
            {
                LCS[i][j]=0;
            }
            else if(A[i-1]==B[j-1])
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else
            {
                LCS[i][j]=maxVal(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
    return LCS[x][y];
}

int maxVal(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    cout<<"Don't Put Any Spaces"<<endl;
    cout<<"Input First String Set:";
    string firstString;
    cin>>firstString;
    int firstStringLength=firstString.length();
    char firstStringArray[firstStringLength+1];
    strcpy(firstStringArray,firstString.c_str());

    cout<<"Input Second String Set:";
    string secondString;
    cin>>secondString;
    int secondStringLength=secondString.length();
    char secondStringArray[secondStringLength+1];
    strcpy(secondStringArray,secondString.c_str());

    cout<< "Length of Longest Common SubSequence :"<< LongestCommonSubSequence(firstStringArray,secondStringArray,firstStringLength,secondStringLength);
    return 0;
}
