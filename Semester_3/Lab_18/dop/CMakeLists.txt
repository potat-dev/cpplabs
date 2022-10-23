cmake_minimum_required(VERSION 3.11)

include(FetchContent)

# Название проекта
project(Lab_18_dop)

# Скачиваем библиотеку
FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
)

# Добавляем библиотеку
FetchContent_MakeAvailable(json)

# Создает исполняемый файл
add_executable(Lab_18_dop main.cpp cache.cpp translate.cpp)

# Скопировать файлы words.json и input.txt в папку сборки
configure_file(words.json words.json COPYONLY)
configure_file(input.txt input.txt COPYONLY)

# Линковка программы с библиотекой
target_link_libraries(Lab_18_dop PRIVATE nlohmann_json::nlohmann_json)