#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct BMPFileHeader
{

    char bfType1;
    char bfType2;
    int bfsize;
    short int bfreserved1;
    short int bfreserved2;
    int bfOffBits;

};

struct BMPInfoHeader
{
	int bisize;
	int biwidth;
	int biheight;
	short int biplanas;
	short int bibitcount;
	int bicompression;
	int bisizeimage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	int biClrUsed;
	int biClrImportant;

};

void printBMPFileHeader(struct BMPFileHeader bmpfh) 
{
	printf("\n\nTHE INFO OF BITMAP FILE HEADER");
	printf("\nBftype1:  		%c", bmpfh.bfType1);
	printf("\nBftype2:   		%c", bmpfh.bfType2);
	printf("\nBfsize:   		%d", bmpfh.bfsize);
	printf("\nBfreserved1:   	%d", bmpfh.bfreserved1);
	printf("\nBfreserved2:   	%d", bmpfh.bfreserved2);
	printf("\nbfOffBits:   		%d", bmpfh.bfOffBits);
	
	return;
}

void printBMPInfoHeader( struct BMPInfoHeader bmpih)
{
	
	printf("\n\nTHE INFO of BITMAP INFO HEADER ");
	printf("\nbisize:	%d",bmpih.bisize );
	printf("\nbiwidth:	%d",bmpih.biwidth);
	printf("\nbiheight:	%d",bmpih.biheight);
	printf("\nbiplanas:	%d",bmpih.biplanas);		
	printf("\nbibitcount:	%d",bmpih.bibitcount);
	printf("\nbicompression:	%d",bmpih.bicompression);
	printf("\nbisizeimage:	%d",bmpih.bisizeimage);
	printf("\nbiXpelsPermeters:	%d",bmpih.biXPelsPerMeter);
	printf("\nbiYPelsPerMeter:	%d",bmpih.biYPelsPerMeter);
	printf("\nbiClrUsed:	%d",bmpih.biClrUsed);	
	printf("\nbiClrImportant:	%d",bmpih.biClrImportant);


}


int main()
{
	FILE *fp;
	struct BMPFileHeader bmpfh;
	struct BMPInfoHeader bmpih;
	fp= fopen("ugurbocegi.bmp","rb");
	if (fp== NULL)
	{
		printf("File is not opened");
		exit(1);
	}
	
	fread(&bmpfh,sizeof(struct BMPFileHeader),1,fp);
	printBMPFileHeader(bmpfh);
	
	fread(&bmpih,sizeof(struct BMPInfoHeader),1,fp);
	printBMPInfoHeader(bmpih);
	fclose(fp);

    return 0;


}
