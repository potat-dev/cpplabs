cmake_minimum_required(VERSION 3.12)

# Название проекта
project(Lab_15_base)

# Создает исполняемый файл
add_executable(Lab_15_base main.cpp)

# Скопировать файлы в папку сборки
configure_file(input.bmp input.bmp COPYONLY)