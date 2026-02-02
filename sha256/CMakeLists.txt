cmake_minimum_required(VERSION 4.1)
project(sha256)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/jyh/Qt/6.10.2/macos")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(sha256 main.cpp)
target_link_libraries(sha256
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

