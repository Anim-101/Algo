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

struct Node *linearSearch(struct Node *pointNode, int key)
{
    while(pointNode != NULL)
    {
        if(key == pointNode->data)
        {
            return pointNode;
        }

        pointNode = pointNode->next;
    }

    return NULL;
}

int main()
{
    struct Node *tempNode;

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    printf("\n");

    displayNodes(firstNode);

    printf("\n");

    tempNode = linearSearch(firstNode, 10);

    if(tempNode != NULL)
    {
        printf("\nValue Found\n");
    }
    else
    {
        printf("\nValue Not Fount\n");
    }

    return 0;
}
