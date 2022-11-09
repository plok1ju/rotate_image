//
// Created by Evdokiia Galkina on 10/24/22.
//

#ifndef UNTITLED3_BMP_H

#include "image.h"
#include "utils.h"

#include <stdio.h>

#pragma pack( push, 1 )

struct bmp_header
{

    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;

};

#pragma pack( pop )

static uint32_t padding_calculate( const uint32_t width );

enum read_status  {

    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
    READ_INVALID_IMAGE

};

enum  write_status  {

    WRITE_OK = 0,
    WRITE_ERROR

};

enum read_status from_bmp( FILE* in, struct image* img );

void new_bmp_header( struct bmp_header* new_header, const struct image* img );

enum write_status to_bmp( FILE* out, const struct image* img );

#endif //UNTITLED3_BMP_H
