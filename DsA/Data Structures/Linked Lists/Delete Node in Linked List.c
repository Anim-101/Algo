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

int Delete(struct Node *pointNode, int index)
{
    struct Node *tempNode = NULL;

    int value;

    if((index < 0) || (index > Count(pointNode)))
    {
        printf("\nIndex Overflow\n");

        return -1;
    }
    else
    {
        if(index == 1)
        {
            tempNode = firstNode;

            value = firstNode->data;

            firstNode = firstNode->next;

            free(tempNode);

            return value;
        }
        else
        {
            for(int i = 0; i < index - 1; i++)
            {
                tempNode = pointNode;

                pointNode = pointNode->next;
            }

            tempNode->next = pointNode->next;

            value = pointNode->data;

            free(pointNode);

            return value;
        }
    }
}

int main()
{
    int array [] = {1, 2, 3, 4, 5};

    createNodes(array, 5);

    printf("\nDisplaying Nodes Before Deleting Linked List: ");

    Display(firstNode);

    printf("\n");

    printf("\nDeleting Node's Value: %d\n", Delete(firstNode, 2));

    printf("\nDisplaying Nodes After Deleting Linked List: ");

    Display(firstNode);

    printf("\n");

    return 0;
}
