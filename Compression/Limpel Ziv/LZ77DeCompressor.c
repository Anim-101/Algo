#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"uTypes.h"
#include"BitIO.c"

typedef struct
{
    char algo[4];
    ulong fileSize;
}fileStamp;

typedef struct
{
    uint position,length;
}pos_t;

#define WIN_BUFFSIZE    4096
#define NUM_POS_BITS    12
#define WIN_MASK        4095
#define PAT_BUFFSIZE    18
#define NUM_LEN_BITS    4
#define MIN_MATCH_LEN   3

pos_t pos;
uchar winBuf[WIN_BUFFSIZE];
uchar pattern[PAT_BUFFSIZE];
uint win_cnt=0;

int main(int argc,char *argv[])
{
    unsigned long fsize=0;
    uint i,k;
    FILE *out;
    fileStamp fstamp;

    if(argc!=3)
    {
        fprintf(stderr,"Basic Lempel Ziv 77 Implementation");
        fprintf(stderr,"\nCompressor for 256 Base");
        fprintf(stderr,"\nProvide Input File name and Out put File Name");
        return 0;
    }

    if((gIN=fopen(argv[1],"rb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Input File");
        return 0;
    }

    fread(&fstamp,sizeof(fileStamp),1,gIN);
    init_getBuffer();

    if((out=fopen(argv[2],"wb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Output File");
        return 0;
    }

     fprintf(stderr,"\nName of Input File : %s",argv[1]);
     fprintf(stderr,"\nDecompressing...");

     memset(winBuf,32,WIN_BUFFSIZE);

     fsize=fstamp.fileSize;
     while(fsize)
     {
         switch(get_bit())
         {
         case 0:
            pos.length=get_nbits(NUM_LEN_BITS);
            pos.position=get_nbits(NUM_POS_BITS);
            pos.length+=MIN_MATCH_LEN;
            i=pos.length;
            while(i--)
            {
                pattern[i]=winBuf[(pos.position+i)&WIN_MASK];
            }
            i=pos.length;
            while(i--)
            {
                winBuf[(win_cnt+i)&WIN_MASK]=pattern[i];
            }
            fwrite(pattern,pos.length,1,out);
            fsize-=pos.length;
            win_cnt=(win_cnt+pos.length)&WIN_MASK;
            break;

         case 1:
            k=get_nbits(8);
            fputc((unsigned char)k,out);
            winBuf[win_cnt]=(unsigned char)k;
            if((++win_cnt)==WIN_BUFFSIZE)
            {
                win_cnt=0;
            }
            fsize--;
            break;
         }
     }

     fprintf(stderr,"\nComplete.");
     fprintf(stderr,"\nName of the Output File : %s",argv[2]);

halt_prog:

    free_getBuffer();
    if(gIN)
    {
        fclose(gIN);
    }
    if(out)
    {
        fclose(out);
    }
    return 0;
}
