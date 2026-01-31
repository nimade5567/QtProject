cmake_minimum_required(VERSION 4.1)
project(server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/jyh/Qt/6.10.1/macos")

find_package(Qt6 COMPONENTS
        Core
        Network
        REQUIRED)

add_executable(server main.cpp)
target_link_libraries(server
        Qt::Core
        Qt::Network
)
configure_file(server.crt ${CMAKE_BINARY_DIR}/server.crt COPYONLY)
configure_file(server.key ${CMAKE_BINARY_DIR}/server.key COPYONLY)

