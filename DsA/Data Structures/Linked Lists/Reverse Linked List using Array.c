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

int Count(struct Node *pointNode)
{
    int count = 0;

    while(pointNode != NULL)
    {
        count++;

        pointNode = pointNode->next;
    }

    return count;
}

void createNodes(int array [], int numberOfNodes)
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

void reverseUsingArray(struct Node *pointNode)
{
    int *array;

    array = (int *) malloc(sizeof(int) * Count(pointNode));

    struct Node *tempNode = pointNode;

    int i = 0;

    while(tempNode != NULL)
    {

        array[i] = tempNode->data;

        tempNode = tempNode->next;

        i++;
    }

    tempNode = firstNode;

    i--;

    while(tempNode != NULL)
    {
        tempNode->data = array[i];

        tempNode = tempNode->next;

        i--;
    }
}

int main()
{
    int array [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    printf("\nDisplaying Before Reversing using Array: ");

    Display(firstNode);

    printf("\n");

    reverseUsingArray(firstNode);

    printf("\nDisplaying After Reversing Using Array: ");

    Display(firstNode);

    printf("\n");

    return 0;
}
