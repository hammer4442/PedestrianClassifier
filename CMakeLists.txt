cmake_minimum_required(VERSION 3.16)
project(PedestrianClassifier LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(tinyxml2 REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(app
    src/main.cpp
    src/data_loader.cpp
    src/annotation_parser.cpp
)

target_include_directories(app PRIVATE include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(app PRIVATE tinyxml2::tinyxml2)
target_link_libraries(app PRIVATE ${OpenCV_LIBS})