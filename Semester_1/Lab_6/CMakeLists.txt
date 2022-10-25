cmake_minimum_required(VERSION 3.0)

# Название проекта
project(Lab_6)

# Создает исполняемый файл
add_executable(Lab_6_base main.c)
add_executable(Lab_6_dop dop.c)

# Скопировать папку input в папку сборки
file(COPY input DESTINATION ${CMAKE_BINARY_DIR})