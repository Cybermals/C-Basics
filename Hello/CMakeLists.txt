#Minimum CMake version and policy settings
cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)

#Project Name
project(Hello)

#Add executable
add_executable(Hello)

#Add source code
target_sources(
    Hello
    PUBLIC
    src/main.c
)