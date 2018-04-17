#include"AdaptiveHuffman.c"

void updateTreeVitterEncoding(int c);
void updateTreeVitterDecoding(int c);
huffmanNode_t *getBlockLeaderVitter(huffmanNode_t *node);
void slideNodeVitterEncoding(huffmanNode_t *node);
void slideIncrementVitterEncoding(huffmanNode_t **node);
void slideNodeVitterDecoding(huffmanNode_t *node);
void slideIncrementVitterDecoding(huffmanNode_t **node);

//Function Returns the Leader of the Block
huffmanNode_t *getBlockLeaderVitter(huffmanNode_t *node)
{
    huffmanNode_t *high=NULL;
    int i;

    for(i=node->number+1;i<rootNodeNumber;i++)
    {
        if(node->frequency==nodeAddress_Number[i]->frequency)
        {
            if(nodeAddress_Number[i]!=node->parent)
              {
                    if(!(node->ch > internalNode && nodeAddress_Number[i]->ch==internalNode))
                    {
                        high=nodeAddress_Number[i];
                    }
              }
              else
                {
                    break;
                }
        }
        else
        {
            break;
        }
    }
    return high;
}

//For Encoding -> Old Technique

void slideNodeVitterEncoding(huffmanNode_t *node)
{
    unsigned long nodeFrequency;
    int i;
    if(node->ch==internalNode)
    {
        nodeFrequency=node->frequency+1;
    }
    else
    {
        nodeFrequency=node->frequency;
    }

    for(i=node->number+1;i<rootNodeNumber;i++)
    {
        if(nodeFrequency >= nodeAddress_Number[i]->frequency)
        {
            if(nodeAddress_Number[i] != node->parent)
            {
                if(node->ch==internalNode && nodeAddress_Number[i]->ch==internalNode && nodeFrequency==nodeAddress_Number[i]->frequency)
                {
                    break;
                }
                else
                {
                    swapNodes(node,nodeAddress_Number[i]);
                }
            }
        }
        else
        {
            break;
        }
    }
}

void slideIncrementVitterEncoding(huffmanNode_t **node)
{
    huffmanNode_t *temp;
    temp=(*node)->parent;
    slideNodeVitterEncoding(*node);

    (*node)->frequency++;

    if((*node)->ch > internalNode)
    {
        *node=(*node)->parent;
    }
    else
    {
        *node=temp;
    }
}

void updateTreeVitterEncoding(int c)
{
    huffmanNode_t *blockLeader=NULL;
    huffmanNode_t *increament=NULL;
    huffmanNode_t *node=huffmanList[c];

    if(node==NULL)
    {
        createNewZeroNode(c);
        node=zeroNode->parent;
        increament=node->secondChild;
    }
    else
    {
        blockLeader=getBlockLeaderVitter(node);
        if(blockLeader)
        {
            swapNodes(node,blockLeader);
        }
        if(node->parent==zeroNode->parent)
        {
            increament=node;
            node=node->parent;
        }
    }

    while(node!=top)
    {
        slideIncrementVitterEncoding(&node);
    }

    if(increament!=NULL)
    {
        slideIncrementVitterEncoding(&increament);
    }
}

//For Decoding -> New Updated Technique
void slideNodeVitterDecoding(huffmanNode_t *node)
{
    int i;

    for(i=node->number+1;i<rootNodeNumber;i++)
    {
        if(node->frequency == nodeAddress_Number[i]->frequency)
        {
            if(nodeAddress_Number[i] != node->parent)
            {
                swapNodes(node,nodeAddress_Number[i]);
            }
        }
        else
        {
            break;
        }
    }
}

//Updated SlideIncremeantVitter Than Previous Version
void slideIncrementVitterDecoding(huffmanNode_t **node)
{
    huffmanNode_t *temp;
    slideNodeVitterDecoding(*node);

    (*node)->frequency++;

    if((*node)->ch == internalNode)
    {
        temp=(*node)->parent;
        slideNodeVitterDecoding(*node);
    }

    if((*node)->ch > internalNode)
    {
        *node=(*node)->parent;
    }
    else
    {
        *node=temp;
    }
}

void updateTreeVitterDecoding(int c)
{
    huffmanNode_t *blockLeader=NULL;
    huffmanNode_t *increament=NULL;
    huffmanNode_t *node=huffmanList[c];

    if(node==NULL)
    {
        createNewZeroNode(c);
        node=zeroNode->parent;
        increament=node->secondChild;
    }
    else
    {
        blockLeader=getBlockLeaderVitter(node);
        if(blockLeader)
        {
            swapNodes(node,blockLeader);
        }
        if(node->parent==zeroNode->parent)
        {
            increament=node;
            node=node->parent;
        }
    }

    while(node!=top)
    {
        slideIncrementVitterDecoding(&node);
    }

    if(increament!=NULL)
    {
        slideIncrementVitterDecoding(&increament);
    }
}

