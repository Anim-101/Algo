#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"BitIO.c"
#include"Vitter.c"
#include"uTypes.h"

typedef struct
{
    char algo[4];
    ulong fileSize;
}fileStamp;

//Creating Input Buffer For Faster Input/Output Processes
#define inBuffSize 16384
uchar inputBuffer[inBuffSize];
uint nread=0,in_i=0;

int main (int argc,char *argv[])
{
    ulong inputFileLength,outputFileLength;
    FILE *in;
    fileStamp fstamp;

    if(argc!=3)
    {
        fprintf(stderr,"Basic Adaptive Huffman Implementation Based On Vitter's Algorithm");
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

    fprintf(stderr,"\nA Basic Adaptive Huffman Based On Vitter's Algorithm File Compressor");
    fprintf(stderr,"\nWritten and Modified by Anim");
    fprintf(stderr,"\nName of the Output File: %s",argv[1]);

    clock_t begin=clock();

    init_putBuffer();

    //Displaying File Length
    fseek(in,0,SEEK_END);
    inputFileLength=ftell(in);

    rewind(pOUT);
    strcpy(fstamp.algo,"VIT");
    fstamp.fileSize=inputFileLength;
    fwrite(&fstamp,sizeof(fileStamp),1,pOUT);

    //Starting Huffman Encoding The Symbols/File Bytes
    rewind(in);

    init_huffmanList();

    huffmanCurrent=fgetc(in);

    if(huffmanCurrent==EOF)
    {
        goto haltProg;
    }

    top=zeroNode=createNode();

    fputc((uchar)huffmanCurrent,pOUT);

    //Re Traversing The Tree
    updateTreeVitterEncoding(huffmanCurrent);

    while(1)
    {
        //Loading Input Buffer
        nread=fread(inputBuffer,1,inBuffSize,in);
        if(nread==0)
        {
            break;
        }
        in_i=0;

        while(in_i<nread)
        {
            huffmanCurrent=(uchar)*(inputBuffer+in_i);
            ++in_i;

            if(huffmanList[huffmanCurrent])
            {
                //Saving Output -> The Symbol's Code
                hcompress(huffmanList[huffmanCurrent]);
            }
            else
            {
                //Saving Output -> The Zero Node's Code
                hcompress(zeroNode);
                put_nbits(huffmanCurrent,8);
            }

            //Re Traversing The Tree For Update
            updateTreeVitterEncoding(huffmanCurrent);
        }
    }

    flush_putBuffer();
    clock_t end=clock();
    double timeTook=(double)(end-begin)/CLOCKS_PER_SEC;

    //Getting Output File's Size and Compression Ratio
    outputFileLength=ftell(pOUT);

    fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);
    fprintf(stderr,"\nLength of Output File    =%15lu bytes",outputFileLength);
    fprintf(stderr,"\nCompression Ratio:        %15.2f%%\n",
        (((float)inputFileLength-(float)outputFileLength)/(float)inputFileLength)*(float)100);
    fprintf(stderr,"\nTime Took to Compress That File Using Adaptive Huffman Based on Vitter's Algorithm %lf Seconds\n",timeTook);

    haltProg:

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
