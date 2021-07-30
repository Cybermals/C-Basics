#Minimum CMake version and policy settings
cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)

#Project Name
project(PswdProtHello)

#Add executable
add_executable(PswdProtHello)

#Add source code
target_sources(
    PswdProtHello
    PUBLIC
    src/main.c
)