//
// Created by Evdokiia Galkina on 10/27/22.
//

#include "../include/flip.h"

enum flip_status flip(struct image* image, struct image* flip_image){
    enum new_image_status status  = new_image(image->height, image->width, flip_image);
    if(status){
        return FLIP_MALLOC_TROUBLE;
    }
    uint32_t count = image->width*image->height - 1;
    for(uint32_t i = 0; i < image->width; i++){
        for(uint32_t j = 0; j < image->height; j++){
            flip_image->data[count] = image->data[((image->width - 1) + j * image->width) - i];
            count = count - 1;
        }
    }

    return SUCCESS_FLIP_IMAGE;

}
