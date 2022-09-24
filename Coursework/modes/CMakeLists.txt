cmake_minimum_required(VERSION 3.0)

project(modes) # Название проекта
set(SOURCE_LIB modes.cpp) # Установка переменной со списком исходников
add_library(modes STATIC ${SOURCE_LIB}) # Создание статической библиотеки