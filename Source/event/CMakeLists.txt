add_library(game_event STATIC
    EventManager.cpp
)

target_include_directories(game_event PRIVATE
    ${PROJECT_ROOT_DIR}/Source/game/
    ${PROJECT_ROOT_DIR}/Source/event/
    ${PROJECT_ROOT_DIR}/Source/database/
    ${CMAKE_CURRENT_LIST_DIR}
    ${SQLITE_ROOT_DIR}
    ${OPENSRC_ROOT_DIR}
)

target_link_libraries(game_event PUBLIC
    game_basic
    game_db
)