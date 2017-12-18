#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *next;
}*start;

class singleLinkedList
{
public:
    node *createNode(int);
    void insertBegin();
    void insertPosition();
    void insertLast();
    void deletePosition();
    void sort();
    void search();
    void update();
    void reverse ();
    void display();

    singleLinkedList()
    {
        start=NULL;
    }
};

int main ()
{
    int choice,nodes,element,position,i;
    singleLinkedList sll;
    start= NULL;

    while(1)
    {
        cout << "\nOptions on a Single Linked List" <<endl;
        cout << "1.Insert Node at Beginning"<<endl;
        cout << "2.Insert Node at Last"<<endl;
        cout << "3.Insert Node Position"<< endl;
        cout << "4.Sort Single Linked List"<<endl;
        cout << "5.Delete Particular Node" <<endl;
        cout << "6.Update Node Value" << endl;
        cout << "7.Search Element" << endl;
        cout << "8.Display Linked List" <<endl;
        cout << "9.Reverse Linked List" <<endl;
        cout << "10.Exit"<<endl;
        cout << "Enter your Choice :";
        cin >>choice;

        switch(choice)
        {
            case 1:
                cout << "\nInserting Node at Beginning->\n";
                sll.insertBegin();
                cout <<endl;
                break;

            case 2:
                cout << "\nInsert Node at Last->\n";
                sll.insertLast();
                cout<<endl;
                break;

            case 3:
                cout << "\nInserting node at a given Position->\n";
                sll.insertPosition();
                break;

            case 4:
                cout <<  "\nSorted Single Linked List->" <<endl;
                sll.sort();
                break;

            case 5:
                cout << "\nDelete Particular Node->";
                sll.deletePosition();
                break;

            case 6:
                 cout << "\nUpdate Node Value->";
                 sll.update();
                 break;

            case 7:
                cout << "\nSearch Element in Single Linked List->";
                sll.search();
                cout << endl;
                break;

            case 8:
                cout << "\nDisplay Elements of Single Linked List->" <<endl;
                sll.display();
                break;

            case 9:
                cout << "\nReverse Elements of Single Linked List->" <<endl;
                sll.reverse();
                cout <<endl;
                break;

            case 10:
                cout << "Exit!" << endl;
                exit(1);
                break;

            default:
                cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}

node *singleLinkedList::createNode(int value)
{
    struct node *temp, *s;
    temp= new(struct node);

    if(temp==NULL)
    {
        cout << "Memory no Allocated" << endl;
        return 0;
    }
    else
    {
        temp->info=value;
        temp->next=NULL;
        return temp;
    }
}

void singleLinkedList::insertBegin()
{
    int value;
    cout << "Enter the Value to be Inserted:";
    cin >> value;
    struct node *temp, *p;
    temp = createNode(value);
    if(start==NULL)
    {
        start=temp;
        start->next=NULL;
    }
    else
    {
        p=start;
        start=temp;
        start->next=p;
    }
    cout << "Element Inserted at Beginning" << endl;
}

void singleLinkedList::insertLast()
{
    int value;
    cout << "Enter Value to be Inserted :";
    cin>>value;
    struct node *temp,*s;
    temp= createNode(value);
    s=start;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    temp->next=NULL;
    s->next=temp;
    cout << "Element has Inserted at Last" << endl;
}

void singleLinkedList::insertPosition()
{
    int value,position,count=0;
    cout << "Enter the value to be Inserted:";
    cin >> value;
    struct node *temp,*s,*ptr;
    temp=createNode(value);
    cout << "Enter the position at which node to be Inserted:";
    cin >> position;
    int i;
    s=start;
    while(s!=NULL)
    {
        s=s->next;
        count++;
    }
    if(position==1)
    {
        if(start==NULL)
        {
            start=temp;
            start->next=NULL;
        }
        else
        {
            ptr=start;
            start=temp;
            start->next=ptr;
        }
    }
    else if (position >1 && position <= count)
    {
        s =start;
        for (int i=1;i<position;i++)
        {
            ptr=s;
            s=s->next;
        }
        ptr->next=temp;
        temp->next=s;
    }
    else
    {
        cout << "Position out of range" << endl;
    }
}

void singleLinkedList::sort()
{
    struct node *ptr,*s;
    int value;
    if(start==NULL)
    {
        cout <<"The List is Empty"<<endl;
        return;
    }
    ptr=start;
    while(ptr!=NULL)
    {
        for(s=ptr->next;s!=NULL;s=s->next)
        {
            if(ptr->info>s->info)
            {
                value=ptr->info;
                ptr->info=s->info;
                s->info=value;
            }
        }
        ptr=ptr->next;
    }
}

void singleLinkedList::deletePosition()
{
    int position,i,count=0;
    if(start==NULL)
    {
        cout << "List is Empty" <<endl;
        return;
    }
    cout << "Enter the Position of Value to be deleted:";
    cin >> position;
    struct node *s,*ptr;
    s=start;
    if(position==1)
    {
        start=s->next;
    }
    else
    {
        while(s!=NULL)
        {
            s=s->next;
            count++;
        }
        if(position> 0&& position<=count)
        {
            s=start;
            for(i=1;i<position;i++)
            {
                ptr=s;
                s=s->next;
            }
            ptr->next=s->next;
        }
        else
        {
            cout << "Position out of Range"<<endl;
        }
        free(s);
        cout <<"Element Deleted" << endl;
    }
}

void singleLinkedList::update()
{
    int value,position,i;
    if(start==NULL)
    {
        cout << "List is Already Empty"<<endl;
        return;
    }
    cout << "Enter the node Position to be Updated:";
    cin >> position;
    cout << "Enter the new Value:";
    cin >> value;
    struct node *s,*ptr;
    s=start;
    if(position==1)
    {
        start->info=value;
    }
    else
    {
        for(i=0;i<position-1;i++)
        {
            if(s==NULL)
            {
                cout << "There are less then" << position << " Element!" <<endl;
                return;
            }
            s=s->next;
        }
        s->info=value;
    }
    cout <<"Node Updated" << endl;
}

void singleLinkedList::search()
{
    int value,position=0;
    bool flag=false;
    if(start==NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    cout << "Enter the value to be Searched:";
    cin >> value;
    struct node *s;
    s=start;
    while(s!=NULL)
    {
        position++;
        if(s->info==value)
        {
            flag=true;
            cout << "Element " << value <<" is Found at Position "<<position<<endl;
        }
        s=s->next;
    }
    if(!flag)
    {
        cout << "Element " << value<< " not Found in the List"<<endl;
    }
}

void singleLinkedList::reverse()
{
    struct node *ptr1,*ptr2,*ptr3;
    if(start==NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    if(start->next==NULL)
    {
        return;
    }
    ptr1=start;
    ptr2=ptr1->next;
    ptr3=ptr2->next;
    ptr1->next=NULL;
    ptr2->next=ptr1;

    while(ptr3!=NULL)
    {
        ptr1=ptr2;
        ptr2=ptr3;
        ptr3=ptr3->next;
        ptr2->next=ptr1;
    }
    start=ptr2;
}

void singleLinkedList::display()
{
    struct node *temp;
    if(start==NULL)
    {
        cout << "This List is Empty" << endl;
        return;
    }
    temp =start;
    cout << "Elements of List are :"<<endl;
    while(temp!=NULL)
    {
        cout << temp->info <<"->";
        temp=temp->next;
    }
    cout << "NULL"<<endl;
}
