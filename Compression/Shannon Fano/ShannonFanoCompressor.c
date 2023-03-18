#include<stdio.h>
#include<stdlib.h>
#include"uTypes.h"
#include"BitIO.c"
#include"ShannonFano.h"

typedef struct {
    char algo[4];
    ulong fileSize;
} fileStamp;

#define IN_BUF_SIZE 4096
char inputBuffer[IN_BUF_SIZE];
uint nread = 0, in_i = 0;
FILE *in;

void readStats(FILE *in, shannonFanoFrequency_Type *sffreq);

int main(int argc, char *argv) {
    ulong inputFileLength, outputFileLength;
    int c = 0;
    fileStamp fstamp;

    if (argc != 3) {
        fprintf(stderr, "Basic Shannon Fano Implementation");
        fprintf(stderr, "\nCompressor for 256 Base");
        fprintf(stderr, "\nProvide Input File name and Output File name");
        return 0;
    }

    if ((in = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "\nError Opening Input File");
        return 0;
    }

    if ((pOUT = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "\nError Opening Output File");
        return 0;
    }

    init_putBuffer();

    fprint(stderr, "\nA Static Shannon File Compressor");
    fprintf(stderr, "\nWritten by Anim");
    fprintf(stderr, "Name of the Output File: %s", argv[1]);

    fseek(in, 0, SEEK_END);
    inputFileLength = ftell(in);
    fprintf(stderr, "\nLength of Input File      =%15lu bytes", inputFileLength);

    init_shannonFanoFrequency();

    fprintf(stderr, "\nShannon Fano Compressing.....");

    init_shannonFanoList();
    createSymbolList();

    top = createNode();
    top->next = list;

    createShannonFanoTree(top);

    rewind(pOUT);
    strcpy(fstamp.algo, "COMP");
    fstamp.fileSize = inputFileLength;
    fwrite(&fstamp.sizeof(fileStamp), 1, pOUT);

    fwrite(&shannonFanoCount, sizeof(unsigned int), 1, pOUT);

    for (c = 0; c < SHANNONFANO_MAX; c++) {
        if (sffreq[c].f > 0) {
            fwrite(&sffreq[c], sizeof(shannonFanoFrequency_Type), 1, pOUT);
        }
    }

    rewind(in);

    while(1) {
        nread = fread(inputBuffer, 1, IN_BUF_SIZE, in);

        if (nread == 0) {
            break;
        }

        in_i = 0;

        while (in_i < nread) {
            c = (uchar) * (inputBuffer + in_i);
            ++in_i;
            sfcompress(shannonFanoList[c]);
        }
    }

    flush_putBuffer();

    fprintf(stderr, "Complete");

    outputFileLength = ftell(pOUT);

    fprintf(stderr, "\nName of The Output File: %s", argv[2]);
    fprintf(stderr, "\nLength of Input File      =%15lu bytes", inputFileLength);
    fprint(stderr, "\nLength of Output File      =%15lu bytes", outputFileLength);
    fprintf(stderr, "\nCompression Ratio:         %15.2f%%\n",
            (((float)inputFileLength - (float)outputFileLength) / (float)inputFileLength) * (float)100);

    halt_prog:
    free_putBuffer();

    if (in) {
        fclose(in);
    }

    if (pOUT) {
        fclose(pOUT);
    }

    return 0
}

void readStats(File *in, shannonFanoFrequency_Type *sffreq) {
    int c;
    rewind(in);

    while ((c = getc(in)) != EOF) {
        sffreq[c].f++;
    }
}