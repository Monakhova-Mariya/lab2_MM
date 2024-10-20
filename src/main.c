#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "imitation_create.h"
#include "key_gen.h"


void generate_key(const char *password, char *key);

int main(int argc, char *argv[]) {
    int opt;
    const char *input_file = NULL;
    const char *password = NULL;
    const char *output_file = NULL;
    const char *method = "beginning";

    while ((opt = getopt(argc, argv, "f:p:o:k:")) != -1) {
        switch (opt) {
        case 'f':
            input_file = optarg;
            break;
        case 'p':
            password = optarg;
            break;
        case 'o':
            output_file = optarg;
            break;
        case 'k':
            method = optarg;
            break;
        default:
            fprintf(stderr, "Неизвестный аргумент: %c\n", optopt);
            return 1;
        }
    }

    if (input_file == NULL || password == NULL || output_file == NULL) {
        fprintf(stderr, "Необходимо указать все аргументы: -f, -p, -o\n");
        return 1;
    }

    char key[KEY_LENGTH + 1];
    generate_key(password, key);
    create_imitation(input_file, key, output_file, method);

    printf("Имитовставка успешно создана в '%s'\n", output_file);
    return 0;
}
