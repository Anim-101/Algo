#include"Huffman.c"

#define zeroNodeSymbol -2
#define internalNode -1
#define rootNodeNumber (Huffman_MAX*2)

#define huffmanNode_t listnode_t

int huffmanCurrent; //Current Symbol
huffmanNode_t *zeroNode=NULL; //The 0 Node
/*
This Array Contains the node address as indexed
by their node numbers
*/
huffmanNode_t *nodeAddress_Number [Huffman_MAX*2+1];

int assignedNumber = rootNodeNumber;

void createNewZeroNode(int c)
{
    //Creating Children and Assigning Links
    zeroNode->firstChild=createNode();
    zeroNode->secondChild=createNode();

    zeroNode->firstChild->parent=zeroNode;
    zeroNode->secondChild->parent=zeroNode;

    //Reseting the Node's Internal Node by Assigning internalNode
    zeroNode->ch=internalNode;

    //New Symbol's Node is secondChild or "Right"
    huffmanList[c]=zeroNode->secondChild;
    huffmanList[c]->ch=c;

    //Numbering the Nodes
    zeroNode->number=assignedNumber--;
    huffmanList[c]->number=assignedNumber--;

    //Storing These in the Hash Array
    nodeAddress_Number[zeroNode->number]=zeroNode;
    nodeAddress_Number[huffmanList[c]->number]=huffmanList[c];

    //New Zero Node is firstChild or "Left"
    zeroNode = zeroNode->firstChild;
    zeroNode->ch=zeroNodeSymbol;
}

//Changing Two Nodes Based On Their References
void swapNodes(huffmanNode_t *aNode,huffmanNode_t *bNode)
{
    huffmanNode_t *par,*temp=NULL;
    int i=0;

    if(aNode->parent==bNode->parent)
    {
        par=aNode->parent;
        if(par->firstChild==aNode)
        {
            par->firstChild=bNode;
            par->secondChild=aNode;
        }
        else
        {
            par->firstChild=aNode;
            par->secondChild=bNode;
        }
        goto numbersHultVal;
    }

    if(aNode->parent->firstChild==aNode)
    {

        aNode->parent->firstChild=bNode;
    }
    else
    {

        aNode->parent->secondChild=bNode;
    }

    if(bNode->parent->firstChild==bNode)
    {
        bNode->parent->firstChild=aNode;
    }
    else
    {
        bNode->parent->secondChild=aNode;
    }

    par=aNode->parent;
    aNode->parent=bNode->parent;
    bNode->parent=par;

    numbersHultVal:

    //Swapping Nodes in nodeAddress_Number [] Hash and their Numbers
    temp=nodeAddress_Number[aNode->number];
    nodeAddress_Number[aNode->number]=nodeAddress_Number[bNode->number];
    nodeAddress_Number[bNode->number]=temp;

    i=aNode->number;
    aNode->number=bNode->number;
    bNode->number=i;
}
