cmake_minimum_required(VERSION 3.0)

# Название проекта
project(coursework)

# Установка переменной со списком исходников
set(SOURCE_EXE main.cpp)

# Настройки параметров
set(BASE 1000000000)
message(STATUS "Using base: ${BASE}")
# не будет работать по причине: http://disq.us/p/d9r28h

# Расположение заголовочных файлов
include_directories(modes)
include_directories(number)
include_directories(fourier)

# Поиск библиотеки CLI11
find_package(CLI11 CONFIG REQUIRED)

# Создает исполняемый файл с именем main
add_executable(main ${SOURCE_EXE})

# Добавление подпроектов, указывается имя дирректории
add_subdirectory(modes)
add_subdirectory(number)
add_subdirectory(fourier)

# Линковка программы с библиотекой
target_link_libraries(main modes number fourier CLI11::CLI11)