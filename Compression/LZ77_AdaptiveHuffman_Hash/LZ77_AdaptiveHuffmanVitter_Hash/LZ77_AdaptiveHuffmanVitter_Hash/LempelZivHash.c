#include<stdio.h>
#include<stdlib.h>
#include"LempelZivHash.h"

int *lempelZivHash=NULL;
int *lempelZivNext=NULL;
int *lempelZivPrevious=NULL;

//Allocating Memory to the Hash Table and Linked-List Tables
int allocate_lempelZivHash(int size)
{
    int i;

    lempelZivHash=(int*)malloc(sizeof(int)*size);

    if(!lempelZivHash)
    {
        fprintf(stderr,"\nError Allocating Hash Table");
        return(0);
    }

    lempelZivPrevious=(int*)malloc(sizeof(int)*size);

    if(!lempelZivPrevious)
    {
        fprintf(stderr,"\nError Allocating Hash (Previous) Table");
        return(0);

    }

    lempelZivNext=(int*)malloc(sizeof(int)*size);

    if(!lempelZivNext)
    {
        fprintf(stderr,"\nError Allocating Hash (Next) Table");
        return(0);

    }

    //initialing the ListHeads to LZ_NULL
    for(i=0;i<size;i++)
    {
        lempelZivHash[i]=LempelZiv_NULL;
    }

    return 1;
}

//Free Hash Table
void free_lempelZivHash(void)
{
    if(lempelZivHash)
    {
        free(lempelZivHash);
    }
    if(lempelZivPrevious)
    {
        free(lempelZivPrevious);
    }
    if(lempelZivNext)
    {
        free(lempelZivNext);
    }
}

void insert_lempelZivHashNode(int h,int i)
{
    int k=lempelZivHash[h];

    lempelZivHash[h]=i;
    lempelZivPrevious[i]=LempelZiv_NULL;
    lempelZivNext[i]=k;

    if(k!=LempelZiv_NULL)
    {
        lempelZivPrevious[k]=i;
    }
}

void delete_lempelZivHashNode(int h,int i)
{
    if(lempelZivHash[h]==i)
    {
        lempelZivHash[h]=lempelZivNext[i];
        if(lempelZivHash[h]!=LempelZiv_NULL)
        {
            lempelZivPrevious[lempelZivHash[h]]=LempelZiv_NULL;
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
