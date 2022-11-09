//
// Created by Evdokiia Galkina on 10/24/22.
//
#include "../include/bmp.h"

static struct bmp_header header;

static uint32_t padding_calculate( const uint32_t width ){

    return ( 4 - ( width * 3 ) % 4 ) % 4;

}

enum read_status from_bmp( FILE* in, struct image* img ){

    uint32_t padding, width, height = { 0 };

    fread( &header, sizeof( struct bmp_header ), 1, in );

    width = header.biWidth;
    height = header.biHeight;
    padding = padding_calculate( width );

    enum new_image_status now_image_status = new_image(width, height, img);
    if( now_image_status ){
        return READ_INVALID_IMAGE;
    }

    for ( uint32_t i = 0; i < height; i = i + 1 ){

        if ( !( fread( ( img->data + i * width ), sizeof( struct pixel ) * width, 1, in ))){
            return READ_INVALID_BITS;
        }

        fseek(in, padding, SEEK_CUR);
    }

    return READ_OK;

}

enum write_status to_bmp( FILE* out, const struct image* img ){

    struct bmp_header new_header = { 0 };
    uint32_t padding, width, height, size_image, file_size = { 0 };

    padding = padding_calculate(img->width);
    struct pixel pad_byte = { 0, 0, 0 };

    new_bmp_header( &new_header, img );

    fwrite(&new_header, sizeof( struct bmp_header ), 1, out );

    for ( uint32_t j = 0; j < img->height; j = j + 1 ){

        fwrite( ( img->data + j * img->width ), sizeof( struct pixel ) * img->width, 1, out );

        fwrite( &pad_byte, 1, padding, out );
    }

    image_free( img );

    return WRITE_OK;

}

void new_bmp_header( struct bmp_header* new_header, const struct image* img ){
    uint32_t padding, width, height, size_image, file_size = { 0 };

    padding = padding_calculate( img->width );


    new_header = &header;
    width = img->width;
    height = img->height;
    size_image = 3 * height * width + width * padding;
    file_size = size_image + sizeof ( struct bmp_header );

    new_header->biHeight = height;
    new_header->biWidth = width;
    new_header->biSizeImage = size_image;
    new_header->bfileSize = file_size;

}
