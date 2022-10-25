cmake_minimum_required(VERSION 3.0)

# Название проекта
project(Lab_6_base_cpp)

# Создает исполняемый файл
add_executable(Lab_6_base_cpp main.cpp snippets.cpp)

# Скопировать файлы в папку сборки
configure_file(input.txt input.txt COPYONLY)