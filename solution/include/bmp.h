//
// Created by Evdokiia Galkina on 10/24/22.
//

#ifndef UNTITLED3_BMP_H

#include  <stdint.h>
#include <stdio.h>
#include "image.h"


#pragma pack(push, 1) // отмена автоматического выравнивания структуры

struct bmp_header // 432 бита = 54 байта - вес одного заголовка
{

    uint16_t bfType; // определяет тип файла. Здесь он должен быть BM
    uint32_t bfileSize; // размер файла в байтах - не всегда true
    uint32_t bfReserved; // что-то что зарезирвировано нулями
    uint32_t bOffBits; // показывает начало битового массива относительно начала файла ("от начала структуры BITMAPFILEHEADER"), который и описывает картинку.
    // чтобы гарантированно попадать на начало массива: SetFilePointer(hFile, bfh.bfOffBits, NULL, FILE_BEGIN);
    uint32_t biSize; // определяет размер структуры BITMAPINFOHEADER в байтах
    uint32_t biWidth; // ширина изображения
    uint32_t biHeight; // высота изображения
    uint16_t biPlanes; // задает количество плоскостей
    uint16_t biBitCount; // глубина пикселей? количество бит на пиксель? wdm?
    uint32_t biCompression; // позволяет узнать, хранится ли изображение в сжатом виде. Поскольку мы не собираемся работать со сжатыми BMP-файлами, необходимо проверить, имеет ли это поле значение BI_RGB (а не BI_RLE8, свидетельствующее о сжатии файла)
    uint32_t biSizeImage; // тут хранится размер графических данных (в пикселях), может быть равно 0
    uint32_t biXPelsPerMeter; // горизонтальное разрешение (в пикселях на метр)
    uint32_t biYPelsPerMeter; // вертикальное разрешение (в пикселях на метр)
    uint32_t biClrUsed; // определят кол-во используемых цветов в палитре, может быть равно 0
    uint32_t biClrImportant; // определение кол-ва важных цветов программы

};

#pragma pack(pop) //TODO что это?


//struct pixel { uint8_t b, g, r; }; // 24 бита = 3 байта - вес одного пикселя

enum read_status from_bmp( FILE* in, struct image* img );

enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
    READ_INVALID_IMAGE

};

enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR

};

enum write_status to_bmp( FILE* out, struct image* img);

enum  args_status  {
    COUNT_ARGS_OK,
    FEW_ARGS,
    MANY_ARGS

};

enum  args_status count_args(int args);

uint32_t calculate_padding(uint32_t width);
#endif //UNTITLED3_BMP_H
