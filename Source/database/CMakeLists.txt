add_library(game_db STATIC
    database.cpp
)

target_include_directories(game_db PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${SQLITE_ROOT_DIR}
)

target_link_libraries(game_db PUBLIC
    game_basic
    ${sqlite3}
)