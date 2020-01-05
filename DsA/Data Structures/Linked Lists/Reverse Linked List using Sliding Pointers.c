#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}
*firstNode = NULL;

void Display(struct Node *pointNode)
{
    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }
}

void createNodes(int array [], int numberOfNodes)
{
    struct Node *tempNode,  *lastNode;

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

void reverseUsingSlidingPointers(struct Node *pointNode)
{
    struct Node *tempNode = NULL, *lastNode = NULL;

    while(pointNode != NULL)
    {
        lastNode = tempNode;

        tempNode = pointNode;

        pointNode = pointNode->next;

        tempNode->next = lastNode;
    }

    firstNode = tempNode;
}

int main()
{
    int array [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    printf("\nDisplaying Linked List Before Reversing using Sliding Pointers: ");

    Display(firstNode);

    printf("\n");

    reverseUsingSlidingPointers(firstNode);

    printf("\nDisplaying Lined List After Reversing using Sliding Pointers: ");

    Display(firstNode);

    printf("\n");

    return 0;
}
