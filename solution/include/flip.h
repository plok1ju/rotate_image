//
// Created by Evdokiia Galkina on 10/27/22.
//

#include "image.h"

#ifndef UNTITLED3_FLIP_H
#define UNTITLED3_FLIP_H

enum flip_status{

    SUCCESS_FLIP_IMAGE = 0,
    FLIP_MALLOC_TROUBLE

};

enum flip_status image_flip( const struct image* image, struct image* flip_image );

#endif //UNTITLED3_FLIP_H
