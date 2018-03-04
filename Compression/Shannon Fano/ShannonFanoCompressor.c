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

//Creating an Input Buffer for Faster I/O
#define IN_BUF_SIZE 4096
char inputBuffer[IN_BUF_SIZE];
uint nread=0,in_i=0;
FILE *in;

void readStats(FILE *in,shannonFanoFrequency_Type *sffreq);

int main(int argc,char *argv[])
{
    ulong inputFileLength,outputFileLength;
    int c=0;
    fileStamp fstamp;

    if(argc!=3)
    {
        fprintf(stderr,"Basic Shannon Fano Implementation");
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

    fprintf(stderr,"\nA Static Shannon Fano File Compressor");
    fprintf(stderr,"\nWriten by Anim");
    fprintf(stderr,"Name of the Output File: %s",argv[1]);

    //Displaying the Length of File
    fseek(in,0,SEEK_END);
    inputFileLength=ftell(in);
    fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);

    //Main Shannon Fano Implementaion

    //Initializing Array of ShannonFanoFrequency for reading Stats
    init_shannonFanoFrequency();

    //Getting Frequency counts of Symbols
    fprintf(stderr,"\n\nAnalyzing File....");
    readStats(in,sffreq);
    fprintf(stderr,"complete");

    //Compressing the File into Output File
     fprintf(stderr,"\nShannon Fano Compressing.....");

     //Initializing List Symbol
     init_shannonFanoList();
     createSymbolList();

     //Preparing the root of the Tree
     top=createNode();
     top->next=list;

     //Creating the whole Shannon Fano Tree
     createShannonFanoTree(top);

     //Encoding File Stamp
     rewind(pOUT);
     strcpy(fstamp.algo,"COMP");
     fstamp.fileSize=inputFileLength;
     fwrite(&fstamp,sizeof(fileStamp),1,pOUT);

     //Encoding the count of the Output File
     fwrite(&shannonFanoCount,sizeof(unsigned int),1,pOUT);

     //Encoding the Frequncy Table to the Output File
     for(c=0;c<ShannonFano_MAX;c++)
     {
         if(sffreq[c].f>0)
         {
             fwrite(&sffreq[c],sizeof(shannonFanoFrequency_Type),1,pOUT);
         }
     }

     //Encoding Symbol/Files bytes
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

         //Getting bytes From the Buffer and Compressing Them
         while(in_i<nread)
         {
            c=(uchar)*(inputBuffer+in_i);
            ++in_i;
            //Encoding the Bytes c
            sfcompress(shannonFanoList[c]);
         }
     }
     flush_putBuffer();
     fprintf(stderr,"Complete");

     //Getting Output File's Size and Compress Ratio
     outputFileLength=ftell(pOUT);
     fprintf(stderr,"\n\nName of The OutPut File: %s", argv[2]);
     fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);
     fprintf(stderr,"\nLength of Output File    =%15lu bytes",outputFileLength);
     fprintf(stderr,"\nCompression Ratio:        %15.2f%%\n",
             (((float)inputFileLength-(float)outputFileLength)/(float)inputFileLength)*(float)100);

     halt_prog:
     free_putBuffer();
     if(in)
     {
         fclose(in);
     }
     if(pOUT)
     {
         fclose(pOUT);
     }
     return 0;
}

void readStats(FILE *in,shannonFanoFrequency_Type *sffreq)
{
    int c;
    rewind(in);
    while((c=getc(in))!=EOF)
    {

        sffreq[c].f++;
    }
}
