#include"Vitter.c"

void adaptiveHuffman_initFirstNode(int c);
void adaptiveHuffman_encodeSymbol(int c);
int adaptiveHuffman_decodeSymbol(void);

void adaptiveHuffman_encodeSymbol(int c)
{
    //Encoding the Byte
    if(huffmanList[c])
    {
        hcompress(huffmanList[c]);
    }
    else
    {
        hcompress(zeroNode);
        put_nbits(c,huffmanSymbol_bitSize);
    }
    updateTreeVitter(c);
}

int adaptiveHuffman_decodeSymbol(void)
{
    int c;
    c=hdecompress(top);
    if(c==zeroNodeSymbol)
    {
        c=get_nbits(huffmanSymbol_bitSize);
    }
    //Updating Huffman Tree Vitter
    updateTreeVitter(c);
    return c;
}

void adaptiveHuffman_initFirstNode(int c)
{
    init_huffmanList();

    top=zeroNode=createNode();

    assignedNumber=rootNodeNumber;

    //Updating The Adaptive Huffman Tree Vitter
    updateTreeVitter(c);
}
