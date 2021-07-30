#Minimum CMake version and policy settings
cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)

#Project Name
project(PswdProtHello4)

#Add executable
add_executable(PswdProtHello4)

#Add source code
target_sources(
    PswdProtHello4
    PUBLIC
    src/main.c
)

#Copy data files
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})