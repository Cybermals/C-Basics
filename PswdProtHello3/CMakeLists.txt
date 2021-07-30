#Minimum CMake version and policy settings
cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)

#Project Name
project(PswdProtHello3)

#Add executable
add_executable(PswdProtHello3)

#Add source code
target_sources(
    PswdProtHello3
    PUBLIC
    src/main.c
)