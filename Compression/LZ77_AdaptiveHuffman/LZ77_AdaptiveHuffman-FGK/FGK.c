#include "AdaptiveHuffman.c"

huffmanNode_t *getHighestEqualLeafFGK(huffmanNode_t *node);
huffmanNode_t *getHighestEqualNodeFGK(huffmanNode_t *node);
void updateTreeFGK(int c);

huffmanNode_t *getHighestEqualLeafFGK(huffmanNode_t *node)
{
    huffmanNode_t *high=NULL;
    int i;
    for(i=node->number+1;i<rootNodeNumber;i++)
    {
        if(node->frequency==nodeAddress_Number[i]->frequency)
        {
            if(nodeAddress_Number[i]->ch != internalNode)
            {
                high=nodeAddress_Number[i];
            }
        }
        else
        {
            break;
        }
    }
    return high;
}

huffmanNode_t *getHighestEqualNodeFGK(huffmanNode_t *node)
{
    huffmanNode_t *high=NULL;
    int i;
    for(i=node->number+1;i<rootNodeNumber;i++)
    {
        if(node->frequency==nodeAddress_Number[i]->frequency)
        {
            high=nodeAddress_Number[i];
        }
        else
        {
            break;
        }
    }
    return high;
}

void updateTreeFGK(int c)
{
    huffmanNode_t *high=NULL;
    huffmanNode_t *node=huffmanList[c];
    if(node==NULL)
    {
        createNewZeroNode(c);
        node=huffmanList[c];
    }

    //Checking If a Sibling of Zero 0-Node
    if(node->parent==zeroNode->parent)
    {
        high=getHighestEqualLeafFGK(node);
        if(high)
        {
            swapNodes(node,high);
        }

        //Incrementing Node's Count
        node->frequency++;

        node=node->parent;
    }

    while(node!=top)
    {
        high=getHighestEqualNodeFGK(node);
        if(high)
        {
            swapNodes(node,high);
        }

        //Incrementing Node's Count
        node->frequency++;

        //Traversing To Top By Assigning Node Parent To Node
        node=node->parent;
    }
}
