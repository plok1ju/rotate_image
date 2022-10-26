//
// Created by Evdokiia Galkina on 10/26/22.
//
#include "../include/open_bmp_file.h"

FILE* open_file(char* file_name, char* mode){
    FILE *file = fopen(file_name, mode);
    if(file){ return file;}
    return NULL;
}
