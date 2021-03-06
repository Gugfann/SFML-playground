#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)


# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(basics)

# Set version information in a config.h file
set(cmake_project_VERSION_MAJOR 1)
set(cmake_project_VERSION_MINOR 0)

include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
#set(EXECUTABLE_NAME "game")

#file(GLOB PROJECT_EXTRA "*.jpg" "*.png" "*.bmp")
#file(GLOB PROJECT_SOURCES "src/*.cpp")
file(GLOB PROJECT_HEADERS "include/*.h")

#add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_EXTRA})

add_executable(red_box src/red_box.cpp ${PROJECT_HEADERS})
add_executable(texture src/texture.cpp ${PROJECT_HEADERS})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(red_box ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
  target_link_libraries(texture ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# # Install target
# install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
