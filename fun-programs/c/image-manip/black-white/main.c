// WORKS ONLY FOR BMP FILES
// using BMP file format to manipulate at the pixel level


// BMP header --> https://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm


#include <stdio.h>
#include <stdlib.h>

// single byte packing aligmenet of structs
#pragma pack(push, 1)
typedef struct
{
    // valid header signature (magic number) for a standard BMP file consists of two bytes: 0x42 0x4D <<--- from google
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
#pragma pack(pop)


int main()
{
    FILE *fInp = fopen("testImage.bmp", "rb");
    if (!fInp)
    {
        printf("Could not open file.");
        return EXIT_FAILURE;
    }

    BMPHeader header;
    BMPinfoHeader info;

    fread(&header, sizeof(BMPHeader), 1, fInp);
    fread(&info, sizeof(BMPinfoHeader), 1, fInp);

    if (header.signature != 0x4D42)
    {
        printf("not a valid BMP file");
        fclose(fInp);
        return EXIT_FAILURE;
    }

    printf("BMP file validated.\n");
    printf("signature: 0x%hx", header.signature);
    fclose(fInp);

    return 0;
}
