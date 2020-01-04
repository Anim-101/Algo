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

void createNodes(int array [], int numberOfNodes)
{
    struct Node *tempNode, *lastNode;

    firstNode = (struct Node *) malloc(sizeof(struct Node));

    firstNode->data = array[0];

    firstNode->next = NULL;

    lastNode = firstNode;

    for(int i = 1; i < numberOfNodes; i++)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = array[i];

        tempNode->next = NULL;

        lastNode->next = tempNode;

        lastNode = tempNode;
    }
}

int isSorted(struct Node *pointNode)
{
    int x = -32768;

    while(pointNode != NULL)
    {
        if(x > pointNode->data)
        {
            return 0;
        }

        x = pointNode->data;

        pointNode = pointNode->next;
    }

    return 1;
}

int main()
{
    int array [] = {1, 2, 3, 4, 5};

    printf("\nDisplaying Nodes: ");

    createNodes(array, 5);

    Display(firstNode);

    printf("\n");

    if(isSorted(firstNode))
    {
        printf("\nGiven Linked List is Sorted\n");
    }
    else
    {
        printf("\nGiven Linked List is Not Sorted\n");
    }

    return 0;
}
