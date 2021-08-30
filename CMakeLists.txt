cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# Project name
project(Radon LANGUAGES CXX)

list(APPEND CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/vendor/wxWidgets-build)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Makes sure wxWidgets links statically
set(wxWidgets_USE_STATIC 1)

# All of these components are required
find_package(wxWidgets 3.1 COMPONENTS core base richtext adv html xml REQUIRED)

# Just to make sure private fonts is on
set(wxUSE_PRIVATE_FONTS ON)

# Include wxWidgets
include(${wxWidgets_USE_FILE})

# Radon debug option
if (RA_DEBUG)
    add_definitions(-DRA_DEBUG=1)
endif (RA_DEBUG)

# Set source files
set(SRC_FILES
        src/Main.cpp
        src/App.cpp
        src/Main.h
        src/App.h
        )

# Add executables and like them
if (APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SRC_FILES})
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
endif()

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})