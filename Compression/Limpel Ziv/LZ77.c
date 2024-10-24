#include<stdio.h>
#include<stdlib.h>
#include"LZ77.h"

//Table of ListHeads, Indexed by 256 characters
int lzList[lzMax];

/*
Contains Previous and Next pointers of virtual Nodes
*/
int lzPrevious[lzMaxBuffer];
int lzNext[lzMaxBuffer];

//Initializing ListHead to -1
void initLZList(void)
{
    unsigned int i;
    for(i=0;i<lzMax;i++)
    {
        lzList[i]=lzNull;
    }
}

void insertLZNode(unsigned char c,int i)
{
    int k=lzList[c];
    lzList[c]=i;
    lzPrevious[i]=lzNull;
    lzNext[i]=k;
    if(k!=lzNull)
    {
        lzPrevious[k]=i;
    }
}

void deleteLZNode(unsigned char c,int i)
{
    if(lzList[c]==i)
    {
        lzList[c]=lzNext[i];
        if(lzList[c]!=lzNull)
        {
            lzPrevious[lzList[c]]=lzNull;
        }
    }
    else
    {
        lzNext[lzPrevious[i]]=lzNext[i];
        if(lzNext[i]!=lzNull)
        {
            lzPrevious[lzNext[i]]=lzPrevious[i];
        }
    }
}
