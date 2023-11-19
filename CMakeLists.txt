cmake_minimum_required(VERSION 3.20.5)

project(MY_GAME)

get_filename_component(PROJECT_ROOT_DIR     ${CMAKE_CURRENT_SOURCE_DIR}     ABSOLUTE) # 工程根目录
get_filename_component(CMAKE_INSTALL_PREFIX ${PROJECT_ROOT_DIR}             ABSOLUTE) # 二进制发布目录
get_filename_component(SOURCE_ROOT_DIR      ${PROJECT_ROOT_DIR}/Source      ABSOLUTE) # 项目源码目录
get_filename_component(OPEN_SOURCE_DIR      ${PROJECT_ROOT_DIR}/Open_src    ABSOLUTE) # 开源代码目录
get_filename_component(BINARY_SHARED_DIR    ${PROJECT_ROOT_DIR}/Binaries    ABSOLUTE) # 二进制目录

add_subdirectory(Source)