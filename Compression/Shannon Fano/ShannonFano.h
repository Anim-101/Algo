#ifndef SHANNONFANO_H_INCLUDED
#define SHANNONFANO_H_INCLUDED
#define SHANNONFANO_MAX 256

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listNode *listp;

typedef struct listNode {
    listp next;
    unsigned long frequency;
    signed int ch;
    listp parent, firstChild, secondChild;
} listNode_t;

typedef struct {
    unsigned char b;
    unsigned long f;
} shannonFanoFrequency_Type;

extern unsigned int shannonFanoCount;
extern shannonFanoFrequency_Type sffreq[];
extern listNode_t *list, *top;
extern listp shannonFanoList[];
extern listNode_t shannonFanoNodes[];
extern unsigned int sfn;

listNode_t *createNode(void);
void insert(listNode_t **list, listNode_t *node);
void init_shannonFanoList(void);
void init_shannonFanoFrequency(void);
void createSymbolList(void);
void createShannonFanoTree(listNode_t *node);
void sfcompress(listNode_t *node);
void sfdecompress(listNode_t *node);

#endif