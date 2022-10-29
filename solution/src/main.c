#include "../include/flip.h"
#include "../include/bmp.h"

int main( int argc, char** argv ) {
    (void) argc; (void) argv;

    enum args_status now_args_status = count_args(argc);
    if(now_args_status){
        return 1;
    }

    FILE *file;
    FILE *new_file;

    char *input_file = argv[0];
    char *output_file = argv[1];

    struct image picture = {0};
    struct image flip_picture = {0};

    fopen(input_file, "rb");
    fopen(output_file, "wb");

    enum read_status now_read_status = from_bmp(file, &picture);
    if(now_read_status){
        return 1;
    }

    flip(&picture, &flip_picture);

    free_image(&picture);

    enum write_status now_write_status = to_bmp(new_file, &flip_picture);
    if(now_write_status){
        return 1;
    }

    free_image(&flip_picture);

    fclose(new_file);
    fclose(file);

    return 0;
}
