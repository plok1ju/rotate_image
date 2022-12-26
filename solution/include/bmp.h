//
// Created by Evdokiia Galkina on 10/24/22.
//

#ifndef UNTITLED3_BMP_H

#include "image.h"

#include <stdio.h>

enum read_status  {

    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
    READ_INVALID_IMAGE,
    READ_INVALID_FSEEK

};

enum  write_status  {

    WRITE_OK = 0,
    WRITE_ERROR,
    WRITE_ERROR_HEADER,
    WRITE_ERROR_FILE,
    WRITE_ERROR_BYTE

};

enum read_status from_bmp( FILE* in, struct image* img );

enum write_status to_bmp( FILE* out, const struct image* img );

#endif //UNTITLED3_BMP_H
