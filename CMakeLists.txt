# CMakeList.txt : CMake project for Pong, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Pong")

set(SDL2_DIR "${CMAKE_SOURCE_DIR}/lib/SDL2-2.24.1/cmake")
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories("lib")

file(CREATE_LINK "${PROJECT_SOURCE_DIR}/fonts" "${CMAKE_BINARY_DIR}/fonts" SYMBOLIC)
file(CREATE_LINK "${PROJECT_SOURCE_DIR}/images" "${CMAKE_BINARY_DIR}/images" SYMBOLIC)
file(CREATE_LINK "${PROJECT_SOURCE_DIR}/res" "${CMAKE_BINARY_DIR}/res" SYMBOLIC)

file(GLOB Pong_src "src/*.h" "src/*.cpp")

add_executable(Pong ${Pong_src})
target_link_libraries(Pong ${SDL2_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pong PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
