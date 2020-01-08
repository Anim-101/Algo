#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}
*Head;

void createNodes(int array [], int numberOfNodes)
{
    struct Node *tempNode, *lastNode;

    Head = (struct Node *) malloc(sizeof(struct Node));

    Head->data = array[0];

    Head->next = Head;

    lastNode = Head;

    for(int i = 1; i < numberOfNodes; i++)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = array[i];

        tempNode->next = lastNode->next;

        lastNode->next = tempNode;

        lastNode = tempNode;
    }
}

void Display(struct Node *pointNode)
{
    do
    {
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }
    while(pointNode != Head);
}

int main()
{
    int array [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    createNodes(array, 10);

    printf("\nDisplaying Circular Linked List: ");

    Display(Head);

    printf("\n");
}
