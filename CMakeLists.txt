cmake_minimum_required(VERSION 3.23)
project(GRAPHI)

set(CMAKE_CXX_STANDARD 14)

add_executable(GRAPHI main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(GRAPHI sfml-system sfml-window sfml-graphics sfml-audio)