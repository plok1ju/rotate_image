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

struct image new_image(uint32_t width, uint32_t height);

void free_image(struct image old_im);

struct pixel { uint8_t b, g, r; }; // 24 бита = 3 байта - вес одного пикселя

#endif //UNTITLED3_IMAGE_H
