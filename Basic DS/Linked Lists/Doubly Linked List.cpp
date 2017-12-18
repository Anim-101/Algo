#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;

class doublyLinkedList
{
public :
    void createList(int value);
    void insertBegin(int value);
    void insertAfter(int value, int position);
    void deleteElement(int value);
    void searchElement(int value);
    void display();
    void counter();
    void reverse();
    doublyLinkedList()
    {
        start=NULL;
    }
};

int main()
{
    int choice,element,position;
    doublyLinkedList dll;
    while(1)
    {
        cout<<"Options on Doubly Linked List!"<<endl;
        cout<<"1.Create Node"<<endl;
        cout<<"2.Insert at Beginning"<<endl;
        cout<<"3.Insert after Position"<<endl;
        cout<<"4.Search Elements"<<endl;
        cout<<"5.Delete"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Counter"<<endl;
        cout<<"8.Reverse"<<endl;
        cout<<"9.Quit"<<endl;
        cout<<endl<<"Enter your choice :";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case 1:
            cout<<"Enter the Element:";
            cin>>element;
            dll.createList(element);
            break;
        case 2:
            cout<<"Enter the Element:";
            cin>>element;
            dll.insertBegin(element);
            break;
        case 3:
            cout<<"Enter the Element:";
            cin>>element;
            cout<<"Enter The Position:";
            cin>>position;
            dll.insertAfter(element,position);
            cout<<endl;
            break;
        case 4:
            cout<<"Enter the Elements to be Searched:";
            cin>>element;
            dll.searchElement(element);
            break;
        case 5:
            if(start==NULL)
            {
                cout<<"Doubly Linked List is Empty,Nothing to Delete"<<endl;
                break;
            }
            cout<<"Enter the Element to to Delete:";
            cin>>element;
            dll.deleteElement(element);
            cout<<endl;
            break;
        case 6:
            dll.display();
            cout<<endl;
            break;
        case 7:
            dll.counter();
            break;
        case 8:
            if(start==NULL)
            {
                cout<<"Doubly Linked List is Empty,Nothing to Reverse"<<endl;
                break;
            }
            dll.reverse();
            cout<<endl;
            break;
        case 9:
            exit(1);
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}

void doublyLinkedList::createList(int value)
{
    struct node *s,*temp;
    temp=new(struct node);
    temp->info=value;
    temp->next=NULL;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        s=start;
        while(s->next!=NULL)
        {
            s=s->next;
            s->next=temp;
            temp->prev=s;
        }
    }
}

void doublyLinkedList::insertBegin(int value)
{
    if(start==NULL)
    {
        cout<<"First Create a Doubly Linked List"<<endl;
        return;
    }
    struct node *temp;
    temp=new(struct node);
    temp->prev=NULL;
    temp->next=start;
    temp->info=value;
    start->prev=temp;
    start=temp;
    cout<<"Element Inserted"<<endl;
}

void doublyLinkedList::insertAfter(int value,int position)
{
    if(start==NULL)
    {
        cout<<"First Create a Doubly Linked List"<<endl;
        return;
    }
    struct node *tempp,*p;
    int i;
    p=start;
    for(i=0;i<position-1;i++)
    {
        p=p->next;
        if(p==NULL)
        {
            cout<<"There are less than ";
            cout<<position<<" element"<<endl;
            return;
        }
    }
    tempp=new(struct node);
    tempp->info=value;
    if(p->next==NULL)
    {
        p->next=tempp;
        tempp->next=NULL;
        tempp->prev=p;
    }
    else
    {
        tempp->next=p->next;
        tempp->next->prev=tempp;
        p->next=tempp;
        tempp->prev=p;
    }
    cout<<"Elements Inserted"<<endl;
}

void doublyLinkedList::searchElement(int value)
{
    if(start==NULL)
    {
        cout<<"Doubly Linked List is Empty,Nothing to Search"<<endl;
        return;
    }
    struct node *s;
    s=start;
    if(s->next==NULL)
    {
        if(s->info==value)
        {
            cout<<"Element Found in Start Position"<<endl;
            return;
        }
        else
        {
            cout<<"Element not Found in Start Position,\nTry Inserting or Create a new Node and Input more Elements"<<endl;
            return;
        }
    }
    else
    {
        int count=0;
        while(s->next!=NULL)
        {
            count++;
            if(s->info==value)
            {
                cout<<"Element Found in "<<count<<" Position"<<endl;
                return;
            }
            s=s->next;
        }
        if(count!=0)
        {
            cout<<"Element not Found"<<endl;
            return;
        }
    }
}

void doublyLinkedList::deleteElement(int value)
{
    struct node *tmp,*p;
    if(start->info==value && start->next!=NULL)
    {
        tmp=start;
        start=start->next;
        start->prev=NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    else if (start->info==value && start->next==NULL)
    {
        start=NULL;
        return;
    }
    p=start;
    while(p->next->next!=NULL)
    {
        if(p->next->info==value)
        {
            tmp=p->next;
            p->next=tmp->next;
            tmp->next->prev=p;
            cout<<"Elements Deleted"<<endl;
            free(tmp);
            return;
        }
        p=p->next;
    }
    if(p->next->info==value)
    {
        tmp=p->next;
        free(tmp);
        p->next=NULL;
        cout<<"Elements Deleted"<<endl;
        return;
    }
    cout <<"Element "<<value<<" Not Found"<<endl;
}

void doublyLinkedList::display()
{
    struct node *s;
    if(start==NULL)
    {
        cout<<"Doubly Linked List is Empty,Nothing to Display"<<endl;
        return;
    }
    s=start;
    cout<<"The Doubly Linked List is :"<<endl;
    while(s!=NULL)
    {
        cout<<s->info<<" <-> ";
        s=s->next;
    }
    cout<<"NULL"<<endl;
}

void doublyLinkedList::counter()
{
   struct node *q;
   q=start;
   int count=0;
   while(q!=NULL)
   {
       q=q->next;
       count++;
   }
   cout<<"Number of Elements are: "<<count<<endl;
}

void doublyLinkedList::reverse()
{
    struct node *n,*m;
    n=start;
    m=n->next;
    n->next=NULL;
    n->prev=m;
    while(m!=NULL)
    {
        m->prev=m->next;
        m->next=n;
        n=m;
        m=m->prev;
    }
    start=n;
    cout<<"Doubly Linked List Reversed"<<endl;
}
