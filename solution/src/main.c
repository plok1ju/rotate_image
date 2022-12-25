#include "../include/flip.h"
#include "../include/bmp.h"
#include "../include/utils.h"

int main( int argc, char** argv ) {
    ( void ) argc; ( void ) argv;

    enum args_status now_args_status = count_args( argc );
    if( now_args_status ){
        return 1;

    }

    FILE *file = NULL;
    FILE *new_file = NULL;

    //char *input_file = "/Users/evdokiiagalkina/CLionProjects/untitled3/assignment-image-rotation/tester/tests/1/input.bmp";
    //char *output_file = "/Users/evdokiiagalkina/CLionProjects/untitled3/assignment-image-rotation/tester/tests/1/output_expected.bmp";

    char *input_file = argv[1];
    char *output_file = argv[2];

    struct image picture = { 0 };
    struct image flip_picture = { 0 };

    file = fopen( input_file, "rb" );
    if( !file ){
        return 2;

    }

    enum read_status now_read_status = from_bmp( file, &picture );
    if( now_read_status ){
        return 3;

    }

    fclose( file );

    new_file = fopen( output_file, "wb" );
    if( !new_file ){
        return 2;

    }

    image_flip( &picture, &flip_picture );

    enum write_status now_write_status = to_bmp( new_file, &flip_picture );
    if( now_write_status ){
        return 5;

    }

    image_free(&picture);
    image_free(&flip_picture);

    fclose( new_file );

    return 0;
}
