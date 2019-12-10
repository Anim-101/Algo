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
    printf("\nDisplaying Nodes: ");

    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }

    printf("\n");
}

struct Node * moveToFrontLinearSearch(struct Node *pointNode, int key)
{
    struct Node *previousPointNode;

    while(pointNode != NULL)
    {
        if(key == pointNode->data)
        {
            previousPointNode->next = pointNode->next;

            pointNode->next = firstNode;

            firstNode = pointNode;

            return pointNode;
        }

        previousPointNode = pointNode;

        pointNode = pointNode->next;
    }

    return NULL;
}

int main()
{
    struct Node *tempNode;

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    displayNodes(firstNode);

    tempNode = moveToFrontLinearSearch(firstNode, 7);

    if(tempNode != NULL)
    {
        printf("\nValue Found\n");
    }
    else
    {
        printf("\nValue Not Found\n");
    }

    displayNodes(firstNode);

    return 0;
}
