#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"uTypes.h"
#include"BitIO.c"
#include"LempelZivHash.c"
#include"AdaptiveHuffmanFGK.c"

#define NUM_POS_BITS 14
#define WIN_BUFFSIZE (1<<NUM_POS_BITS)
#define WIN_MASK (WIN_BUFFSIZE-1)
#define HASH_SHIFT (NUM_POS_BITS-8)

#define NUM_LEN_BITS 8
#define PAT_BUFFSIZE ((1<<NUM_LEN_BITS)+MIN_LEN)
#define MIN_LEN 3

//3 Byte Hash
#define hash_w(pos)\
    ((winBuf[(pos) & WIN_MASK] << HASH_SHIFT) ^ (winBuf[((pos)+1) & WIN_MASK]<<1)\
     ^ (winBuf[((pos)+2) & WIN_MASK]<<4))

#define hash_p(pos)\
    ((pattern[(pos)] << HASH_SHIFT) ^ (pattern[((pos)+1) % PAT_BUFFSIZE] << 1)\
     ^ (pattern[((pos)+2) % PAT_BUFFSIZE]<<4))

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
    int i;
    fileStamp fstamp;

    if(argc!=3)
    {
        fprintf(stderr,"Basic Lempel Ziv 77 And Adaptive Huffman Based on FGK Algorithm's with 3 Byte Hash Implementation");
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

    fprintf(stderr,"\nA Lempel Ziv 77 and Adaptive Huffman FGK Algorithm with 3 Byte Hash Compressor");
    fprintf(stderr,"\nWriten and Modified by Anim");
    fprintf(stderr,"\nWindow Buffer Size    : %151lu bytes",(ulong)WIN_BUFFSIZE);
    fprintf(stderr,"\nLook Ahead Buffer Size: %151lu bytes",(ulong)PAT_BUFFSIZE);
    fprintf(stderr,"\nName of the Input File: %s",argv[1]);

    clock_t begin=clock();

    init_putBuffer();

    //Displaying the Length of Input File
    fseek(gIN,0,SEEK_END);
    inputFileLength=ftell(gIN);

    rewind(pOUT);
    strcpy(fstamp.algo,"DEF");
    fstamp.fileSize=inputFileLength;
    fwrite(&fstamp,sizeof(fileStamp),1,pOUT);

    //Start Compressing to Output File
    fprintf(stderr,"\nCompressing Using Lempel Ziv 77 and Adaptive Huffman Based on FGK Algorithm with 3 Byte Hash");

    //Initializing Table of Pointers
    if(!allocate_lempelZivHash(WIN_BUFFSIZE))
    {
        goto HALT_PROG;
    }

    //Setting Sliding Window
    memset(winBuf,0,WIN_BUFFSIZE);

    //Initializing the Search List
    for(i=0;i<WIN_BUFFSIZE;i++)
    {
        lempelZivNext[i]=LempelZiv_NULL;
        lempelZivPrevious[i]=LempelZiv_NULL;
        insert_lempelZivHashNode(hash_w(i),i);
    }

    rewind(gIN);

    //Filling the Pattern Buffer
    buf_cnt=fread(pattern,1,PAT_BUFFSIZE,gIN);

    //Initializing the Input Buffer
    init_getBuffer();

    //Adaptive Huffman Initializations
    hmax_symbols=PAT_BUFFSIZE-MIN_LEN;
    huffmanSymbol_bitSize=NUM_LEN_BITS;
    adaptiveHuffman_initFirstNode(hmin=0);

    //Compressing
    while(buf_cnt>0)
    {
        pos=search(winBuf,pattern);

        //Encoding Prefix Bits
        if(pos.length > MIN_LEN)
        {
            put_ONE();
        }
        else if(pos.length==MIN_LEN)
        {
            put_ZERO();
            put_ONE();
        }
        else
        {
            put_ZERO();
            put_ZERO();
        }

        //Encoding Window Buffer
        putCodes(&pos);
    }

    flush_putBuffer();

    clock_t end=clock();
    double timeTook=(double)(end-begin)/CLOCKS_PER_SEC;

    //Getting Output File's Size and Compression Ratio
    outputFileLength=ftell(pOUT);

    fprintf(stderr,"\n\nName of The OutPut File: %s", argv[2]);
    fprintf(stderr,"\nLength of Input File     =%15lu bytes",inputFileLength);
    fprintf(stderr,"\nLength of Output File    =%15lu bytes",outputFileLength);
    fprintf(stderr,"\nCompression Ratio:        %15.2f%%\n",
        (((float)inputFileLength-(float)outputFileLength)/(float)inputFileLength)*(float)100);
    fprintf(stderr,"\nTime Took to Compress Using Lempel Ziv 77 and Adaptive Huffman Based on FGK Algorithm with 3 Byte Hash     = %lf Seconds\n",timeTook);

    HALT_PROG:

    free_putBuffer();
    free_getBuffer();
    free_lempelZivHash();
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
    pos_t pos={0,0};

    i=lempelZivHash[hash_p(pat_cnt)];

    if(buf_cnt>1)
    {
        while(i!=LempelZiv_NULL)
        {
            if((j=pat_cnt+pos.length)>=PAT_BUFFSIZE)
            {
                j-=PAT_BUFFSIZE;
            }
            k=pos.length;
            do
            {
                if(p[j]!=w[(i+k)&WIN_MASK])
                {
                    goto skipSearch;
                }
                if(j-- == 0)
                {
                    j=PAT_BUFFSIZE-1;
                }
            }
            while((--k)>=0);

            if((j=pat_cnt+pos.length+1)>=PAT_BUFFSIZE)
            {
                j-=PAT_BUFFSIZE;
            }

            k=pos.length+1;

            if(k<buf_cnt)
            {
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
            }

            if(k>pos.length)
            {
                pos.position=i;
                pos.length=k;

                if(k==buf_cnt)
                {
                    break;
                }
            }

            skipSearch:

            //Pointing to Next Occurrence of This Hash Table
            i=lempelZivNext[i];
        }
    }
    return pos;
}

void putCodes(pos_t *pos)
{
    int i,j,k;

    if(pos->length > MIN_LEN)
    {
        k=pos->length-(MIN_LEN+1);
        adaptiveHuffman_encodeSymbol(k);
    }

    if(pos->length>=MIN_LEN)
    {
        k=pos->position;
        put_nbits(k,NUM_POS_BITS);
    }
    else
    {
        pos->length=1;
        k=(uchar)pattern[pat_cnt];
        put_nbits(k,8);
    }

    if((j=win_cnt-2)<0)
    {
        j=k=WIN_BUFFSIZE+j;
    }
    else
    {
        k=j;
    }

    //Removing Strings from The Hash List
    for(i=0;i<(pos->length+2);i++,j++)
    {
        delete_lempelZivHashNode(hash_w(j),j&WIN_MASK);
    }

    j=win_cnt;

    for(i=0;i<pos->length;i++,j++)
    {
        *(winBuf+((j)&(WIN_MASK))) = *(pattern+((pat_cnt+i)%PAT_BUFFSIZE));
    }

    //ReHashing the Position
    j=k;
    for(i=0;i<(pos->length+2);i++,j++)
    {
        insert_lempelZivHashNode(hash_w(j),j&WIN_MASK);
    }

    //Getting Length Bytes
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

    //Updating Counters
    buf_cnt-=(pos->length-i);
    win_cnt=(win_cnt+pos->length)&WIN_MASK;
    if((pat_cnt=(pat_cnt+pos->length))>=PAT_BUFFSIZE)
    {
        pat_cnt-=PAT_BUFFSIZE;
    }
}
