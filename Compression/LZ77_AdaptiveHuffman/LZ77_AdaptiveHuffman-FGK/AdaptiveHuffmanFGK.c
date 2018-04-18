#include"FGK.c"

void adaptiveHuffman_initFirstNode(int c);
void adaptiveHuffman_encodeSymbol(int c);
int adaptiveHuffman_decodeSymbol(void);

void adaptiveHuffman_initFirstNode(int c)
{
    init_huffmanList();

    top=zeroNode=createNode();

    //Reseting
    assignedNumber=rootNodeNumber;

    //Updating The Huffman Tree
    updateTreeFGK(c);
}

void adaptiveHuffman_encodeSymbol(int c)
{
    if(huffmanList[c])
    {
        hcompress(huffmanList[c]);
    }
    else
    {
        hcompress(zeroNode);
        put_nbits(c,huffmanSymbol_bitSize);
    }
    updateTreeFGK(c);
}

int adaptiveHuffman_decodeSymbol(void)
{
    int c;
    c=hdecompress(top);
    if(c==zeroNodeSymbol)
    {
        c=get_nbits(huffmanSymbol_bitSize);
    }
    updateTreeFGK(c);

    return c;
}
