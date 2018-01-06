#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int v;
    cout<<"How Many Vertexes :";
    cin>>v;cout<<endl;
    int adj[v][v];
    cout<<"For Connections Provide 1, 0 Otherwise"<<endl;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cout<<"Vertex "<<i<<" Has Edge with "<<j<<" :";
            cin>>adj[i][j];
        }
        cout<<endl;
    }
    cout<<"Adjacency Matrix :"<<endl;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cout<<adj[i][j];
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
