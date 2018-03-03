#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BitIO.h"

FILE *gIN,*pOUT;
unsigned int pBUFSIZE=8192,gBUFSIZE=8192;
unsigned char *pbuf,*pbuf_start,p_cnt;
unsigned char *gbuf,*gbuf_start,*gbuf_end,g_cnt;
unsigned int pbuf_count,nfread;
unsigned int bit_read=0,nbits_read=0;
unsigned long nbytes_out;

//Initializing Size of Buffer
void init_bufferSizes(unsigned int size)
{
   pBUFSIZE=gBUFSIZE=size;
}

//Initializing PutBuffer Function
void init_putBuffer()
{
    p_cnt=0;
    pbuf=NULL;
    pbuf_start=NULL;
    pbuf_count=0;
    nbytes_out=0;

    //Allocating Memory for Buffers
    while(1)
    {
        pbuf=(unsigned char *)malloc(sizeof(char)*pBUFSIZE);
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
        gbuf=(unsigned char *)malloc(sizeof(char)*gBUFSIZE);
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
    gbuf_end=(unsigned char *)(gbuf+nfread);
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
        nbytes_out=0;
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
                gbuf_end=(unsigned char *)(gbuf+nfread);
            }
        }
    }
    else return EOF;
    return bit_read;
}

//Getting a Byte from Input Buffer
int gfgetc(void)
{
    int c;
    if(nfread)
    {
        c=(int)(*gbuf++);
        if(gbuf==gbuf_end)
        {
            gbuf=gbuf_start;
            nfread=fread(gbuf,1,gBUFSIZE,gIN);
            gbuf_end=(unsigned char *)(gbuf+nfread);
        }
        return c;
    }
    else return EOF;
}

//Putting a Bytes into the Output Buffer
void pfputc(int c)
{
    *pbuf++=(unsigned char)c;
    if((++pbuf_count)==pBUFSIZE)
    {
        fwrite(pbuf_start,pBUFSIZE,1,pOUT);
        pbuf=pbuf_start;
        pbuf_count=0;
        nbytes_out+=pBUFSIZE;
        memset(pbuf,0,pBUFSIZE);
    }
}

/*
Multiple Bit Input and Output
Input more bits at a time
*/
unsigned int get_nbits(int size)
{
    unsigned int in_cnt=0,k=(*gbuf)>>g_cnt;
    if(size>=(8-g_cnt))
    {
        size-=(8-g_cnt);
        in_cnt+=(8-g_cnt);
        g_cnt=0;
        if((++gbuf)==gbuf_end)
        {
            gbuf=gbuf_start;
            nfread=fread(gbuf,1,gBUFSIZE,gIN);
            gbuf_end=(unsigned char *) (gbuf+nfread);
        }
        if(size)
            do
            {
                k |= ((*gbuf)<<in_cnt);
                if(size>=8)
                {
                    size-=8;
                    in_cnt+=8;
                    if((++gbuf)==gbuf_end)
                    {
                        gbuf=gbuf_start;
                        nfread=fread(gbuf,1,gBUFSIZE,gIN);
                        gbuf_end=(unsigned char *)(gbuf+nfread);
                    }
                }
                else
                {
                    break;
                }
            }
            while(size);
    }
    g_cnt+=size;
    in_cnt+=size;
    return (k<<(INT_BIT-in_cnt))>>(INT_BIT-in_cnt);
}

//Output More bits at a time
void put_nbits(unsigned int k,int size)
{
    k=(k<<(INT_BIT-size))>>(INT_BIT-size);
    *pbuf |=(k<<(p_cnt));
    if(size>=(8-p_cnt))
    {
        size-=(8-p_cnt);
        k>>=(8-p_cnt);
        p_cnt=0;
        if((++pbuf_count)==pBUFSIZE)
        {
            fwrite(pbuf_start,pBUFSIZE,1,pOUT);
            pbuf=pbuf_start;
            pbuf_count=0;
            nbytes_out+=pBUFSIZE;
            memset(pbuf,0,pBUFSIZE);
        }
        else
        {
            pbuf++;
        }
        if(size)
            do
            {
                *pbuf|=k;
                if(size>=8)
                {
                    size-=8;
                    k>>=8;
                    if((++pbuf_count)==pBUFSIZE)
                    {
                        fwrite(pbuf_start,pBUFSIZE,1,pOUT);
                        pbuf=pbuf_start;
                        pbuf_count=0;
                        nbytes_out+=pBUFSIZE;
                        memset(pbuf,0,pBUFSIZE);
                    }
                    else
                    {
                        pbuf++;
                    }
                }
                else
                {
                    break;
                }
            }
            while(size);
    }
    p_cnt+=size;
}

/*
Get a Symbol of Bit length=size
Same as get_nbits() method, with test on EOF
*/
int get_symbol(int size)
{
    unsigned int in_cnt=0,k=(*gbuf)>>g_cnt;
    if(nfread==0)
    {
        return EOF;
    }
    if(size>=(8-g_cnt))
    {
        size-=(8-g_cnt);
        in_cnt+=(8-g_cnt);
        g_cnt=0;
        if((++gbuf)==gbuf_end)
        {
            gbuf=gbuf_start;
            nfread=fread(gbuf,1,gBUFSIZE,gIN);
            gbuf_end=(unsigned char *)(gbuf+nfread);
            if(size>0&&nfread==0)
            {
                nbits_read=(k<<(INT_BIT-in_cnt))>>(INT_BIT-in_cnt);
                g_cnt=in_cnt;
                return EOF;
            }
        }
        if(size)
        do
        {
            k|=((*gbuf)<<in_cnt);
            if(size>=8)
            {
                size-=8;
                in_cnt+=8;
                if((++gbuf)==gbuf_end)
                {
                    gbuf=gbuf_start;
                    nfread=fread(gbuf,1,gBUFSIZE,gIN);
                    gbuf_end=(unsigned char *)(gbuf+nfread);
                    if(size>0&&nfread==0)
                    {
                        nbits_read=(k<<(INT_BIT-in_cnt))>>(INT_BIT-in_cnt);
                        g_cnt=in_cnt;
                        return EOF;
                    }
                }
            }
            else
            {
                break;
            }
        }
        while(size);
    }
    g_cnt+=size;
    in_cnt+=size;
    return (k<<(INT_BIT-in_cnt))>>(INT_BIT-in_cnt);
}

unsigned long get_nbytes_out(void)
{
    return (nbytes_out+pbuf_count);
}
