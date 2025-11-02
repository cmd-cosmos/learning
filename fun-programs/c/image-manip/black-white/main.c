// WORKS ONLY FOR BMP FILES
// using BMP file format to manipulate at the pixel level


// BMP header --> https://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm

// standard RGB to Grayscale conversion using the weighted method
// Grayscale = 0.299R + 0.587G + 0.114B


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
    printf("signature: 0x%hx\n", header.signature);
    printf("Width: %d px\n", info.width);
    printf("height: %d px\n", info.height);
    printf("Bits per pixel: %d\n", info.bits_per_pixel);
    printf("pixel data start offset: %d\n", header.offset);

    printf("\nConverting input image to black and white.\n");

    FILE *fout = fopen("out.bmp", "wb");

    if (!fout)
    {
        printf("error - could not create output image.\n");
        fclose(fInp);
        return EXIT_FAILURE;
    }

    fwrite(&header, sizeof(BMPHeader), 1, fout);
    fwrite(&info, sizeof(BMPinfoHeader), 1, fout);

    int width = info.width;
    int height = info.height;

    int padding = (4 - (width*3) % 4) % 4; // add padding only if row not a multiple of 4

    RGB pixel;
    for (int y = 0; y < height; y++) // go through all rows(height of the image) but by columns(width)
    {
        for (int x = 0; x < width; x++)
        {
            fread(&pixel, sizeof(RGB) - 1, 1, fInp); // reads 3 bytes at once

            unsigned char gray = (unsigned char)(0.299 * pixel.red + 0.587 * (pixel.green) + 0.114 * (pixel.blue));

            pixel.red = pixel.green = pixel.blue = gray;

            fwrite(&pixel, sizeof(RGB) - 1, 1, fout);
        }
        fseek(fInp, padding, SEEK_CUR);
    }
    fseek(fInp, padding, SEEK_CUR);

    for(int pad = 0; pad < padding; pad++)
    {
        fputc(0x00, fout);
    }

    fclose(fInp);
    fclose(fout);

    return 0;
}
