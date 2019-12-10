#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}
*firstNode = NULL;

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
    printf("\nDisplay Nodes: ");

    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }

    printf("\n");
}

struct Node *recursiveLinearSearch(struct Node *pointNode, int key)
{
    if(pointNode == NULL)
    {
        return NULL;
    }

    if(key == pointNode->data)
    {
        return pointNode;
    }

    return recursiveLinearSearch(pointNode->next, key);
}

int main()
{
    struct Node *tempNode;

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    displayNodes(firstNode);

    tempNode = recursiveLinearSearch(firstNode, 8);

    if(tempNode == NULL)
    {
        printf("\nValue Not Found\n");
    }
    else
    {
        printf("\nValue Found\n");
    }

    return 0;
}
