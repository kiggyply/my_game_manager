add_library(event_static STATIC evenmanager.cpp fileutils.cpp)

target_include_directories(event_static PRIVATE
    ${SOURCE_ROOT_DIR}/user
    ${SOURCE_ROOT_DIR}/db
    ${OPEN_SOURCE_DIR}
)

target_link_libraries(event_static PRIVATE
    gamedb
    user_shared
)

add_dependencies(event_static user_shared user_shared)