cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(aiface VERSION 1.0 LANGUAGES CXX)

find_package(Td 1.3.0 REQUIRED)

add_executable(aiface aiface.cpp)
target_link_libraries(aiface PRIVATE Td::TdStatic)
set_property(TARGET aiface PROPERTY CXX_STANDARD 14)
