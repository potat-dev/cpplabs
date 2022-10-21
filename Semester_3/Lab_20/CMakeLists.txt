cmake_minimum_required(VERSION 3.0)

# Название проекта
project(Lab_20)

# Установка переменной со списком исходников
set(SOURCE_EXE main.cpp)

# Создает исполняемый файл с именем main
add_executable(Lab_20 ${SOURCE_EXE})
add_executable(Lab_20_dop ${SOURCE_EXE})

# Установка define DOP для компиляции
target_compile_definitions(Lab_20_dop PRIVATE DOP)

# Скопировать файлы в папку с билдом
configure_file(graph.txt graph.txt COPYONLY)