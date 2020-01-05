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

    firstNode = (struct Node * ) malloc(sizeof(struct Node));

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

void Concate(struct Node *pointFirstNode, struct Node *pointSecondNode)
{
    struct Node *pointNode = pointFirstNode;

    while(pointNode->next != NULL)
    {
        pointNode = pointNode->next;
    }

    pointNode->next = pointSecondNode;

    pointSecondNode = NULL;
}

int main()
{
    int arrayOne [] = {1, 2, 3, 4, 5};

    int arrayTwo [] = {6, 7, 8, 9, 10};

    printf("\nDisplaying Linked List First: ");

    createNodesFirst(arrayOne, 5);

    Display(firstNode);

    printf("\n");

    printf("\nDisplaying Linked List Second: ");

    createNodesSecond(arrayTwo, 5);

    Display(secondNode);

    printf("\n");

    printf("\nDisplaying After Concating Two Linked List: ");

    Concate(firstNode, secondNode);

    Display(firstNode);

    printf("\n");

    return 0;
}
