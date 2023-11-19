add_library(game_db_shared SHARED database.cpp)

target_include_directories(game_db_shared PRIVATE
    ${OPEN_SOURCE_DIR}
)

target_link_directories(game_db_shared PRIVATE
    ${CMAKE_INSTALL_PREFIX}
)

target_link_libraries(game_db_shared PRIVATE
    sqlite3
)

# install(TARGETS game_db_shared LIBRARY ${CMAKE_INSTALL_PREFIX})

# 指定安装目录，安装到 CMake 的 install prefix
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/libgame_db_shared.dll"
        DESTINATION ${CMAKE_INSTALL_PREFIX}
)