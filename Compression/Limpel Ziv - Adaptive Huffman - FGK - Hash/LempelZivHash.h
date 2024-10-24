#ifndef LEMPELZIVHASH_H_INCLUDED
#define LEMPELZIVHASH_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#define LempelZiv_NULL -1

extern int *lempelZivHash;
extern int *lempelZivPrevious;
extern int *lempelZivNext;

int allocate_lempelZivHash(int size);
void free_lempelZivHash(void);
void insert_lempelZivHashNode(int h,int i);
void delete_lempelZivHashNode(int h,int i);

#endif // LEMPELZIVHASH_H_INCLUDED
