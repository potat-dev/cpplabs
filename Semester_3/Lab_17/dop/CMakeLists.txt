cmake_minimum_required(VERSION 3.11)

include(FetchContent)

# Название проекта
project(Lab_17_dop)

# Скачиваем библиотеку
FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
)

# Добавляем библиотеку
FetchContent_MakeAvailable(json)

# Создает исполняемый файл
add_executable(Lab_17_dop main.cpp)

# Линковка программы с библиотекой
target_link_libraries(Lab_17_dop PRIVATE nlohmann_json::nlohmann_json)