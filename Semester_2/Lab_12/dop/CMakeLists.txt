cmake_minimum_required(VERSION 3.0)

# Название проекта
project(Lab_12_dop)

# Создает исполняемый файл
add_executable(Lab_12_dop main.cpp HugeInt.cpp)

# Скопировать файлы в папку сборки
configure_file(input.txt input.txt COPYONLY)