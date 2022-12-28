cmake_minimum_required(VERSION 3.12)

# Название проекта
project(SUAI-Labs)

# Настройка CMake
set(CMAKE_CXX_STANDARD 17)

# Подключение лабораторных работ
add_subdirectory(Semester_1)
add_subdirectory(Semester_2)
add_subdirectory(Semester_3)

# Подключение практических работ
add_subdirectory(Practice)