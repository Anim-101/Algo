#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"uTypes.h"
#include"BitIO.c"
#include"ShannonFano.c"

typedef struct
{
    char algo[4];
    ulong fileSize;
}fileStamp;

FILE *out;
void copyRight(void);

int main(int argc,char *argv[])
{
    fileStamp fstamp;
    shannonFanoFrequency_Type frequency;
    int c=0;
    ulong inputFileSize=0;

    if(argc!=3)
    {
        fprintf(stderr,"\n Put input and output File's Name");
        copyRight();
        return 0;
    }

    if((gIN=fopen(argv[1],"rb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Input File");
    }
    fread(&fstamp,sizeof(fileStamp),1,gIN);

    if((out=fopen(argv[2],"wb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Output File");
        goto halt_prog;
    }

    //Initializing ShannonFannoFrequency Table
    init_shannonFanoFrequency();

    fread(&shannonFanoCount,sizeof(int),1,gIN);

    for(c=0;c<shannonFanoCount;c++)
    {
        fread(&frequency,sizeof(shannonFanoFrequency_Type),1,gIN);
        sffreq[(unsigned char)frequency.b]=frequency;
    }

    //Preparing the tree list of Symbols
    init_shannonFanoList();
    createSymbolList();

    top=createNode();
    top->next=list;

    //Creating Shannon Fano Tree
    createShannonFanoTree(top);

    init_getBuffer();
    fprintf(stderr,"\nName of Input File : %s",argv[1]);
    fprintf(stderr,"\nDecompressing...");

    rewind(out);
    for(inputFileSize=fstamp.fileSize;inputFileSize;inputFileSize--)
    {
        c=sfdecompress(top);
        putc((uchar)c,out);
    }

    fprintf(stderr,"Complete.\n");
    fprintf(stderr,"\nName of Outout File :%s\n",argv[2]);

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

void copyRight(void)
{
    fprintf(stderr,"\n\nWriten by Anim Akash");
}
