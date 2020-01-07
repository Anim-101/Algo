#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *firstNode;

public:
    LinkedList()
    {
        firstNode = NULL;
    }

    LinkedList(int array [], int numberOfNodes);

    ~LinkedList();

    void Display();

    void Insert(int index, int setValue);

    int Delete(int index);

    int Length();
};

LinkedList::LinkedList(int array [], int numberOfNodes)
{
    Node *tempNode, *lastNode;

    firstNode = new Node;

    firstNode->data = array[0];

    firstNode->next = NULL;

    lastNode = firstNode;

    for(int i = 1; i < numberOfNodes; i++)
    {
        tempNode = new Node;

        tempNode->data = array[i];

        tempNode->next = NULL;

        lastNode->next = tempNode;

        lastNode = tempNode;
    }
}

LinkedList::~LinkedList()
{
    Node *pointNode = firstNode;

    while(firstNode)
    {
        firstNode = firstNode->next;

        delete pointNode;

        pointNode = firstNode;
    }
}


void LinkedList::Display()
{
    Node *pointNode = firstNode;

    while(pointNode)
    {
        cout << pointNode->data << " ";

        pointNode = pointNode->next;
    }

    cout << endl;
}

int LinkedList::Length()
{
    Node *pointNode = firstNode;

    int length = 0;

    while(pointNode)
    {
        length++;

        pointNode = pointNode->next;
    }

    return length;
}

void LinkedList::Insert(int index, int setValue)
{
    Node *tempNode, *pointNode = firstNode;

    if(index < 0 || index > Length())
    {
        return;
    }

    tempNode = new Node;

    tempNode->data = setValue;

    tempNode->next = NULL;

    if(index == 0)
    {
        tempNode->next = firstNode;

        firstNode = tempNode;
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            pointNode = pointNode->next;
        }

        tempNode->next = pointNode->next;

        pointNode->next = tempNode;
    }
}

int LinkedList::Delete(int index)
{
    Node *tempNode, *lastNode = NULL;

    int retVal = -1;

    if(index < 1 || index > Length())
    {
        return retVal;
    }

    if(index == 1)
    {
        tempNode = firstNode;

        firstNode = firstNode->next;

        retVal = tempNode->data;

        delete tempNode;
    }
    else
    {
        tempNode = firstNode;

        for(int i = 0; i < index - 1; i++)
        {
            lastNode = tempNode;

            tempNode = tempNode->next;
        }

        lastNode->next = tempNode->next;

        retVal = tempNode->data;

        delete tempNode;
    }

    return retVal;
}

int main()
{
    int array [] = {1, 2, 3, 4, 5};

    LinkedList linkedList(array, 5);

    cout << endl << "Displaying Linked List: ";

    linkedList.Display();

    linkedList.Insert(5, 6);

    cout << endl << "Displaying Linked List After Insert: ";

    linkedList.Display();

    linkedList.Delete(6);

    cout << endl << "Displaying Linked List After Delete: ";

    linkedList.Display();

    cout << endl << "Current Linked List Length: " << linkedList.Length() << endl;

    return 0;
}
