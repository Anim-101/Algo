#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
}
*firstNode = NULL;

void createNode(int array[], int numberOfNodes)
{
    struct Node *tempNode, *lastNode;

    firstNode = (struct Node *) malloc(sizeof(struct Node));

    firstNode->data = array[0];

    firstNode->previous = firstNode->next = NULL;

    lastNode = firstNode;

    for(int i = 1; i < numberOfNodes; i++)
    {
        tempNode = (struct Node *) malloc(sizeof (struct Node));

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

int Delete(struct Node *pointNode, int index)
{
    int x = -1;

    if(index < 1 || index > Length(pointNode))
    {
        return -1;
    }

    if(index == 1)
    {
        firstNode = firstNode->next;

        if(firstNode)
        {
            firstNode->previous = NULL;
        }

        x = pointNode->data;

        free(pointNode);
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            pointNode = pointNode->next;
        }

        pointNode->previous->next = pointNode->next;

        if(pointNode->next)
        {
            pointNode->next->previous = pointNode->previous;
        }

        x = pointNode->data;

        free(pointNode);
    }

    return x;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};

    printf("\nDisplaying Elements from Doubly Linked List: ");

    createNode(array, 5);

    Display(firstNode);

    printf("\nDeleting from Doubly Linked List, Position = 3, Deleted Item = %d\n", Delete(firstNode, 3));

    printf("\nAfter Deletion, Doubly Linked List: ");

    Display(firstNode);
}
