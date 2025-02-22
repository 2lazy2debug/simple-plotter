cmake_minimum_required(VERSION 3.20)

# Set the project name and version
project(SimplePlotter VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(SimplePlotter main.cpp)

# Include directories
target_include_directories(SimplePlotter PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Link libraries (if any)
# target_link_libraries(SimplePlotter PRIVATE some_library)

# Add other necessary configurations below