//
// Created by Evdokiia Galkina on 10/24/22.
//

#include "../include/image.h"

enum new_image_status new_image( uint32_t width, uint32_t height, struct image* new_image ){

    new_image->data = malloc( sizeof ( struct pixel )*height*width );

    if ( new_image->data ){

        new_image->width = width;
        new_image->height = height;
        return NEW_IMAGE_OK;

    }

    return NEW_IMAGE_MALLOC_TROUBLE;

}

void image_free( struct image* old_im ){

    free( old_im->data );

}
