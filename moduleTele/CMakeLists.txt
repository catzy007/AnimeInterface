cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(moduleTele VERSION 1.0 LANGUAGES CXX)

find_package(Td 1.3.0 REQUIRED)

add_executable(moduleTele moduleTele.cpp)
target_link_libraries(moduleTele PRIVATE Td::TdStatic)
set_property(TARGET moduleTele PROPERTY CXX_STANDARD 14)
