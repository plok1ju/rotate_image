//
// Created by Evdokiia Galkina on 10/24/22.
//
#include <stdint.h>

#ifndef UNTITLED3_IMAGE_H
#define UNTITLED3_IMAGE_H

struct image {
    uint64_t width, height;
    struct pixel* data;
};
#endif //UNTITLED3_IMAGE_H
