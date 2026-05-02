cmake_minimum_required(VERSION 3.10)
project(ImageCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(OpenCV REQUIRED)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/aritmethic-operations.cpp
    src/logic-operations.cpp
    src/transformations.cpp
)

add_executable(app ${SOURCES})

target_link_libraries(app 
    Qt6::Widgets
    ${OpenCV_LIBS}
)
