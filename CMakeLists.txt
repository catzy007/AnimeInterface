cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(AnimeInterface VERSION 1.0)

# find tdlib, pkgconfig and gtk3
FIND_PACKAGE(Td 1.3.0 REQUIRED)
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# include GTK3 directory
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# define GTK3 flags
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# add executable
add_executable(moduleCore moduleCore.c)
add_executable(moduleBatmax moduleBatmax.c)
add_executable(moduleAiface moduleAiface.c)
add_executable(moduleTele moduleTele.cpp)

# link library and set property
TARGET_LINK_LIBRARIES(moduleAiface ${GTK3_LIBRARIES})
TARGET_LINK_LIBRARIES(moduleTele PRIVATE Td::TdStatic)
set_property(TARGET moduleTele PROPERTY CXX_STANDARD 14)
