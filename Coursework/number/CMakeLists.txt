cmake_minimum_required(VERSION 3.0)

# Название проекта
project(number)

# Установка переменной со списком исходников
set(SOURCE_LIB number.cpp)

# Создание статической библиотеки
add_library(number STATIC ${SOURCE_LIB})