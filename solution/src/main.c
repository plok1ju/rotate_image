#include <stdio.h>
#include <inttypes.h>
#include "../include/bmp.h"
#include "../include/open_bmp_file.h"
#include "../include/image.h"

int main( int argc, char** argv ) {
    (void) argc; (void) argv; // supress 'unused parameters' warning
//    char *name = "/Users/evdokiiagalkina/CLionProjects/untitled3/assignment-image-rotation/tester/tests/1/input.bmp";
//    char *mode = "rb";
    FILE *f = fopen("/Users/evdokiiagalkina/CLionProjects/untitled3/assignment-image-rotation/tester/tests/1/input.bmp", "rb");
    struct bmp_header header;
    fread(&header, sizeof(struct bmp_header), 1, f);

    if(f){
        printf("opeeeen");
    }
    printf("%" PRId32, header.biWidth);

    uint32_t size = header.bfileSize - sizeof(struct bmp_header);
    struct image im = new_image(header.biHeight, header.biWidth);

    fread(im.data, size, 1, f);
    FILE *m = fopen("/Users/evdokiiagalkina/CLionProjects/untitled3/assignment-image-rotation/tester/tests/1/output_expected.bmp", "wb");

    fwrite(&header, sizeof(struct bmp_header), 1, m);
    fwrite(im.data, size, 1, m);

    fclose(f);
    fclose(m);

    return 0;
}


//    FILE *f = fopen("/Users/evdokiiagalkina/CLionProjects/untitled3/assignment-image-rotation/build/test.txt", "rb");
//
//    FILE *s = fopen("/Users/evdokiiagalkina/CLionProjects/untitled3/assignment-image-rotation/build/test1.txt", "wb");
//
//    char a = "1233";
//    fwrite(a, sizeof(char), 4, f);
//
//    char b[4];
//
//    fread(b, sizeof(char), 4, f);
//
//    fwrite(b, sizeof(char), 4, s);
//
//    printf("Hello, World!\n");
//    fclose(f);
//    fclose(s);