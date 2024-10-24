#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"uTypes.h"
#include"BitIO.c"
#include"LZ77.c"

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
uint win_cnt=0,pat_cnt=0,buf_cnt=0;

pos_t search(uchar w[],uchar p[]);
void putCodes(pos_t *pos);

int main(int argc,char *argv[])
{
    unsigned long inputFileLength=0,outputFileLength=0;
    unsigned int i;
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

    if((pOUT=fopen(argv[2],"wb"))==NULL)
    {
        fprintf(stderr,"\nError Opening Output File");
        return 0;
    }

    init_putBuffer();

    fprintf(stderr,"\nA Lempel Ziv 77 Compressor");
    fprintf(stderr,"\nWriten by Anim");
    fprintf(stderr,"\nName of the Output File: %s",argv[1]);

    //Displaying File Length
    fseek(gIN,0,SEEK_END);
    inputFileLength=ftell(gIN);
    fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);

    rewind(pOUT);
    strcpy(fstamp.algo,"LZ77");
    fstamp.fileSize=inputFileLength;
    fwrite(&fstamp,sizeof(fileStamp),1,pOUT);

    //Start Compressing to Output File
    fprintf(stderr,"\nCompressing Using Lempel Ziv 77");

    //Initializing The Table of Pointers
    initLZList();

    //Initializing The Sliding Window
    memset(winBuf,32,WIN_BUFFSIZE);

    //Initializing The Search List
    for(i=0;i<WIN_BUFFSIZE;i++)
    {
        lzPrevious[i]=-1;
        lzNext[i]=-1;
        insertLZNode(winBuf[i],i);
    }

    rewind(gIN);

    //Filling The Pattern Buffer
    buf_cnt=fread(pattern,1,PAT_BUFFSIZE,gIN);

    //Initialing The Input Buffer
    init_getBuffer();

    //Compressing File
    while(buf_cnt>0)
    {
        pos=search(winBuf,pattern);
        putCodes(&pos);
    }

    flush_putBuffer();
    fprintf(stderr,"Complete....");

    //Getting Output File's Size and Compression Ratio
    outputFileLength=ftell(pOUT);
    fprintf(stderr,"\n\nName of The OutPut File: %s", argv[2]);
    fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);
    fprintf(stderr,"\nLength of Output File    =%15lu bytes",outputFileLength);
    fprintf(stderr,"\nCompression Ratio:        %15.2f%%\n",
        (((float)inputFileLength-(float)outputFileLength)/(float)inputFileLength)*(float)100);

    half_prog:

    free_putBuffer();
    free_getBuffer();
    if(gIN)
    {
        fclose(gIN);
    }
    if (pOUT)
    {
        fclose(pOUT);
    }

    return 0;
}

pos_t search(uchar w[],uchar p[])
{
    register int i,j,k;
    pos_t pos={0,1};

    //Starting LZLIST
    i=lzList[(uchar)p[pat_cnt]];
    if(buf_cnt>1)
    {
        while(i!=-1)
        {
            if((j=pat_cnt+1)==PAT_BUFFSIZE)
            {
                j=0;
            }
            k=1;
            do
            {
                if(p[j]!=w[(i+k)&WIN_MASK])
                {
                    break;
                }
                if((++j)==PAT_BUFFSIZE)
                {
                    j=0;
                }
            }
            while((++k)<buf_cnt);

            if(k>pos.length)
            {
                pos.position=i;
                pos.length=k;
                if(k==buf_cnt)
                {
                    break;
                }
            }
            i=lzNext[i];
         }
    }
    if(pos.length>=MIN_MATCH_LEN)
    {
        buf_cnt-=pos.length;
    }
    else
    {
        buf_cnt-=1;
    }
    return pos;
}

void putCodes(pos_t *pos)
{
    int i,j,k;
    if(pos->length < MIN_MATCH_LEN)
    {
        pos->length=1;
        put_ONE();
    }
    else
    {
        put_ZERO();
        k=pos->length;
        k-=MIN_MATCH_LEN;
        put_nbits(k,NUM_LEN_BITS);
    }

    //Encoding Position For Match
    if(pos->length>=MIN_MATCH_LEN)
    {
        k=(unsigned int)pos->position;
        put_nbits(k,NUM_POS_BITS);
    }
    else if(pos->length==1)
    {
        k=(unsigned char)pattern[pat_cnt];
        put_nbits(k,8);
    }
    j=win_cnt;
    for(i=0;i<(pos->length);i++,j++)
    {
        deleteLZNode(*(winBuf+(j&WIN_MASK)),j&WIN_MASK);
        *(winBuf+(j&WIN_MASK))=*(pattern+((pat_cnt+i)%PAT_BUFFSIZE));
        insertLZNode(*(winBuf+(j&WIN_MASK)),j&WIN_MASK);
    }
    for(i=0;i<(pos->length);i++)
    {
        if((k=gfgetc())!=EOF)
        {
            *(pattern+((pat_cnt+i)%PAT_BUFFSIZE))=(uchar)k;
        }
        else
        {
            break;
        }
    }
    buf_cnt+=i;
    win_cnt=(win_cnt+pos->length)&WIN_MASK;
    if((pat_cnt=(pat_cnt+pos->length))>=PAT_BUFFSIZE)
    {
        pat_cnt-=PAT_BUFFSIZE;
    }
}
