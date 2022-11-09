//
// Created by Evdokiia Galkina on 10/29/22.
//

#ifndef UNTITLED3_UTILS_H
#define UNTITLED3_UTILS_H

#include <stdint.h>

enum  args_status  {

    COUNT_ARGS_OK = 0,
    FEW_ARGS,
    MANY_ARGS

};

enum  args_status count_args( const int args );

#endif //UNTITLED3_UTILS_H
