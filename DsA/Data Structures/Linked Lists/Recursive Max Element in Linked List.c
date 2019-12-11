#include<stdio.h>
#include<stdlib.h>

int MIN_INT = -32768;

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
    printf("\nDisplaying Elements from Given Linked List: ");

    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }

    printf("\n");
}

int recursiveMaxElement(struct Node *pointNode)
{
    int x = 0;

    if(pointNode == NULL)
    {
        return MIN_INT;
    }
    else
    {
        x = recursiveMaxElement(pointNode->next);

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
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    displayNodes(firstNode);

    printf("\nMax Nodes' Element in Given Linked List Recursively: %d\n", recursiveMaxElement(firstNode));

    return 0;
}
