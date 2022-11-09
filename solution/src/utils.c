//
// Created by Evdokiia Galkina on 10/29/22.
//

#include "../include/utils.h"

enum args_status count_args( int args ){

    if( args < 3 ){
        return FEW_ARGS;
    }

    else if ( args > 3 ){
        return  MANY_ARGS;
    }

    return COUNT_ARGS_OK;
}
