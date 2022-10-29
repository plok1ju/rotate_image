//
// Created by Evdokiia Galkina on 10/29/22.
//

#ifndef UNTITLED3_UTILS_H
#define UNTITLED3_UTILS_H

#include <stdint.h>

uint32_t calculate_padding(uint32_t width);

enum  args_status  {

    COUNT_ARGS_OK = 0,
    FEW_ARGS,
    MANY_ARGS

};

enum  args_status count_args(int args);

#endif //UNTITLED3_UTILS_H
