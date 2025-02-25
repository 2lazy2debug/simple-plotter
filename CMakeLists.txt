cmake_minimum_required(VERSION 3.28)

# Set the project name and version
project(SimplePlotter VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Add the executable
add_executable(SimplePlotter.out src/main.cpp src/components/graph_components.hpp src/components/graph_components.cpp src/interpreter/lexer.hpp src/interpreter/lexer.cpp)

# Include directories
target_compile_features(SimplePlotter.out PRIVATE cxx_std_23)
target_link_libraries(SimplePlotter.out PRIVATE SFML::Graphics)

target_include_directories(SimplePlotter.out PRIVATE ${PROJECT_SOURCE_DIR}/include)
