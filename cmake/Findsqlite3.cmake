set(SQLITE3_DLL_PATH ${SQLITE_ROOT_DIR}/sqlite3.dll)

if (EXISTS ${SQLITE3_DLL_PATH})
    set(SQLITE3_FOUND TRUE)
    set(SQLITE3_LIBRARY ${SQLITE3_DLL_PATH})
else()
    set(SQLITE3_FOUND FALSE)
endif()

# 如果找到 sqlite3.dll，你可以将它链接到你的目标
if (SQLITE3_FOUND)
    message(STATUS "Found sqlite3.dll: ${SQLITE3_LIBRARY}")
    # 添加你的DLL库
    set(sqlite3 ${SQLITE3_DLL_PATH})

else()
    message(STATUS "sqlite3.dll not found.")
endif()