cmake_minimum_required(VERSION 3.12)
project(imitation_tool_project VERSION 1.0 LANGUAGES C CXX)

# Задаем стандарт C++ только если версия CMake >= 3.12
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set(CMAKE_CXX_STANDARD 20)
endif()

# Настройки поиска OpenSSL
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
link_directories(${OPENSSL_LIBRARY_DIR})

# Добавляем папку include как директорию для заголовочных файлов
include_directories(include)

# Библиотека для генерации ключей (файлы наsходятся в папке src)
add_library(key_gen
    src/key_gen.c
    src/main.c
    include/key_gen.h
)
target_include_directories(key_gen PRIVATE include)
target_link_libraries(key_gen PRIVATE OpenSSL::Crypto OpenSSL::SSL)

# Библиотека для создания имитовставки (файлы находятся в папке src)
add_library(imitation_create
    src/imitation_create.c
    include/imitation_create.h
)
target_include_directories(imitation_create PRIVATE include)
target_link_libraries(imitation_create PRIVATE key_gen OpenSSL::Crypto OpenSSL::SSL)

# Приложение (файл main.c находится в папке src)
add_executable(imitation_tool
    src/main.c
)
target_link_libraries(imitation_tool PRIVATE imitation_create)

# Установка исполняемого файла и библиотек
install(TARGETS imitation_tool DESTINATION bin)
install(TARGETS key_gen imitation_create DESTINATION lib)
