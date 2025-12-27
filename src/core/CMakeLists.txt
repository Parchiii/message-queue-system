set(SOURCES
    ./implementation/Message.cpp
    ./implementation/MessageQueue.cpp
    ./implementation/QueueManager.cpp)
set(HEADERS
    ./include/Message.h
    ./include/MessageQueue.h
    ./include/QueueManager.h)

add_library(${CORE_LIBRARY} STATIC
    ${HEADERS}
    ${SOURCES}
)
target_include_directories(${CORE_LIBRARY} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
