cmake_minimum_required(VERSION 3.11)
include(FetchContent)

# Название проекта
project(Lab_17_dop)

# Отображаем процесс скачивания библиотеки
set(FETCHCONTENT_QUIET OFF)

# Скачиваем библиотеку
FetchContent_Declare(json
    URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP 0
)

# Добавляем библиотеку
FetchContent_MakeAvailable(json)

# Создает исполняемый файл
add_executable(Lab_17_dop main.cpp)

# Линковка программы с библиотекой
target_link_libraries(Lab_17_dop PRIVATE nlohmann_json::nlohmann_json)