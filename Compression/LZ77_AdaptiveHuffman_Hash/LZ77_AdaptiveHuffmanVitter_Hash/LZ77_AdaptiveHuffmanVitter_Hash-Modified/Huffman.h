#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Huffman_MAX 256

typedef struct listnode *listp;
typedef struct listnode
{
    int number;
    listp next;
    unsigned long frequency;
    signed int ch;
    listp parent,firstChild,secondChild;
}listnode_t;

typedef struct
{
    unsigned char b;
    unsigned long f;
}huffmanFrequency_Type;

extern unsigned int huffmanCount;
extern huffmanFrequency_Type hfreq[];

extern listnode_t *list,*top,*listHead;
/*
 list (Current) Pointer
top is top of the Huffman tree
listHead is pointer to point list
*/

extern listnode_t huffmanNodes[];
extern unsigned int hn;
extern int hmin;
extern unsigned hmax_symbols;
extern unsigned int huffmanSymbol_bitSize;

listnode_t *createNode(void);
void insert(listnode_t *node);
void init_huffmanList(void);
void init_huffmanFrequency(void);
void createSymbolList(void);
listnode_t *getLeastNode(void);
void createHuffmanTree(void);
void hcompress(listnode_t *node);
int hdecompress(listnode_t *node);

#endif // HUFFMAN_H_INCLUDED
