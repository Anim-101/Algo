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

void recursiveDisplayDataFirstLinkedList(struct Node *pointNode)
{
   if(pointNode != NULL)
   {
       printf("%d ", pointNode->data);

       recursiveDisplayDataFirstLinkedList(pointNode->next);
   }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("\n");

    createNodes(array, 10);

    recursiveDisplayDataFirstLinkedList(firstNode);

    printf("\n");

    return 0;
}
