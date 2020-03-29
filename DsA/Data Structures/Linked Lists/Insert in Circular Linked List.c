#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}
*headNode;

void createNodes(int array[], int numberOfNodes)
{
    struct Node *tempNode, *lastNode;

    headNode = (struct Node *) malloc(sizeof(struct Node));

    headNode->data = array[0];

    headNode->next = headNode;

    lastNode = headNode;

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
        printf("%d", pointNode->data);

        pointNode = pointNode->next;
    }
    while(pointNode != headNode);

    printf("\n");
}

int lengthOfList(struct Node *pointNode)
{

    int length = 0;

    while(pointNode != headNode)
    {
        length++;

        pointNode = pointNode->next;
    }

    return length;
}

void insertNodes(struct Node *pointNode, int index, int data)
{
    struct Node *tempNode;

    if(index < 0 || index > lengthOfList(pointNode))
    {
        return;
    }

    if(index == 0)
    {
        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = data;

        if(headNode == NULL)
        {
            headNode = tempNode;

            headNode->next = headNode;
        }
        else
        {
            while(pointNode->next != headNode)
            {
                pointNode = pointNode->next;
            }

            pointNode->next = tempNode;

            tempNode->next = headNode;

            headNode = tempNode;
        }
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            pointNode = pointNode->next;
        }

        tempNode = (struct Node *) malloc(sizeof(struct Node));

        tempNode->data = data;

        tempNode->next = pointNode->next;

        pointNode->next = tempNode;
    }
}

int main()
{
    int array[] = {2, 3, 4, 5, 6, 7};

    createNodes(array, 6);

    printf("\nBefore Inserting, Circular Linked List: ");

    Display(headNode);

    printf("\nAfter Inserting, Circular Linked List: ");

    insertNodes(headNode, 0, 1);

    Display(headNode);

    return 0;
}

