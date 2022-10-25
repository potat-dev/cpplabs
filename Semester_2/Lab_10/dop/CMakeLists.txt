cmake_minimum_required(VERSION 3.0)

# Название проекта
project(Lab_10_dop)

# Создает исполняемый файл
add_executable(Lab_10_dop main.cpp file.cpp)

# Копируем файлы в папку с билдом
configure_file(input.txt input.txt COPYONLY)