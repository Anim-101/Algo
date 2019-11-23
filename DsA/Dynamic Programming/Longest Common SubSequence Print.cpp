#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

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

void printLCS(char *X,char *Y,int x,int y)
{
    int LCS[x+1][y+1];

    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0||j==0)
            {
                LCS[i][j]=0;
            }
            else if(X[i-1]==Y[j-1])
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else
            {
                LCS[i][j]=maxVal(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }

    int num=LCS[x][y];
    char LCSChar[num+1];
    LCSChar[num+1]='\0';

    int i=x,j=y;
    while(i>0&&j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            LCSChar[num-1]=X[i-1];
            i--;
            j--;
            num--;
        }
        else if(LCS[i-1][j]>LCS[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<"LCS of "<<X<<" and "<<Y<<" is :"<<LCSChar<<endl;
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

    printLCS(firstStringArray,secondStringArray,firstStringLength,secondStringLength);
    return 0;
}
