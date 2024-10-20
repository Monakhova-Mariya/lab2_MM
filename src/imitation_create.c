#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "key_gen.h"

void create_imitation(const char *input_file, const char *key, const char *output_file, const char *method) {
    FILE *fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) { // Проверка успешности открытия входного файла
        fprintf(stderr, "Ошибка открытия файла %s\n", input_file);
        exit(1);
    }

    FILE *fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) { // Проверка успешности создания выходного файла
        fclose(fp_in); // Закрытие входного файла
        fprintf(stderr, "Ошибка создания файла %s\n", output_file);
        exit(1);
    }

    // Использование функций работы с файлами
    fseek(fp_in, 0, SEEK_END); // Установка указателя файла на конец входного файла
    long file_size = ftell(fp_in); // Получение размера входного файла в байтах
    rewind(fp_in); // Возврат указателя файла в начало входного файла

    char *data = malloc(file_size + 1); // Выделение памяти под данные входного файла
    if (data == NULL) { // Проверка выделения памяти
        fclose(fp_in); // Освобождение памяти входного файла
        fclose(fp_out); // Освобождение
    }
}
