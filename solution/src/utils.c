//
// Created by Evdokiia Galkina on 10/29/22.
//

#include "../include/utils.h"

uint32_t calculate_padding(uint32_t width){
    return (4 - (width * 3) % 4) % 4;
}

enum args_status count_args(int args){

    if(args <2){
        return FEW_ARGS;
    }

    else if (args > 2){
        return  MANY_ARGS;
    }

    return COUNT_ARGS_OK;
}