#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"BitIO.c"
#include"uTypes.h"
#include"LempelZivList.c"
#include"AdaptiveHuffmanVitter.c"

#define WIN_BUFFSIZE 4096
#define NUM_POS_BITS 12
#define WIN_MASK 4095
#define PAT_BUFFSIZE 18
#define NUM_LEN_BITS 4

typedef struct
{
    char algo[4];
    ulong fileSize;
}fileStamp;

typedef struct
{
    uint position,length;
}pos_t;

pos_t pos;
uchar winBuf[WIN_BUFFSIZE];
uchar pattern[PAT_BUFFSIZE];
uint win_cnt=0,pat_cnt=0,buf_cnt=0;

pos_t search(uchar w[],uchar p[]);
void putCodes(pos_t *pos);

int main(int argc,char *argv[])
{
    ulong inputFileLength=0,outputFileLength=0;
    uint i;
    fileStamp fstamp;

    if(argc!=3)
    {
        fprintf(stderr,"Basic Lempel Ziv 77 And Adaptive Huffman Based on Vitter Algorithm's Implementation");
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

    fprintf(stderr,"\nA Lempel Ziv 77 and Adaptive Huffman Vitter Algorithm's Compressor");
    fprintf(stderr,"\nWriten and Modified by Anim");
    fprintf(stderr,"\nWindow Buffer Size    : %151lu bytes",(ulong)WIN_BUFFSIZE);
    fprintf(stderr,"\nLook Ahead Buffer Size: %151lu bytes",(ulong)PAT_BUFFSIZE);
    fprintf(stderr,"\nName of the Input File: %s",argv[1]);

    clock_t begin=clock();

    init_bufferSizes(2048);
    init_putBuffer();

    //Displaying File Length
    fseek(gIN,0,SEEK_END);
    inputFileLength=ftell(gIN);
    fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);

    rewind(pOUT);
    strcpy(fstamp.algo,"DEF");
    fstamp.fileSize=inputFileLength;
    fwrite(&fstamp,sizeof(fileStamp),1,pOUT);

    //Start Compressing to Output File
    fprintf(stderr,"\nCompressing Using Lempel Ziv 77 and Adaptive Huffman Based on Vitter Algorithm");

    //Initializing the Table of Pointers
    init_lempelZivList();

    //Setting the Slide Window to All Zero (0) Values
    memset(winBuf,0,WIN_BUFFSIZE);

    //Initializing The Search List
    for(i=0;i<WIN_BUFFSIZE;i++)
    {
        lempelZivPrevious[i]=-1;
        lempelZivNext[i]=-1;
        insert_lempelZivNode(winBuf[i],i);
    }

    //Rewinding Input File
    rewind(gIN);

    //Filling Pattern Buffer
    buf_cnt=fread(pattern,1,PAT_BUFFSIZE,gIN);

    //Initializing Input Buffer
    init_getBuffer();

    //Adaptive Huffman Initializations
    hmax_symbols=PAT_BUFFSIZE-2;
    huffmanSymbol_bitSize=NUM_LEN_BITS;
    hmin=0;
    adaptiveHuffman_initFirstNode(hmin);

    //Compressing
    while(buf_cnt>0)
    {
        pos = search(winBuf,pattern);

        //Encode Prefix Bits
        if(pos.length>2)
        {
            put_ONE();
        }
        else if(pos.length==2)
        {
            put_ZERO();
            put_ONE();
        }
        else
        {
            put_ZERO();
            put_ZERO();
        }

        //Encoding Window Position
        putCodes(&pos);
    }

    flush_putBuffer();

    clock_t end=clock();
    double timeTook=(double)(end-begin)/CLOCKS_PER_SEC;

    fprintf(stderr,"Complete");

    //Getting Output File's Size and Compression Ratio
    outputFileLength=ftell(pOUT);
    fprintf(stderr,"\n\nName of The OutPut File: %s", argv[2]);
    fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);
    fprintf(stderr,"\nLength of Output File    =%15lu bytes",outputFileLength);
    fprintf(stderr,"\nCompression Ratio:        %15.2f%%\n",
        (((float)inputFileLength-(float)outputFileLength)/(float)inputFileLength)*(float)100);
    fprintf(stderr,"\nTime Took to Compress That File Using Lempel Ziv 77 and Adaptive Huffman Based on Vitter Algorithm = %lf Seconds\n",timeTook);

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
    i=lempelZivList[p[pat_cnt]];

    if(buf_cnt>1)
    {
        while(i!=LempelZiv_NULL)
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
            i=lempelZivNext[i];
         }
    }
    /*if(pos.length>=MIN_MATCH_LEN)
    {
        buf_cnt-=pos.length;
    }
    else
    {
        buf_cnt-=1;
    }*/

    buf_cnt-=pos.length;

    return pos;
}

void putCodes(pos_t *pos)
{
    int c,i,j,k;

    if(pos->length>2)
    {
        k=(uint)pos->length;
        k-=3;

        //Adaptive Huffman Encode to Match Length
        adaptiveHuffman_encodeSymbol(k);
    }

    //Encoding Position For Match
    if(pos->length>=2)
    {
        k=(uint)pos->position;
        put_nbits(k,NUM_POS_BITS);
    }
    else
    {
        k=(uchar)pattern[pat_cnt];
        put_nbits(k,8);
    }

    j=win_cnt & WIN_MASK;
    for(i=0;i<(pos->length);i++,j++)
    {
        //Removing Character from Character List
        delete_lempelZivNode(*(winBuf+(j&WIN_MASK)),(j&WIN_MASK));

        //Writing the Character to Window Buffer
        *(winBuf+(j&WIN_MASK))=*(pattern+((pat_cnt+i)%PAT_BUFFSIZE));

        //Inserting this Position to the Character's List
        insert_lempelZivNode(*(winBuf+(j&WIN_MASK)),(j&WIN_MASK));
    }

    for(i=0;i<(pos->length);i++)
    {
        if((c=gfgetc())!=EOF)
        {
            *(pattern+((pat_cnt+i)%PAT_BUFFSIZE))=(uchar)c;
        }
        else
        {
            break;
        }
    }

    //Updating Counters
    buf_cnt+=i;
    win_cnt=(win_cnt+pos->length)&WIN_MASK;
    if((pat_cnt=(pat_cnt+pos->length))>=PAT_BUFFSIZE)
    {
        pat_cnt-=PAT_BUFFSIZE;
    }
}
