//
// Created by Evdokiia Galkina on 10/26/22.
//

#ifndef UNTITLED3_OPEN_BMP_FILE_H
#define UNTITLED3_OPEN_BMP_FILE_H

#include <stdbool.h>
#include <stdio.h>

enum open_status open_file(FILE** file,char* file_name, char* mode);

enum open_status {
    SUCCESS,
    NOT_SUCCESS

};

#endif //UNTITLED3_OPEN_BMP_FILE_H
