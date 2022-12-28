cmake_minimum_required(VERSION 3.12)

include(FetchContent)

# Название проекта
project(Lab_17_dop)

# Отображает сообщение
message(STATUS "Downloading json")

# Отображает прогресс скачивания
set(FETCHCONTENT_QUIET OFF)

# Скачивает библиотеку
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)

# Устанавливает библиотеку
FetchContent_MakeAvailable(json)

# Отображает сообщение
message(STATUS "Downloading json done")

# Создает исполняемый файл
add_executable(Lab_17_dop main.cpp)

# Линковка программы с библиотекой
target_link_libraries(Lab_17_dop PRIVATE nlohmann_json::nlohmann_json)