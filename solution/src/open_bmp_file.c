//
// Created by Evdokiia Galkina on 10/26/22.
//
#include "../include/open_bmp_file.h"

enum open_status open_file(FILE** file, char* file_name, char* mode){
    *file = fopen(file_name, mode);
    if (file != NULL) return SUCCESS_OPEN_FILE;
    return NOT_SUCCESS_OPEN_FILE;

}
