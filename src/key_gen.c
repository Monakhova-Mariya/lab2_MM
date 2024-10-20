#include <string.h>
#include "key_gen.h"
#include <openssl/evp.h>

// Объявление функции generate_key
void generate_key(const char *password, char *key) {
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new(); // Создание контекста хеширования
    if (mdctx == NULL) { // Проверка успешности создания контекста
        return;
    }

    const EVP_MD *md = EVP_sha256(); // Выбор алгоритма хеширования SHA-256

    // Использование контекста и алгоритма для хеширования данных
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, password, strlen(password));
    int len = EVP_MAX_MD_SIZE; // Определение размера ключа
    char *derivedKey = malloc(len); // Выделение памяти под ключ
    if (derivedKey == NULL) { // Проверка выделения памяти
        EVP_MD_CTX_free(mdctx); // Освобождение памяти контекста
        return;
    }
    EVP_DigestFinal_ex(mdctx, derivedKey, &len); // Хеширование данных в ключ

    *key = *derivedKey; // Копирование ключа в буфер
    free(derivedKey); // Освобождение выделенной памяти

    EVP_MD_CTX_destroy(mdctx); // Уничтожение контекста
}
