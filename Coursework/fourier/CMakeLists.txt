cmake_minimum_required(VERSION 3.0)

# Название проекта
project(fourier)

# Установка переменной со списком исходников
set(SOURCE_LIB fourier.cpp)

# Создание статической библиотеки
add_library(fourier STATIC ${SOURCE_LIB})