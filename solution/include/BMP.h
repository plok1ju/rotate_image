//
// Created by Evdokiia Galkina on 10/24/22.
//

#ifndef UNTITLED3_BMP_H
#define UNTITLED3_BMP_H
#include  <stdint.h>
#pragma pack(push, 1)
struct bmp_header
{

    uint16_t bfType;
    uint32_t  bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t  biHeight;
    uint16_t  biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;

    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t  biClrImportant;
};
#pragma pack(pop)

struct pixel { uint8_t b, g, r; };
#endif //UNTITLED3_BMP_H