cmake_minimum_required(VERSION 3.0)

project(fourier) # Название проекта
set(SOURCE_LIB fourier.cpp) # Установка переменной со списком исходников
add_library(fourier STATIC ${SOURCE_LIB}) # Создание статической библиотеки