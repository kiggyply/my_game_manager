add_executable(start main.cpp)

target_include_directories(start PRIVATE
    ${OPEN_SOURCE_DIR}
    ${SOURCE_ROOT_DIR}/event
    ${SOURCE_ROOT_DIR}/user
    ${SOURCE_ROOT_DIR}/db
)

add_subdirectory(user)
add_subdirectory(db)
add_subdirectory(event)

target_link_libraries(start PRIVATE
    event_static
)

install(TARGETS start DESTINATION ${CMAKE_INSTALL_PREFIX})

# 在构建目标中添加安装步骤
add_custom_target(install_my_targets
    COMMAND "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install
    DEPENDS
        start
        game_db_shared
        user_shared
        event_static
)