#Minimum CMake version and policy settings
cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)

#Project Name
project(PswdProtHello2)

#Add executable
add_executable(PswdProtHello2)

#Add source code
target_sources(
    PswdProtHello2
    PUBLIC
    src/main.c
)