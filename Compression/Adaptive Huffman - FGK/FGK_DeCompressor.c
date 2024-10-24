#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"BitIO.c"
#include"FGK.c"
#include"uTypes.h"

typedef struct
{
    char algo[4];
    ulong fileSize;
}fileStamp;

int main(int argc,char *argv[])
{
    ulong inputFileLength=0,outputFileLength=0;
    FILE *out;
    fileStamp fstamp;

    if(argc!=3)
    {
        fprintf(stderr,"Basic Huffman Implementation");
        fprintf(stderr,"\nDeCompressor for 256 Base");
        fprintf(stderr,"\nProvide Input File name and Out put File Name");
        return 0;
    }

    if((gIN=fopen(argv[1],"rb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Input File");
        return 0;
    }

    if((out=fopen(argv[2],"wb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Output File");
        return 0;
    }

    fprintf(stderr,"\nA Basic Adaptive Huffman Based On FGK Algorithm File DeCompressor");
    fprintf(stderr,"\nWritten and Modified by Anim");
    fprintf(stderr,"\n\nName of the Input->Output File: %s",argv[1]);

    fseek(gIN,0,SEEK_END);
    inputFileLength=ftell(gIN);

    fprintf(stderr,"\n\nDecompressing...");

    clock_t begin=clock();

    rewind(gIN);

    fread(&fstamp,sizeof(fileStamp),1,gIN);

    init_huffmanList();

    huffmanCurrent=fgetc(gIN);

    outputFileLength=fstamp.fileSize-1;

    top=zeroNode=createNode();

    fputc((uchar)huffmanCurrent,out);

    //Re Traversing The Tree
    updateTreeFGK(huffmanCurrent);

    //Getting The Bit Stream
    init_getBuffer();

    while(outputFileLength--)
    {
        huffmanCurrent=hdecompress(top);

        if(huffmanCurrent==zeroNodeSymbol)
        {
            //Getting Raw Byte
            huffmanCurrent=get_nbits(8);
        }

        updateTreeFGK(huffmanCurrent);

        putc((uchar)huffmanCurrent,out);
    }

    outputFileLength=ftell(out);

    clock_t end=clock();
    double timeTook=(double)(end-begin)/CLOCKS_PER_SEC;

    fprintf(stderr,"\n\nComplete.");
    fprintf(stderr,"\n\nName of the Output File : %s",argv[2]);
    fprintf(stderr,"\n\nTime Took to DeCompress That File Using Adaptive Huffman Based On FGK Algorithm %lf Seconds\n",timeTook);

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
