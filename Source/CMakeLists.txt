add_subdirectory(game)
add_subdirectory(database)
add_subdirectory(event)

add_executable(game_run main.cpp)

target_include_directories(game_run PRIVATE 
    ${PROJECT_ROOT_DIR}/Source/game/
    ${PROJECT_ROOT_DIR}/Source/event/
    ${PROJECT_ROOT_DIR}/Source/database/
    ${CMAKE_CURRENT_LIST_DIR}
    ${SQLITE_ROOT_DIR}    
    ${OPENSRC_ROOT_DIR}
)

target_link_libraries(game_run PRIVATE
    game_basic
    game_db
    game_event
    # ${sqlite3}
)

add_dependencies(game_run game_event)