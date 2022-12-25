//
// Created by Evdokiia Galkina on 10/24/22.
//
#include "../include/bmp.h"

uint32_t padding_calculate( const uint32_t width ){

    return ( 4 - ( width * 3 ) % 4 ) % 4;

}

enum read_status from_bmp( FILE* in, struct image* img ){

    static struct bmp_header header;

    uint32_t padding, width, height = 0;

    enum read_status now_read_status = fread( &header, sizeof( struct bmp_header ), 1, in );
    if ( now_read_status ){
        return READ_INVALID_HEADER;
    }

    width = header.biWidth;
    height = header.biHeight;
    padding = padding_calculate( width );

    enum image_status now_image_status = new_image(width, height, img);
    if( now_image_status ){
        return READ_INVALID_IMAGE;
    }

    for ( uint32_t i = 0; i < height; i = i + 1 ){
        enum read_status now_bits_read_status = fread( ( img->data + i * width ), sizeof( struct pixel ) * width, 1, in );
        if ( now_bits_read_status ){
            return READ_INVALID_BITS;
        }

        fseek(in, padding, SEEK_CUR);
    }

    return READ_OK;

}

enum write_status to_bmp( FILE* out, const struct image* img ){

    struct pixel pad_byte = { 0, 0, 0 };

    struct bmp_header new_header = new_bmp_header( img->width, img->height );

    uint32_t padding = padding_calculate(img->width );

    enum write_status now_write_status = fwrite(&new_header, sizeof( struct bmp_header ), 1, out );
    if ( now_write_status ){
        return WRITE_ERROR;
    }

    for ( uint32_t j = 0; j < img->height; j = j + 1 ){

        enum write_status now_bits_write_status = fwrite( ( img->data + j * img->width ), sizeof( struct pixel ) * img->width, 1, out );
        if ( now_bits_write_status ){
            return WRITE_ERROR;
        }

        enum write_status now_pad_byte_write_status = fwrite( &pad_byte, 1, padding, out );
        if ( now_pad_byte_write_status ){
            return WRITE_ERROR;
        }

    }

    return WRITE_OK;

}

struct bmp_header new_bmp_header(uint32_t width, uint32_t height){

    struct bmp_header new_header;
    uint32_t padding = padding_calculate( width );

    uint32_t size_image = 3 * height * width + width * padding;
    uint32_t file_size = size_image + sizeof ( struct bmp_header );

    new_header.biHeight = height;
    new_header.biWidth = width;
    new_header.biSizeImage = size_image;
    new_header.bfileSize = file_size;

    new_header.bfType = 19778;
    new_header.bfReserved = 0;
    new_header.bOffBits = 54;
    new_header.biSize = 40;
    new_header.biPlanes = 1;
    new_header.biBitCount = 24;
    new_header.biCompression = 0;
    new_header.biXPelsPerMeter = 2834;
    new_header.biYPelsPerMeter = 2834;
    new_header.biClrUsed = 0;
    new_header.biClrImportant = 0;


    return new_header;
}
