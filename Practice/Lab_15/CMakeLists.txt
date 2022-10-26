cmake_minimum_required(VERSION 3.0)

# Название проекта
project(Lab_15)

# Создает исполняемый файл
add_executable(Lab_15_practice main.cpp)

# Скопировать файлы в папку сборки
configure_file(kek.bmp kek.bmp COPYONLY)