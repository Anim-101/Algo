#include<stdio.h>
#include<stdlib.h>

int MIN_INT = -32768;

struct Node
{
    int data;
    struct Node *next;
}
*firstNode;

void createNodes(int array[], int numberOfNodes)
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

void displayNodes(struct Node *pointNode)
{
    printf("\nDisplay Nodes:\n\n");

    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }

    printf("\n");
}

int maxNodesElements(struct Node *pointNode)
{
    int max = MIN_INT;

    while(pointNode != NULL)
    {
        if(pointNode->data > max)
        {
            max = pointNode->data;
        }

        pointNode = pointNode->next;
    }

    return max;
}

int main()
{
    int array [] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    createNodes(array, 10);

    displayNodes(firstNode);

    printf("\nMaximum Nodes' Element Value in Given List: %d\n", maxNodesElements(firstNode));

    return 0;
}
