#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BitIO.h"

FILE *gIN,*pOUT;
unsigned int pBUFSIZE=8192,gBUFSIZE=8192;
unsigned char *pbuf,*pbuf_start,p_cnt;
unsigned char *gbuf,*gbuf_start,*gbuf_end,g_cnt;
unsigned int pbuf_count,nfread;
unsigned int bit_read=0;

//Initializing Size of Buffer
void init_bufferSizes(unsigned int size)
{
   pBUFSIZE=size;
   gBUFSIZE=size;
}

//Initializing PutBuffer Function
void init_putBuffer()
{
    p_cnt=0;
    pbuf=NULL;
    pbuf_start=NULL;
    pbuf_count=0;

    //Allocating Memory for Buffers
    while(1)
    {
        pbuf=(unsigned char *) malloc(sizeof(char) * pBUFSIZE);
        if(pbuf)
        {
            pbuf_start=pbuf;
            break;
        }
        else
        {
            pBUFSIZE-=1024;
            if(pBUFSIZE==0)
            {
                fprintf(stderr,"\nMemory Allocation Error");
                exit(0);
            }
        }
    }
    memset(pbuf,0,pBUFSIZE);
}

//Initializing GetBuffer Function
void init_getBuffer(void)
{
    gbuf=NULL;
    gbuf_start=NULL;
    gbuf_end=NULL;
    g_cnt=0,nfread=0;

    //Allocating Memory for Buffers
    while(1)
    {
        gbuf=(unsigned char *) malloc(sizeof(char) * gBUFSIZE);
        if(gbuf)
        {
            gbuf_start=gbuf;
            break;
        }
        else
        {
            gBUFSIZE-=1024;
            if(gBUFSIZE==0)
            {
                fprintf(stderr,"\nMemory Allocation Error!");
                exit(0);
            }
        }
    }
    nfread=fread(gbuf,1,gBUFSIZE,gIN);
    gbuf_end=(unsigned char *) (gbuf+nfread);
}

void free_putBuffer(void)
{
    pbuf=pbuf_start;
    if(pbuf)
    {
        free(pbuf);
    }
}

void free_getBuffer(void)
{
    gbuf=gbuf_start;
    if(gbuf)
    {
        free(gbuf);
    }
}

void flush_putBuffer(void)
{
    if(pbuf_count || p_cnt)
    {
        fwrite(pbuf_start,pbuf_count+(p_cnt?1:0),1,pOUT);
        pbuf=pbuf_start;
        pbuf_count=0;
        p_cnt=0;
        memset(pbuf,0,pBUFSIZE);
    }
}

int get_bit(void)
{
    if(nfread)
    {
        if((*gbuf)&(1<<(g_cnt++)))
        {
            bit_read=1;
        }
        else
        {
            bit_read=0;
        }
        if(g_cnt==8)
        {
            g_cnt=0;
            if((++gbuf)==gbuf_end)
            {
                gbuf=gbuf_start;
                nfread=fread(gbuf,1,gBUFSIZE,gIN);
                gbuf_end=(unsigned char *) (gbuf+nfread);
            }
        }
    }
    else
    {
        return EOF;
    }
    return bit_read;
}
