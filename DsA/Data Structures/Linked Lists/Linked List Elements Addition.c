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
    printf("\nDisplaying Nodes in Linked List:\n\n");

    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }

    printf("\n");
}

int additionNodesElements(struct Node *pointNode)
{
    int sum = 0;

    while(pointNode != NULL)
    {
        sum = sum + pointNode->data;

        pointNode = pointNode->next;
    }

    return sum;
}

int main()
{
    int array [] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    createNodes(array, 10);

    displayNodes(firstNode);

    printf("\nAddition of Linked List's Nodes' Elements: %d\n", additionNodesElements(firstNode));

    return 0;
}
