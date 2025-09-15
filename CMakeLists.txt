# CMakeLists.txt para o projeto TODO
cmake_minimum_required(VERSION 3.10)
project(TODO)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)
file(GLOB SOURCES "src/*.cpp" "src/models/*.cpp" "src/controllers/*.cpp" "src/views/*.cpp" "src/utils/*.cpp")
add_executable(todo ${SOURCES})
