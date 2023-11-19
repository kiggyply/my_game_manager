add_library(gamedb SHARED database.cpp)

target_include_directories(gamedb PRIVATE
    ${OPEN_SOURCE_DIR}
)

target_link_directories(gamedb PRIVATE
    ${CMAKE_INSTALL_PREFIX}
)

target_link_libraries(gamedb PRIVATE
    sqlite3
)

# install(TARGETS gamedb LIBRARY ${CMAKE_INSTALL_PREFIX})

# 指定安装目录，安装到 CMake 的 install prefix
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/libgamedb.dll"
        DESTINATION ${CMAKE_INSTALL_PREFIX}
)