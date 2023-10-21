cmake_minimum_required(VERSION 3.20.5)

set(CMAKE_C_COMPILER    "x86_64-w64-mingw32-gcc.exe")
set(CMAKE_CXX_COMPILER  "x86_64-w64-mingw32-g++.exe")

project(MGame)

get_filename_component(PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR} ABSOLUTE)         # 工程根目录
get_filename_component(OPENSRC_ROOT_DIR ${PROJECT_ROOT_DIR}/Opensource ABSOLUTE)    # 开源仓根目录
get_filename_component(SQLITE_ROOT_DIR ${OPENSRC_ROOT_DIR}/sqlite ABSOLUTE)         # sqlite根目录

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)  # 假设 Findsqlite.cmake 存在于 cmake 目录中
find_package(sqlite3 REQUIRED)

add_subdirectory(Source)