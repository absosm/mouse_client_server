cmake_minimum_required(VERSION 3.12)
project (mouse C)

# Bring the headers, such as *.h into the project
include_directories(
    ${CMAKE_SOURCE_DIR}/head
)

# Appending to corresponding CMake variables:
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -s")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -s")
SET(CMAKE_EXE_LINKER_FLAGS  "-lwsock32")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_executable(client src/client.c)
add_executable(server src/server.c)

TARGET_LINK_LIBRARIES(client ${CMAKE_EXE_LINKER_FLAGS})
TARGET_LINK_LIBRARIES(server ${CMAKE_EXE_LINKER_FLAGS})