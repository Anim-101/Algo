#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}
*firstNode = NULL;

void Display(struct Node *pointNode)
{
    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }
}

int Count(struct Node *pointNode)
{
    int count = 0;

    while(pointNode != NULL)
    {
        count++;

        pointNode = pointNode->next;
    }

    return count;
}

void Insert(struct Node *pointNode, int index, int setValue)
{
    struct Node *tempNode;

    if((index < 0) || (index > Count(firstNode)))
    {
        printf("\nIndex Overflow\n");
    }
    else
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = setValue;

        if(index == 0)
        {
            tempNode->next = firstNode;

            firstNode = tempNode;
        }
        else
        {
            for(int i = 0; i < index - 1; i++)
            {
                pointNode = pointNode->next;
            }

            tempNode->next = pointNode->next;

            pointNode->next = tempNode;
        }
    }
}

int main()
{
    Insert(firstNode, 0, 4);

    Insert(firstNode, 0, 2);

    Insert(firstNode, 0, 1);

    Insert(firstNode, 2, 3);

    Insert(firstNode, 5, 6);

    printf("\nValues After Creating Linked List Using Insert: ");

    Display(firstNode);

    printf("\n");

    return 0;
}
