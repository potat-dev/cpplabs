cmake_minimum_required(VERSION 3.12)

# Название проекта
project(Lab_20_dop)

# Создает исполняемый файл
add_executable(Lab_20_dop main.cpp)

# Скопировать файлы в папку с билдом
configure_file(graph.txt graph.txt COPYONLY)

# Add definitions
target_compile_definitions(Lab_20_dop PRIVATE DOP)