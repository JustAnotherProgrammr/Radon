cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(Radon LANGUAGES CXX)

list(APPEND CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/dep/wxWidgets-build)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(wxWidgets_USE_STATIC 1)

find_package(wxWidgets 3.1 COMPONENTS core base richtext adv html xml REQUIRED)

set(wxUSE_PRIVATE_FONTS ON)

include(${wxWidgets_USE_FILE})

set(SRC_FILES
        src/Main.cpp
        src/App.cpp
        src/Main.h
        src/App.h
        )

if (APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SRC_FILES})
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
endif()

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})