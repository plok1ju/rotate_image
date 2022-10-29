#include "../include/open_bmp_file.h"
#include "../include/flip.h"
#include "../include/bmp.h"

int main( int argc, char** argv ) {
    (void) argc; (void) argv;

    enum args_status argsStatus = count_args(argc);
    if(argsStatus){
        return 1;
    }

    FILE *file;
    FILE *new_file;

    char *input_file = argv[0];
    char *output_file = argv[1];

    struct image pic = {0};
    struct image flip_pic = {0};

    enum open_status openStatus = open_file(&file,input_file,"rb");
    if(openStatus){
        return 1;
    }

    enum open_status openStatuS = open_file(&new_file,output_file,"wb");
    if(openStatuS){
        return 1;
    }

    enum read_status readStatus = from_bmp(file, &pic);
    if(readStatus){
        return 1;
    }

    flip(&pic, &flip_pic);

    free_image(&pic);

    enum write_status writeStatus = to_bmp(new_file, &flip_pic);
    if(writeStatus){
        return 1;
    }

    free_image(&flip_pic);

    fclose(new_file);
    fclose(file);

    return 0;
}
