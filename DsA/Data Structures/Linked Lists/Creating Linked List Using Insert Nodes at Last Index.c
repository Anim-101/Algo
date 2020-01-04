#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}
*firstNode = NULL, *lastNode = NULL;

void Display(struct Node *pointNode)
{
    printf("\nDisplaying Linked List's Node Values: ");

    while(pointNode != NULL)
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }

    printf("\n");
}

void insertNodeLast(int setValue)
{
    struct Node *tempNode;

    tempNode = (struct Node *) malloc(sizeof(struct Node));

    tempNode->data = setValue;

    tempNode->next = NULL;

    if(firstNode == NULL)
    {
        firstNode = tempNode;

        lastNode = tempNode;
    }
    else
    {
        lastNode->next = tempNode;

        lastNode = tempNode;
    }
}

int main()
{
    insertNodeLast(1);

    insertNodeLast(2);

    insertNodeLast(3);

    Display(firstNode);

    return 0;
}
