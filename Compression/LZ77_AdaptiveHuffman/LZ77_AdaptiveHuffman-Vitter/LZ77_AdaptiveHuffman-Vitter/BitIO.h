#ifndef BITIO_H_INCLUDED
#define BITIO_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#if !defined(INT_BIT)
    #if INT_MAX==0x7fff
        #define INT_BIT 16
    #elif INT_MAX==0x7fffffff
        #define INT_BIT 32
    #else
        #define INT_BIT(8*sizeof(int))
    #endif
#endif

#define pset_bit() *pbuf |=(1<<p_cnt)

//Writes a One(1) bit
#define put_ONE() {pset_bit(); advance_buf();}

//Writes a Zero(0) bit
#define put_ZERO() advance_buf()

//Increamenting pbuf buffer through advance_buf() function
#define advance_buf()\
{\
    if((++p_cnt)==8)\
    {\
        p_cnt=0;\
        if((++pbuf_count)==pBUFSIZE)\
        {\
            pbuf=pbuf_start;\
            fwrite(pbuf,pBUFSIZE,1,pOUT);\
            memset(pbuf,0,pBUFSIZE);\
            pbuf_count=0;\
        }\
        else pbuf++;\
    }\
}

extern FILE *gIN,*pOUT;
extern unsigned int pBUFSIZE,gBUFSIZE;
extern unsigned char *pbuf,*pbuf_start,p_cnt;
extern unsigned char *gbuf,*gbuf_start,*gbuf_end,g_cnt;
extern unsigned int pbuf_count,nfread;
extern unsigned int bit_read;

void init_bufferSizes(unsigned int size);
void init_putBuffer(void);
void init_getBuffer(void);
void free_putBuffer(void);
void free_getBuffer(void);
void flush_putBuffer(void);
int get_bit(void);
int gfgetc(void);
unsigned int get_nbits(int size);
void put_nbits(unsigned int k,int size);

#endif // BITIO_H_INCLUDED
