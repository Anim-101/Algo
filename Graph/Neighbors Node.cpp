#include<stdio.h>
#include<iostream>
using namespace std;
void neighbor_node (int);
int main ()
{
    int v;
    cout << "How Many Vertices :";
    scanf("%d",&v);
    neighbor_node (v);
    return 0;
}
void neighbor_node (int v)
{
    printf("Enter vertices :\n");
    int adj[v],adjacent[v][v];
    for (int i=1;i<=v;i++)
    {
        scanf("%d",&adj[i]);
    }

    cout <<"Put 1 if Vertices are conected or Put 0 if Vertices are not Connected :\n\n";
    for (int i=1;i<=v;i++)
    {
        cout << "\nFor Vertecs :" <<i << endl << endl;
        for (int j=1;j<=v;j++)
        {
            cout << j << " Conenected :";
            scanf("%d",&adjacent[i][j]);
        }

    }

     cout <<"\nYour Adjacent Matrix is :" << endl;
    cout << "    ";
    for (int k=1;k<=v;k++)
      {
            printf("%d ",k);
      }
      printf("\n");
      cout << "   ";
      for (int k=1;k<=v;k++)
      {
            printf(" _");
      }
      printf("\n\n");
          for (int i=1;i<=v;i++)
            {
                for (int j=1;j<=v;j++)
                    {
                        if (j==1)
                        {
                            printf("%d | ",i);
                        }
                        if (adjacent[i][j]==1)
                        {
                            printf("1");
                            printf(" ");
                        }
                        else
                        {
                            printf("0");
                            printf(" ");
                        }
                    }
                    printf("\n");
            }
        int count;
        cout <<"\n\nNow Neighbor Nodes are :\n\n";
        for (int i=1;i<=v;i++)
        {
            count=0;
            cout <<"For Node " << i << " Neighbor Nodes are :";
            for (int j=1;j<=v;j++)
            {
                if (i==j)
                {
                    continue;
                }
                else if (adjacent[i][j]==1)
                {
                    printf (" %d",j);
                    count++;
                }
            }
            if (count==0)
            {
                printf(" Nill");
            }
            printf("\n");
        }

}
