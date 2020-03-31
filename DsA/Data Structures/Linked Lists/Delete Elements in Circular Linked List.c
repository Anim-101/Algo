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
        printf("%d ", pointNode->data);

        pointNode = pointNode->next;
    }
    while(pointNode != headNode);
}

int lengthOfList(struct Node *pointNode)
{
    int length = 0;

    do
    {
        length++;

        pointNode = pointNode->next;
    }
    while(pointNode != headNode);

    return length;
}

int Delete(struct Node *pointNode, int index)
{
    struct Node  *qNode;

    int value = 0;

    if(index < 0 || index > lengthOfList(headNode))
    {
        return 1;
    }

    if(index == 1)
    {
        while(pointNode->next != headNode)
        {
            pointNode = pointNode->next;
        }

        value = headNode->data;

        if(headNode == pointNode)
        {
            free(headNode);

            headNode = NULL;
        }
        else
        {
            pointNode->next = headNode->next;

            free(headNode);

            headNode = pointNode->next;
        }
    }
    else
    {
        for(int i = 1; i < index - 2; i++)
        {
            pointNode = pointNode->next;
        }

        qNode = pointNode->next;

        pointNode->next = qNode->next;

        value = qNode->data;

        free(qNode);
    }

    return value;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};

    createNodes(array, 7);

    printf("\nDisplaying Circular Linked List Before Deleting Elements: ");

    Display(headNode);

    printf("\n");

    printf("\nDeleting Element: %d, Displaying Circular Linked List After Deletion: ", Delete(headNode, 1));

    Display(headNode);

    return 0;
}
