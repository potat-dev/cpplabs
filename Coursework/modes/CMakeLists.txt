cmake_minimum_required(VERSION 3.0)

# Название проекта
project(modes)

# Установка переменной со списком исходников
set(SOURCE_LIB modes.cpp)

# Создание статической библиотеки
add_library(modes STATIC ${SOURCE_LIB})