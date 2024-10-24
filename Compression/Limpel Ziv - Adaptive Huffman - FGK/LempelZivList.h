#ifndef LEMPELZIVLIST_H_INCLUDED
#define LEMPELZIVLIST_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#define LempelZiv_NULL -1
#define LempelZiv_Max_Symbol 256
#define LempelZiv_Max_BufferSize 8192

extern int lempelZivPrevious[];
extern int lempelZivNext[];

//Table of ListHeads, Will be Indexed by 256 Characters
extern int lempelZivList[];

void init_lempelZivList(void);
void insert_lempelZivNode(unsigned char c,int i);
void delete_lempelZivNode(unsigned char c,int i);

#endif // LEMPELZIVLIST_H_INCLUDED
