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

void displayNodesRecursive(struct Node *pointNode)
{
    if(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        displayNodesRecursive(pointNode->next);
    }
}

int maxNodesElementsRecursive(struct Node *pointNode)
{
    int x  = 0;

    if(pointNode == NULL)
    {
        return MIN_INT;
    }
    else
    {
        x = maxNodesElementsRecursive(pointNode->next);

        if(x > pointNode->data)
        {
            return x;
        }
        else
        {
            return pointNode->data;
        }
    }
}

int main()
{
    int numberOfNodes;

    printf("\nNumber of Nodes in Linked List: ");

    scanf("%d", &numberOfNodes);

    int array[numberOfNodes];

    printf("\nGive %d Number of Nodes' Element:\n\n", numberOfNodes);

    for(int i = 0; i < numberOfNodes; i++)
    {
        scanf("%d", &array[i]);
    }

    createNodes(array, numberOfNodes);

    printf("\n\nDisplay Nodes Recursively:\n\n");

    displayNodesRecursive(firstNode);

    printf("\n\nMaximum Nodes' Element of Given Linked List Recursively: %d\n", maxNodesElementsRecursive(firstNode));

    return 0;
}
