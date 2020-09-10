#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
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
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = array[i];

        tempNode->previous = lastNode;

        tempNode->next = lastNode->next;

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

void Reverse(struct Node *pointNode)
{
    struct Node *tempNode;

    while(pointNode != NULL)
    {
        tempNode = pointNode->next;

        pointNode->next = pointNode->previous;

        pointNode->previous = tempNode;

        pointNode = pointNode->previous;

        if(pointNode != NULL && pointNode->next == NULL)
        {
            firstNode = pointNode;
        }
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    printf("\nDoubly Linked List: ");

    Display(firstNode);

    printf("\nReversed Doubly Linked List: ");

    Reverse(firstNode);

    Display(firstNode);

    return 0;
}
