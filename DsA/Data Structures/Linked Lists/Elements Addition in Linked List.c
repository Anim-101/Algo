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

int additionElements(struct Node *pointNode)
{
    int sum = 0;

    while(pointNode != NULL)
    {
        sum = sum + pointNode->data;

        pointNode = pointNode->next;
    }

    return sum;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    printf("\n");

    displayNodes(firstNode);

    printf("\n");

    printf("\nAddition of Linked List Nodes' Elements: %d\n", additionElements(firstNode));

    return 0;
}
