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

void Display(struct Node *pointNode)
{
    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }
}

void Insert(int index, int data)
{
    struct Node *tempNode, *pointNode;

    if(index == 0)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = data;

        tempNode->next = firstNode;

        firstNode = tempNode;
    }
    else
    {
        pointNode = firstNode;

        for(int i = 0; i < index - 1 && pointNode; i++)
        {
            pointNode = pointNode->next;
        }

        if(pointNode)
        {
            tempNode = (struct Node *) malloc(sizeof(struct Node));

            tempNode->data = data;

            tempNode->next = pointNode->next;

            pointNode->next = tempNode;
        }
    }
}

int main()
{
    int array [] = {1, 2, 3, 4, 5};

    printf("\nDisplaying Before Inserting Extra Node: ");

    createNodes(array, 5);

    Display(firstNode);

    printf("\n");

    printf("\nDisplaying After Inserting Extra Node: ");

    Insert(5, 6);

    Display(firstNode);

    printf("\n");

    return 0;
}
