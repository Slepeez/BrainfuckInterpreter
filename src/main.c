#include "interpreter.h"
int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <brainfuck_code>\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE* file = fopen(argv[1], "r");
    if(!file){
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* code = malloc(file_size + 1);
    if(!code){
        perror("Failed to allocate memory for code");
        fclose(file);
        return EXIT_FAILURE;
    }
    size_t read_bytes = fread(code, 1, file_size, file);
    code[read_bytes] = '\0';
    fclose(file);
    interpret(code, read_bytes);
    return EXIT_SUCCESS;
}