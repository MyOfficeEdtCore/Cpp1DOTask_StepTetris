cmake_minimum_required (VERSION 3.1)

project (steptetris)

set (CMAKE_CXX_STANDARD 14)

file(GLOB HEADER_FILES *.hpp)
file(GLOB SOURCE_FILES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

