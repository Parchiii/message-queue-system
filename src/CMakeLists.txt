
add_subdirectory(core)

add_executable(mq_server main.cpp)

target_link_libraries(mq_server PUBLIC ${CORE_LIBRARY})
