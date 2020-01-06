#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}
*firstNode = NULL, *secondNode = NULL;

void Display(struct Node *pointNode)
{
    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }
}

void createNodesFirst(int array [], int numberOfNodes)
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

void createNodesSecond(int array [], int numberOfNodes)
{
    struct Node *tempNode, *lastNode;

    secondNode = (struct Node *) malloc(sizeof(struct Node));

    secondNode->data = array[0];

    secondNode->next = NULL;

    lastNode = secondNode;

    for(int i = 1; i < numberOfNodes; i++)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = array[i];

        tempNode->next = NULL;

        lastNode->next = tempNode;

        lastNode = tempNode;
    }
}


void Merge(struct Node *pointNodeFirst, struct Node *pointNodeSecond)
{
    struct Node *tempNode, *lastNode;

    if(pointNodeFirst->data < pointNodeSecond->data)
    {
        tempNode = lastNode = pointNodeFirst;

        pointNodeFirst = pointNodeFirst->next;

        tempNode->next = NULL;
    }
    else
    {
        tempNode = lastNode = pointNodeSecond;

        pointNodeSecond = pointNodeSecond->next;

        tempNode->next = NULL;
    }

    while(pointNodeFirst && pointNodeSecond)
    {
        if(pointNodeFirst->data < pointNodeSecond->data)
        {
            lastNode->next = pointNodeFirst;

            lastNode = pointNodeFirst;

            pointNodeFirst = pointNodeFirst->next;

            lastNode->next = NULL;
        }
        else
        {
            lastNode->next = pointNodeSecond;

            lastNode = pointNodeSecond;

            pointNodeSecond = pointNodeSecond->next;

            lastNode->next = NULL;
        }
    }

    if(pointNodeFirst)
    {
        lastNode->next = pointNodeFirst;
    }

    if(pointNodeSecond)
    {
        lastNode->next = pointNodeSecond;
    }

    pointNodeFirst = NULL;

    pointNodeSecond = NULL;

    firstNode = tempNode;
}

int main()
{
    int arrayOne [] = {1, 3, 5, 7, 9};

    int arrayTwo [] = {2, 4, 6, 8, 10};

    printf("\nDisplaying First Linked List: ");

    createNodesFirst(arrayOne, 5);

    Display(firstNode);

    printf("\n");

    printf("\nDisplaying Second Linked List: ");

    createNodesSecond(arrayTwo, 5);

    Display(secondNode);

    printf("\n");

    printf("\nDisplaying After Merging Two Sorted Linked List: ");

    Merge(firstNode, secondNode);

    Display(firstNode);

    printf("\n");
}
