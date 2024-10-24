#ifndef LZ77_H_INCLUDED
#define LZ77_H_INCLUDED

#define lzNull -1
#define lzMax 256
#define lzMaxBuffer 8192

extern int lzPrevious[];
extern int lzNext[];

//Table of LZ heads, Indexed by 256 characters
extern int lzList[];

void initLZList(void);
void insertLZNode(unsigned char c,int i);
void deleteLZNode(unsigned char c,int i);

#endif // LZ77_H_INCLUDED
