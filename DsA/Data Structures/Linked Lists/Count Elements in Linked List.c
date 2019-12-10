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
    printf("\n");

    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }

    printf("\n\n");
}

int countElements(struct Node *pointNode)
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
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    displayNodes(firstNode);

    printf("Number of Elements in Given Linked List: %d\n", countElements(firstNode));

    return 0;
}
