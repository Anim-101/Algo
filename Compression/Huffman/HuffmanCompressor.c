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

#define IN_BUF_SIZE 4096

char inputBuffer[IN_BUF_SIZE];
uint nread=0,in_i=0;

void readStats(FILE *in,huffmanFrequency_Type *hfreq);

int main(int argc,char *argv[])
{
    ulong inputFileLength,outputFileLength;
    int c=0;
    FILE *in;
    fileStamp fstamp;

    if(argc!=3)
    {
        fprintf(stderr,"Basic Huffman Implementation");
        fprintf(stderr,"\nCompressor for 256 Base");
        fprintf(stderr,"\nProvide Input File name and Out put File Name");
        return 0;
    }

    if((in=fopen(argv[1],"rb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Input File");
        return 0;
    }

    if((pOUT=fopen(argv[2],"wb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Output File");
        return 0;
    }

    init_putBuffer();

    fprintf(stderr,"\nA Static Huffman File Compressor");
    fprintf(stderr,"\nWriten by Anim");
    fprintf(stderr,"\nName of the Output File: %s",argv[1]);

    //Displaying File Length
    fseek(in,0,SEEK_END);
    inputFileLength=ftell(in);
    fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);

    //Main Huffman Implementation

    //Initializing hfreq[] Array for Reading Stats
    init_huffmanFrequency();

    //Getting Frequency Counts of Symbols
    fprintf(stderr,"\nAnalyzing File...");
    readStats(in,hfreq);
    fprintf(stderr,"\nComplete");

    //Start Compressing to Output File
    fprintf(stderr,"\nCompressing Using Huffman");

    //Creating Huffman Tree
    createHuffmanTree();

    //Ending File Stamp
    rewind(pOUT);
    strcpy(fstamp.algo,"HUF");
    fstamp.fileSize=inputFileLength;
    fwrite(&fstamp,sizeof(fileStamp),1,pOUT);

    //Encoding Count to Output File
    fwrite(&huffmanCount,sizeof(unsigned int),1,pOUT);

    //Encoding Frequency Table to Output File
    for(c=0;c<Huffman_MAX;c++)
    {
        if(hfreq[c].f>0)
        {
            fwrite(&hfreq[c],sizeof(huffmanFrequency_Type),1,pOUT);
        }
    }

    //Encoing the Symbols/File Bytes
    rewind(in);
    while(1)
    {
        //Loading Input Buffer
        nread=fread(inputBuffer,1,IN_BUF_SIZE,in);
        if(nread==0)
        {
            break;
        }
        in_i=0;

        //Getting bytes from Buffer and Compressing them
        while(in_i<nread)
        {
            c=(uchar)*(inputBuffer+in_i);
            ++in_i;
            hcompress(huffmanList[c]);
        }
    }

    //Flushing Output Buffer
    flush_putBuffer();
    fprintf(stderr,"\nComplete");

    //Getting Output File's Size and Compression Ratio
    outputFileLength=ftell(pOUT);
    fprintf(stderr,"\n\nName of The OutPut File: %s", argv[2]);
    fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);
    fprintf(stderr,"\nLength of Output File    =%15lu bytes",outputFileLength);
    fprintf(stderr,"\nCompression Ratio:        %15.2f%%\n",
        (((float)inputFileLength-(float)outputFileLength)/(float)inputFileLength)*(float)100);

    half_prog:

    free_putBuffer();
    if(in)
    {
        fclose(in);
    }
    if (pOUT)
    {
        fclose(pOUT);
    }

    return 0;
}

void readStats(FILE *in,huffmanFrequency_Type *hfreq)
{
    int c;
    rewind(in);
    while((c=getc(in))!=EOF)
    {
        hfreq[c].f++;
    }
}
