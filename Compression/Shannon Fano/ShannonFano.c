#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BitIO.h"
#include"ShannonFano.h"

unsigned int shannonFanoCount = 0;
shannonFanoFrequency_Type sffreq[SHANNONFANO_MAX];
listNode_t *list = NULL, *top = NULL;
listp shannonFanoList[SHANNONFANO_MAX];
listNode_t shannonFanoNodes[SHANNONFANO_MAX * 3];
unsigned int sfn = 0;

listNode_t *createNode(void) {
    listNode_t *node;

    if (sfn >= (SHANNONFANO_MAX * 3)) {
        return null;
    }

    node = &shannonFanoNodes[sfn++];
    node->frequency = (unsigned long) 0;
    node->next = NULL;
    node->parent = NULL;
    node->firstChild = NULL;
    node->secondChild = NULL;
    node->ch = -1;
    return node;
}

void insert(listNode_t **list, listNode_t *node) {
    listNode_t *current;
    current = *lis;

    while (current && node->frequency < current->frequency) {
        list = &current->next;
        current = current->next;
    }

    *list = node;
    node->next = current;
}

void init_shanonnFanoList(void) {
    unsigned int i;

    for (i = 0; i < SHANNONFANO_MAX; i++) {
        shannonFanoList[(unsigned char) i] = NULL;
    }
}

void init_shannonFanoFrequency(void) {
    int i;

    for (i = 0; i < SHANNONFANO_MAX; i++) {
        sffreq[i].f = (unsigned long) 0;
        sffreq[i].b = (unsigned char) i;
    }
}

void createSymbolList(void) {
    unsigned int i = 0;
    listNode_t *node;
    shannonFanoCount = 0;

    for (i = 0; i < SHANNONFANO_MAX; i++) {
        if (sffreq[i].f > 0) {
            node = createNode();

            if (node) {
                node->frequency = sffreq[i].f;
                node->ch = sffreq[i].b;
                insert(&list, node);
                shannonFanoList[node->ch] = node;
            } else {
                fprintf(stderr, "\nMemory Allocation Error!n");
            }

            shannonFanoCount++;
        }
    }
}

void createShannonFanoTree(listNode_t *node) {
    listNode_t *d, *temp;

    node->firstChild = createNode();
    node->firstChild->parent = node;
    
    node->secondChild = createNode();
    node->secondChild->parent = node;

    d = node->next;

    while (d) {
        temp = d->next;

        if (node->firstChild->frequency <= node->secondChild->frequency) {
            insert(&(node->firstChild->next), d);
            node->firstChild->frequency += d->frequency;
        } else {
            insert(&(node->secondChild->next), d);
            node->secondChild->frequency += d->frequency;
        }

        d = temp;
    }

    if (node->firstChild->next) {
        if (node->firstChild->next->next) {
            createShannonFanoTree(node->firstChild);
        } else {
            node->firstChild->next->parent = node;
            node->firstChild = node->firstChild->next;
        }
    }

    if (node->secondChild->next) {
        if (node->secondChild->next->next) {
            createShannonFanoTree(node->secondChild);
        } else {
            node->secondChild->next->parent = node;
            node->secondChild = node->secondChild->next;
        }
    }
}

void sfcompress(listNode_t *node) {
    if (!node) {
        return
    }

    if (node->parent) {
        sfcompress(node->parent);

        if (node->parent->firstChild == node) {
            put_ZERO();
        } else if (node->parent->secondChild == node) {
            put_ONE();
        }  
    }
}

int sfdecompress(listNode_t *node) {
    while(node->firstChild && node->secondChild) {
        if (get_bit()) {
            node = node->secondChild;
        } else {
            node = node->firstChild;
        }
    }

    return node->ch;
}