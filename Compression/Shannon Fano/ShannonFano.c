#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BitIO.h"
#include"ShannonFano.h"

/*
Possibility for a a new nodes that it can be a parent node
which also can have two child nodes as firstChild and secondChild
Thus ShannonFano_MAX * 3 [Static Implementations->Faster Process]
*/
unsigned int shannonFanoCount=0;
shannonFanoFrequency_Type sffreq[ShannonFano_MAX];
listnode_t *list=NULL,*top=NULL;
listp shannonFanoList[ShannonFano_MAX]; //Contains Addresses of Symbols
listnode_t shannonFanoNodes[ShannonFano_MAX*3]; //Static Implementations
unsigned int sfn=0;

listnode_t *createNode(void)
{
    listnode_t *node;
    if(sfn>=(ShannonFano_MAX*3))
    {
        return NULL;
    }
    node=&shannonFanoNodes[sfn++]; //Taking a Symbol Node's Address
    node->frequency=(unsigned long)0; //Initial Frequency 0
    node->next=NULL;
    node->parent=NULL;
    node->firstChild=NULL;
    node->secondChild=NULL;
    node->ch=-1;
    return node; //Passing the address of Symbol Node's Address
}

//Inserting the Node into list
void insert(listnode_t **list,listnode_t *node)
{
    listnode_t *current;
    current=*list;
    //Sorting From Highest to Lowest
    while(current && node->frequency < current->frequency)
    {
        list=&current->next;
        current=current->next;
    }
    *list=node;
    node->next=current;
}

//Initializing shannonFanoList Function
void init_shannonFanoList(void)
{
    unsigned int i;
    for(i=0;i<ShannonFano_MAX;i++)
    {
        shannonFanoList[(unsigned char)i]=NULL;
    }
}

//Initializing shannonFanoFrequency Function
void init_shannonFanoFrequency(void)
{
    int i;
    for(i=0;i<ShannonFano_MAX;i++)
    {
        sffreq[i].f=(unsigned long)0; //Contains Frequencies
        sffreq[i].b=(unsigned char)i; //Contains Characters(Symbols{ASCII})
    }
}

//Creating the Initial Sorted Lists of Symbol
void createSymbolList(void)
{
    unsigned int i=0;
    listnode_t *node;
    shannonFanoCount=0;
    for(i=0;i<ShannonFano_MAX;i++)
    {
        if(sffreq[i].f>0)
        {
            node=createNode();
            if(node)
            {
                node->frequency=sffreq[i].f;
                node->ch=sffreq[i].b;
                insert(&list,node);
                shannonFanoList[node->ch]=node;
            }
            else
            {
                fprintf(stderr,"\nMemory Allocation Error!\n");
                exit(0);
            }
            shannonFanoCount++;//Counting the Count of Symbols
        }
    }
}

/*
Creating Shannon Fano Tree (Recursive Function) which
distributes node's set/list of symbol node to it's two
children nodes as known as firstChild and secondChild
*/
void createShannonFanoTree(listnode_t *node)
{
    listnode_t *d,*temp;
    //Creating Two Children Nodes
    //First Child
    node->firstChild=createNode();
    node->firstChild->parent=node;

    //Second Child
    node->secondChild=createNode();
    node->secondChild->parent=node;

    d=node->next;
    while(d)
    {
        temp=d->next;
        if(node->firstChild->frequency <= node->secondChild->frequency)
        {
            insert(&(node->firstChild->next),d);
            node->firstChild->frequency += d->frequency;
        }
        else
        {
            insert(&(node->secondChild->next),d);
            node->secondChild->frequency += d->frequency;
        }
        d=temp; //Starting next Nodes (Processing)
    }
    /*
    Using Recursion Method for two for two lists.
    If in child's list one node is stored then no recursion
    is used.Connecting with symbol node to parent node will be
    final approach.
    */
    //For firstChild
    if(node->firstChild->next)
    {
        if(node->firstChild->next->next)
        {
            createShannonFanoTree(node->firstChild);
        }
        else
        {
            node->firstChild->next->parent=node;
            node->firstChild=node->firstChild->next;
        }
    }

    //For secondChild
    if(node->secondChild->next)
    {
        if(node->secondChild->next->next)
        {
            createShannonFanoTree(node->secondChild);
        }
        else
        {
            node->secondChild->next->parent=node;
            node->secondChild=node->secondChild->next;
        }
    }
}

//Compression Method for ShannonFano using Recursive Process
void sfcompress(listnode_t *node)
{
    if(!node)
    {
        return;
    }
    if(node->parent)
    {
        sfcompress(node->parent);
        if(node->parent->firstChild==node)
        {
            put_ZERO();
        }
        else if(node->parent->secondChild==node)
        {
            put_ONE();
        }
    }
}

//Decompression Method for ShannonFano using Recursive Process
int sfdecompress(listnode_t *node)
{
    while(node->firstChild && node->secondChild)
    {
        if(get_bit())
        {
            node=node->secondChild;
        }
        else
        {
            node=node->firstChild;
        }
    }
    return node->ch;
}
