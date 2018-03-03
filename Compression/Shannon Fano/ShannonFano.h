#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef SHANNONFANO_H_INCLUDED
#define SHANNONFANO_H_INCLUDED
#define ShannonFano_MAX 256

typedef struct listnode *listp;
typedef struct listnode
{
    listp next;
    unsigned long frequency;
    signed int ch;
    listp parent,firstChild,secondChild;
}listnode_t;

typedef struct
{
    unsigned char b;
    unsigned long f;
}shannonFanoFrequency_Type;

extern unsigned int shannonFanoCount;
extern shannonFanoFrequency_Type sffreq[];
extern listnode_t *list,*top;
extern listp shannonFanoList[];
extern listnode_t shannonFanoNodes[];
extern unsigned int sfn;

listnode_t *createNode(void);
void insert(listnode_t **list,listnode_t *node);
void init_shannonFanoList(void);
void init_shannonFanoFrequency(void);
void createSymbolList(void);
void createShannonFanoTree(listnode_t *node);
void sfcompress(listnode_t *node);
int sfdecompress(listnode_t *node);

#endif // SHANNONFANO_H_INCLUDED
