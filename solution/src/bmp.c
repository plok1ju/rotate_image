//
// Created by Evdokiia Galkina on 10/24/22.
//
#include "../include/bmp.h"

uint32_t calculate_padding(uint32_t width){
    return (4 - (width * 3) % 4) % 4;
}

static struct bmp_header header;

enum read_status from_bmp( FILE* in, struct image* img ){

    uint32_t padding, width, height;
    fread(&header, sizeof(struct bmp_header), 1, in);
    width = header.biWidth;
    height = header.biHeight;
    padding = calculate_padding(img->width);
    enum new_image_status status = new_image(width, height, img);
    if(status){
        return READ_INVALID_IMAGE;
    }
    for (uint32_t i = 0; i < height; i++){
        if (!(fread((img->data + i * width), sizeof(struct pixel) * width, 1, in)))
            return READ_INVALID_BITS;
        fseek(in, padding, SEEK_CUR);
    }
    return READ_OK;
}

enum write_status to_bmp( FILE* out, struct image* img){
    struct bmp_header new_header;
    uint32_t padding = calculate_padding(img->width);
    uint8_t pad_byte = 1;
    new_header = header;
    new_header.biHeight = header.biWidth;
    new_header.biWidth = header.biHeight;
    new_header.biSizeImage = header.biWidth*(header.biHeight + header.biHeight*padding);
    fwrite(&new_header, sizeof(struct bmp_header), 1, out);
    for (uint32_t i = 0; i < img->height; i++){
        fwrite((img->data + i * img->width), sizeof(struct pixel) * img->width, 1, out);
        fwrite(&pad_byte, 1, padding, out);
    }
    return WRITE_OK;

}

enum args_status count_args(int args){
    if(args <2){
        return FEW_ARGS;
    }
    else if (args > 2){
        return  MANY_ARGS;
    }
    return COUNT_ARGS_OK;
}

enum open_status open_file(FILE** file, char* file_name, char* mode){
    *file = fopen(file_name, mode);
    if (file != NULL) return SUCCESS_OPEN_FILE;
    return NOT_SUCCESS_OPEN_FILE;

}



