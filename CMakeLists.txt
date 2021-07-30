#Minimum CMake version and policy settings
cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)

#Project Name
project(Basics)

#Include sub-projects
add_subdirectory(Hello)
add_subdirectory(Hello_)
add_subdirectory(PswdProtHello)
add_subdirectory(PswdProtHello2)
add_subdirectory(PswdProtHello3)
add_subdirectory(PswdProtHello4)