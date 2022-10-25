#include <stdio.h>


int main( int argc, char** argv ) {
    (void) argc; (void) argv; // supress 'unused parameters' warning
    FILE *f = fopen("/Users/evdokiiagalkina/CLionProjects/untitled3/assignment-image-rotation/build/test.txt", "rb");

    FILE *s = fopen("/Users/evdokiiagalkina/CLionProjects/untitled3/assignment-image-rotation/build/test1.txt", "wb");

//    char a = "1233";
//    fwrite(a, sizeof(char), 4, f);

    char b[4];

    fread(b, sizeof(char), 4, f);

    fwrite(b, sizeof(char), 4, s);

    printf("Hello, World!\n");
    fclose(f);
    fclose(s);

    return 0;
}
