#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *previous;
    struct Node *next;
    int data;
}
*firstNode = NULL;

void createNodes(int array[], int numberOfNodes)
{
    struct Node *tempNode, *lastNode;

    firstNode = (struct Node *) malloc(sizeof(struct Node));

    firstNode->data = array[0];

    firstNode->previous = firstNode->next = NULL;

    lastNode = firstNode;

    for(int i = 1; i < numberOfNodes; i++)
    {
        tempNode = (struct Node *)  malloc(sizeof(struct Node));

        tempNode->data = array[i];

        tempNode->next = lastNode->next;

        tempNode->previous = lastNode;

        lastNode->next = tempNode;

        lastNode = tempNode;
    }
}

void Display(struct Node *pointNode)
{
    while(pointNode)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }

    printf("\n");
}

int Length(struct Node *pointNode)
{
    int length = 0;

    while(pointNode)
    {
        length++;

        pointNode = pointNode->next;
    }

    return length;
}

void Insert(struct Node *pointNode, int index, int value)
{
    struct Node *tempNode;

    if(index < 0 || index > Length(pointNode))
    {
        return;
    }

    if(index == 0)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = value;

        tempNode->previous = NULL;

        tempNode->next = firstNode;

        tempNode->previous = tempNode;

        firstNode = tempNode;
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            pointNode = pointNode->next;
        }

        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = value;

        tempNode->previous = pointNode;

        tempNode->next = pointNode->next;

        if(pointNode->next)
        {
            pointNode->next->previous = tempNode;
        }

        pointNode->next = tempNode;
    }
}

int main()
{
    int array[] = {10, 20, 30, 50, 60};

    createNodes(array, 5);

    printf("\nNodes in Doubly Linked List: ");

    Display(firstNode);

    printf("\nInserting 40 at 4th Position: \n");

    Insert(firstNode, 3, 40);

    printf("\nInsertion Successful\n");

    printf("\nAfter Inserting Nodes in Doubly Linked List: ");

    Display(firstNode);

    return 0;
}
