cmake_minimum_required(VERSION 3.10)
project(App)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(OpenCV REQUIRED)
find_package(SDL2 REQUIRED)

add_executable(app ./src/main.cpp)

target_link_libraries(app 
    Qt6::Widgets
    ${OpenCV_LIBS}
    SDL2::SDL2
)