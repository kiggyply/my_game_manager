add_library(user_shared STATIC userinfo.cpp)

add_dependencies(start user_shared)