//
// Created by Evdokiia Galkina on 10/24/22.
//
#include <stdlib.h>
#include "headlines/image.h"

struct image {
    uint64_t width, height;
    struct pixel* data;
};
