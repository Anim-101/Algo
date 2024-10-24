#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"uTypes.h"
#include"BitIO.c"
#include"Huffman.c"

typedef struct
{
    char algo[4];
    ulong fileSize;
}fileStamp;

FILE *out;

int main(int argc,char *argv[])
{
    fileStamp fstamp;
    huffmanFrequency_Type frequen;
    int c=0;
    ulong inputFileLength=0;

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

    fread(&fstamp,sizeof(fileStamp),1,gIN);

    if((out=fopen(argv[2],"wb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Output File");
        return 0;
    }

    //Starting Decompressing Processes
    //Initializing Huffman Frequency
    init_huffmanFrequency();

    //Reading the Number of Symbol from File
    fread(&huffmanCount,sizeof(int),1,gIN);

    //Reading the Symbols from File
    for(c=0;c<huffmanCount;c++)
    {
        fread(&frequen,sizeof(huffmanFrequency_Type),1,gIN);
        hfreq[(unsigned char) frequen.b]=frequen;
    }

    //Creating Huffman Tree
    createHuffmanTree();

    //Getting Buffer
    init_getBuffer();

    fprintf(stderr,"\nName of Input File : %s",argv[1]);
    fprintf(stderr,"\nDecompressing...");

    //Decompression Step
    for(inputFileLength=fstamp.fileSize;inputFileLength;inputFileLength--)
    {
        c=hdecompress(top);
        putc((uchar)c,out);
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
