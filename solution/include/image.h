//
// Created by Evdokiia Galkina on 10/24/22.
//

#ifndef UNTITLED3_IMAGE_H
#define UNTITLED3_IMAGE_H

#include <stdint.h>
#include <stdlib.h>

struct image {

    uint64_t width, height;
    struct pixel* data;

};

enum image_status  {

    IMAGE_OK = 0,
    IMAGE_MALLOC_TROUBLE,

};

enum new_image_status new_image( uint32_t width, uint32_t height, struct image* new_image );

void image_free( struct image* old_im );

struct pixel { uint8_t b, g, r; };

#endif //UNTITLED3_IMAGE_H
