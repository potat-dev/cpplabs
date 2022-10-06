cmake_minimum_required(VERSION 3.0)

# Название проекта
project(coursework)

# Установка переменной со списком исходников
set(SOURCE_EXE main.cpp)

# Расположение заголовочных файлов
include_directories(modes)
include_directories(number)
include_directories(fourier)

# Поиск библиотеки CLI11
find_package(CLI11 CONFIG REQUIRED)

# Создает исполняемый файл с именем main
add_executable(Coursework ${SOURCE_EXE})

# Добавление подпроектов, указывается имя дирректории
add_subdirectory(modes)
add_subdirectory(number)
add_subdirectory(fourier)

# Линковка программы с библиотекой
target_link_libraries(Coursework modes number fourier CLI11::CLI11)