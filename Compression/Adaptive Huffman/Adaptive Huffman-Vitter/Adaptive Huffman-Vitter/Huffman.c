#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BitIO.h"
#include"Huffman.h"

unsigned int huffmanCount=0;
huffmanFrequency_Type hfreq[Huffman_MAX];

listnode_t *list=NULL,*top=NULL,*listHead=NULL;
listp huffmanList[Huffman_MAX];
listnode_t huffmanNodes[Huffman_MAX*2+1];
unsigned int hn=0;
unsigned hmax_symbols=Huffman_MAX;

listnode_t *createNode(void)
{
    listnode_t *node;
    if(hn>=(Huffman_MAX*2+1))
    {
        return NULL;
    }
    node=&huffmanNodes[hn++];
    node->number=0;
    node->frequency=(unsigned long)0;
    node->next=NULL;
    node->parent=NULL;
    node->firstChild=NULL;
    node->secondChild=NULL;
    node->ch=-1;
    return node;
}

void insert(listnode_t *node)
{
    listnode_t *current,*previous=NULL;
    current=list;
    if(list)
    {
        while(current&&node->frequency>current->frequency)
        {
            previous=current;
            current=current->next;
        }
        if(previous==NULL&&current)
        {
            list=node;
        }
        else
        {
            previous->next=node;
        }
        node->next=current;
    }
    else
    {
        if(listHead==NULL)
        {
            listHead=node;
        }
         list=node;
    }
}

void init_huffmanList(void)
{
    int i=0;
    for(;i<hmax_symbols;++i)
    {
        huffmanList[i]=NULL;
    }
}

void init_huffmanFrequency(void)
{
    int i=0;
    for(;i<hmax_symbols;++i)
    {
        hfreq[i].f=(unsigned long)0;
        hfreq[i].b=(unsigned char)i;
    }
}

void createSymbolList(void)
{
    unsigned int i=0;
    listnode_t *node;
    huffmanCount=0;
    for(;i<hmax_symbols;++i)
    {
        if(hfreq[i].f>0)
        {
            node=createNode();
            if(node)
            {
                node->frequency=hfreq[i].f;
                node->ch=hfreq[i].b;
                insert(node);
                huffmanList[node->ch]=node;
            }
            else
            {
                fprintf(stderr,"\nMemory Allocation Error\n");
                exit(0);
            }
            huffmanCount++;
        }
    }
}

listnode_t *getLeastNode(void)
{
    listnode_t *node;
    node=list;
    if(list)
    {
        list=list->next;
    }
    return node;
}

void createHuffmanTree(void)
{
    listnode_t *firstNode,*secondNode,*parent;
    init_huffmanList();
    createSymbolList();
    while(list)
    {
        firstNode=getLeastNode();
        if(list)
        {
            secondNode=getLeastNode();
            parent=createNode();
            firstNode->parent=parent;
            secondNode->parent=parent;
            parent->firstChild=firstNode;
            parent->secondChild=secondNode;
            parent->frequency=firstNode->frequency+secondNode->frequency;
            insert(parent);
        }
        else
        {
            top=firstNode;
            if(firstNode==listHead)
            {
                top=createNode();
                top->firstChild=firstNode;
                top->secondChild=firstNode;
                firstNode->parent=top;
            }
            break;
        }
    }
}

void hcompress(listnode_t *node)
{
    int bit_cnt=0;
    char bit[Huffman_MAX];
    if(!node)
    {
        return;
    }
    while(node->parent)
    {
        if(node==node->parent->firstChild)
        {
            bit[bit_cnt]=0;
        }
        else if(node==node->parent->secondChild)
        {
            bit[bit_cnt]=1;
        }
        bit_cnt++;
        node=node->parent;
    }
    while(bit_cnt--)
    {
        if(bit[bit_cnt])
        {
            put_ONE();
        }
        else
        {
            put_ZERO();
        }
    }
}

int hdecompress(listnode_t *node)
{
    while(node->firstChild&&node->secondChild)
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
