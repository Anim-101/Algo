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

void displayNodes(struct Node *pointNode)
{
    printf("\nDisplaying Nodes:\n\n");

    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }

    printf("\n");
}

int countNodes(struct Node *pointNode)
{
    int count = 0;

    while(pointNode != NULL)
    {
        count++;

        pointNode = pointNode->next;
    }

    return count;
}

int main()
{
    int array [] = {1, 3, 7, 11, 13, 17, 19, 23, 31};

    createNodes(array, 9);

    displayNodes(firstNode);

    printf("\nTotal Number of Nodes in Linked List: %d\n", countNodes(firstNode));

    return 0;
}
