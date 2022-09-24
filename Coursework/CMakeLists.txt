cmake_minimum_required(VERSION 3.0)

project(coursework) # Название проекта

set(SOURCE_EXE main.cpp) # Установка переменной со списком исходников

include_directories(number) # Расположение заголовочных файлов
include_directories(fourier) # Расположение заголовочных файлов

include_directories(${CLI11_DIR}/include) # Расположение заголовочных файлов

add_executable(main ${SOURCE_EXE}) # Создает исполняемый файл с именем main

add_subdirectory(number) # Добавление подпроекта, указывается имя дирректории
add_subdirectory(fourier) # Добавление подпроекта, указывается имя дирректории

target_link_libraries(main number fourier) # Линковка программы с библиотекой