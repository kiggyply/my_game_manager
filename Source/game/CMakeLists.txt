add_library(game_basic STATIC
    game_base.cpp
    specific_game.cpp
)

target_include_directories(game_basic PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)