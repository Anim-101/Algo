#include<iostream>
#include<stdio.h>

using namespace std;

int stackSize=0;
int stack[0];
int top=-1;

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(top==stackSize)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int topVal ()
{
    return stack[top];
}

int pop ()
{
    int data;

    if(!isEmpty())
    {
        data=stack[top];
        top=top-1;
        return data;
    }
    else
    {
        cout << "Couldn't Retrieve Data-> Stack is Empty" <<endl;
    }
}

int push (int data)
{
    if(!isFull())
    {
        top=top+1;
        stack[top]=data;
    }
    else
    {
        printf("Couldn't Store Data-> Stack is Full");
    }
}

int main ()
{
    int choice,value=0,iteration=1;

    while(iteration==1)
    {
        cout << "Press 1 For Entering/Re-Entering ->Push Values" << endl;
        cout << "Press 2 For Pop" << endl;
        cout << "Press 3 For Top" << endl;
        cout << "Press 4 For Finding out Whether Stack is Empty or Not" << endl;
        cout << "Press Any Other Keys For Closing this Application" << endl;

        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                    cout << "What will be the size of Stack ?" << endl;
                    cin >> stackSize;
                    stack[stackSize];
                    top=-1;
                    cout << "Now Enter " << stackSize << " Values in This Stack" << endl;
                    for (int i=0;i<stackSize;i++)
                    {
                        scanf("%d",&value);
                        push(value);
                        cout << value <<" Pushed in the Stack" << endl;
                        value=0;
                    }
                    break;
            case 2:
                    if (!isEmpty())
                    {
                        cout << "Value " << pop() << " Popped" << endl;
                    }
                    else
                    {
                        pop();
                    }
                    break;
            case 3:
                    if (top==-1)
                    {
                        cout << "There is no Value Stored in Stack" << endl;
                    }
                    else
                    {
                        cout << "Current Top Value of Stack is : " << topVal() << endl;
                    }
                    break;
            case 4:
                    if (!isEmpty())
                    {
                        cout << "No Stack is not Empty" << endl;
                    }
                    else
                    {
                        printf("This Stack is Empty");
                    }
                    break;
            default:
                    iteration=0;
                    break;
        }
        printf("\n\n");
    }
    return 0;
}
