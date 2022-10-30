cmake_minimum_required(VERSION 3.0)

# Название проекта
project(Lab_15_extended)

# Создает исполняемый файл
add_executable(Lab_15_extended main.cpp)

# Скопировать файлы в папку сборки
configure_file(input.bmp input.bmp COPYONLY)