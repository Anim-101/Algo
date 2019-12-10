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
    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }
}

int recursiveCountElements(struct Node *pointNode)
{
    if(pointNode == NULL)
    {
        return 0;
    }
    else
    {
        return recursiveCountElements(pointNode->next) + 1;
    }
}

int recursiveCountElementsUsingVariable(struct Node *pointNode)
{
    int x = 0;

    if(pointNode == NULL)
    {
        return x;
    }
    else
    {
        x = recursiveCountElementsUsingVariable(pointNode->next);

        return x + 1;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    printf("\n");

    displayNodes(firstNode);

    printf("\n");

    printf("\nCounting Elements from Given Linked List Using Recursion: %d\n", recursiveCountElements(firstNode));

    printf("\nCounting Elements from Given Linked List Using Variable in Recursive Call: %d\n", recursiveCountElementsUsingVariable(firstNode));

    return 0;
}
