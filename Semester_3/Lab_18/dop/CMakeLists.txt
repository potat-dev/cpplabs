cmake_minimum_required(VERSION 3.0)

# Название проекта
project(Lab_18_dop)

# Создает исполняемый файл
add_executable(Lab_18_dop main.cpp)

# Скопировать файлы words.json и input.txt в папку сборки
configure_file(words.json words.json COPYONLY)
configure_file(input.txt input.txt COPYONLY)