//
// Created by Evdokiia Galkina on 10/24/22.
//
#include <stdlib.h>
#include <stdio.h>
#include "../include/image.h"

struct image new_image(uint32_t width, uint32_t height){
    struct image new_im;
    new_im.data = malloc(sizeof (struct pixel)*height*width);
    if (new_im.data){
        new_im.width = width;
        new_im.height = height;
    }
    return new_im;
}

//uint64_t get_true_size(uint32_t width, uint32_t height){
//
//}

void free_image(struct image old_im){ //TODO освобождение памяти

}
