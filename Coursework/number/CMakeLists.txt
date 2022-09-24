cmake_minimum_required(VERSION 3.0)

project(number) # Название проекта
set(SOURCE_LIB number.cpp) # Установка переменной со списком исходников
add_library(number STATIC ${SOURCE_LIB}) # Создание статической библиотеки