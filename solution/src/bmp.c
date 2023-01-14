//
// Created by Evdokiia Galkina on 10/24/22.
//
#include "../include/bmp.h"
#include "../include/bmp_header.h"

uint16_t BF_TYPE = 19778;
uint32_t BF_RESERVED = 0;
uint32_t B_OFF_BITS = 54;
uint32_t BI_SIZE = 40;
uint16_t BI_PLANES = 1;
uint16_t BI_BIT_COUNT = 24;
uint32_t BI_COMPRESSION = 0;
uint32_t BI_X_PELS_PER_METER = 2834;
uint32_t BI_Y_PELS_PER_METER = 2834;
uint32_t BI_CLR_USED = 0;
uint32_t BI_CLR_IMPORTANT = 0;

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

static uint32_t padding_calculate( const uint32_t width ){

    return ( 4 - ( width * 3 ) % 4 ) % 4;

}

enum read_status from_bmp( FILE* in, struct image* img ){

    static struct bmp_header header;

    uint32_t padding, width, height = 0;

    fread( &header, sizeof( struct bmp_header ), 1, in );
    if ( feof(in) ){
        return READ_INVALID_HEADER;
    }

    width = header.biWidth;
    height = header.biHeight;
    padding = padding_calculate( width );

    enum image_status image_status = new_image(width, height, img);
    if( image_status ){
        return READ_INVALID_IMAGE;
    }

    for ( uint32_t i = 0; i < height; i = i + 1 ){
        fread( ( img->data + i * width ), sizeof( struct pixel ) * width, 1, in );
        if ( feof(in) ){
            return READ_INVALID_BITS;
        }

        if (fseek(in, padding, SEEK_CUR)){
            return READ_INVALID_FSEEK;
        }
    }

    return READ_OK;

}

enum write_status to_bmp( FILE* out, const struct image* img ){

    const char pad_byte[3] = { 0, 0, 0 };

    struct bmp_header new_header = new_bmp_header( img->width, img->height );

    uint32_t padding = padding_calculate(img->width );

    fwrite(&new_header, sizeof( struct bmp_header ), 1, out );
    if ( feof(out) ){
        return WRITE_ERROR_HEADER;
    }

    for ( uint32_t j = 0; j < img->height; j = j + 1 ){

        fwrite( ( img->data + j * img->width ), sizeof( struct pixel ) * img->width, 1, out );
        if ( feof(out) ){
            return WRITE_ERROR_FILE;
        }

        fwrite( &pad_byte, 1, padding, out );
        if ( feof(out) ){
            return WRITE_ERROR_BYTE;
        }
    }

    return WRITE_OK;

}

struct bmp_header new_bmp_header(uint32_t width, uint32_t height){

    struct bmp_header new_header;
    uint32_t padding = padding_calculate(width );

    uint32_t size_image = 3 * height * width + width * padding;
    uint32_t file_size = size_image + sizeof ( struct bmp_header );

    new_header.biHeight = height;
    new_header.biWidth = width;
    new_header.biSizeImage = size_image;
    new_header.bfileSize = file_size;

    new_header.bfType = BF_TYPE;
    new_header.bfReserved = BF_RESERVED;
    new_header.bOffBits = B_OFF_BITS;
    new_header.biSize = BI_SIZE;
    new_header.biPlanes = BI_PLANES;
    new_header.biBitCount = BI_BIT_COUNT;
    new_header.biCompression = BI_COMPRESSION;
    new_header.biXPelsPerMeter = BI_X_PELS_PER_METER;
    new_header.biYPelsPerMeter = BI_Y_PELS_PER_METER;
    new_header.biClrUsed = BI_CLR_USED;
    new_header.biClrImportant = BI_CLR_IMPORTANT;


    return new_header;
}
