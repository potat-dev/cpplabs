cmake_minimum_required(VERSION 3.0)

# Название проекта
project(Lab_17)

# Установка переменной со списком исходников
set(SOURCE_EXE main.cpp)

# Поиск библиотеки nlohmann_json
find_package(nlohmann_json 3.2.0 REQUIRED)

# Создает исполняемый файл с именем main
add_executable(lab17 ${SOURCE_EXE})

# Линковка программы с библиотекой
target_link_libraries(lab17 nlohmann_json::nlohmann_json)