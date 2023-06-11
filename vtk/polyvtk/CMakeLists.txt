cmake_minimum_required(VERSION 3.8)
project(polyvtk)

# Find the VTK package
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})


# Add your source code file(s) to the project
add_executable(polyvtk main.cpp)

# Link against the VTK libraries
target_link_libraries(polyvtk ${VTK_LIBRARIES})

set(CMAKE_GENERATOR "Ninja")
