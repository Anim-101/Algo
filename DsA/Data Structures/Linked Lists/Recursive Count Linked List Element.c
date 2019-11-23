#include<stdio.h>
#include<stdlib.h>

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

int countLinkedListElementRecursive(struct Node *pointNode)
{
    if(pointNode == NULL)
    {
        return 0;
    }
    else
    {
        return countLinkedListElementRecursive(pointNode->next) + 1;
    }
}

int main()
{
    int array [] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    createNodes(array, 10);

    printf("\nDisplaying Linked List's Nodes, Recursively:\n\n");

    displayNodesRecursive(firstNode);

    printf("\n\nCount of Linked List's Elements Recursively: %d\n", countLinkedListElementRecursive(firstNode));

    return 0;
}
