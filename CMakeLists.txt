cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# Name the project
project(Radon)

list(APPEND CMAKE_PREFIX_PATH ${PROJECT_SOURCE_DIR}/dep/wxWidgets-build)

# Request the required wxWidgets libs
find_package(wxWidgets 3.1 COMPONENTS core base richtext adv html xml REQUIRED)

set(wxUSE_PRIVATE_FONTS ON)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

# Define a variable containing a list of source files for the project
set(SRC_FILES
        src/Main.cpp
        src/App.cpp
        src/Main.h
        src/App.h
        )

# Define the build target for the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})