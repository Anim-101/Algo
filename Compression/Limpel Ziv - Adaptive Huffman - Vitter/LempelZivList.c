#include<stdio.h>
#include<stdlib.h>
#include"LempelZivList.h"

//Table for ListHeads Which will be Indexed by 256 Characters
int lempelZivList[LempelZiv_Max_Symbol];

//Contains Previous and Next Pointers of Virtual Nodes
int lempelZivPrevious[LempelZiv_Max_BufferSize];
int lempelZivNext[LempelZiv_Max_BufferSize];

//Initializing LempelZivList Heads to -1
void init_lempelZivList(void)
{
    unsigned int i;
    for(i=0;i<LempelZiv_Max_Symbol;i++)
    {
        lempelZivList[i]=LempelZiv_NULL;
    }
}

//Inserting a Node
void insert_lempelZivNode(unsigned char c,int i)
{
    int k=lempelZivList[c];

    //Inserting at the Beginning
    lempelZivList[c]=i;
    lempelZivPrevious[i]=LempelZiv_NULL;
    lempelZivNext[i]=k;
    if(k!=LempelZiv_NULL)
    {
        lempelZivPrevious[k]=i;
    }
}

//Deleting a LempelZiv Node
void delete_lempelZivNode(unsigned char c,int i)
{
    if(lempelZivList[c]==i)
    {
        lempelZivList[c]=lempelZivNext[i];
        if(lempelZivList[c]!=LempelZiv_NULL)
        {
            lempelZivPrevious[lempelZivList[c]]=LempelZiv_NULL;
        }
    }
    else
    {
        lempelZivNext[lempelZivPrevious[i]]=lempelZivNext[i];
        if(lempelZivNext[i]!=LempelZiv_NULL)
        {
            lempelZivPrevious[lempelZivNext[i]]=lempelZivPrevious[i];
        }
    }
}
