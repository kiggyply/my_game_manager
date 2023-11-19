add_library(event_static STATIC evenmanager.cpp)

target_include_directories(event_static PRIVATE
    ${SOURCE_ROOT_DIR}/user
    ${SOURCE_ROOT_DIR}/db
    ${OPEN_SOURCE_DIR}
)

target_link_libraries(event_static PRIVATE
    game_db_shared
    user_shared
)

add_dependencies(event_static user_shared user_shared)