// WORKS ONLY FOR BMP FILES
// using BMP file format to manipulate at the pixel level


// BMP header --> https://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm


#include <stdio.h>
#include <stdlib.h>

// single byte packing aligmenet of structs
#pragma pack(push, 1)
typedef struct
{
    unsigned short signature; // 2 bytes
    unsigned int size;        // 4 bytes
    unsigned int reserved;    // 4 bytes
    unsigned int offset;      // 4 bytes
} BMPHeader; // header --> 14 bytes

typedef struct
{
    unsigned int size, width, height;
    unsigned short planes, bits_per_pixel;
    unsigned int compression, imagesize, XpixelsPerM, YpixelsPerM;
    unsigned int colors, impColors;
} BMPinfoHeader; // info header --> 40 bytes

typedef struct
{
    // BMP color table stores in the blue --> green --> red order for each entry 
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char res;  // set to 0x00 --> unused 4th byte
}RGB; // color table --> 4 bytes


int main()
{


    return 0;
}
