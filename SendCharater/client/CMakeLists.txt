cmake_minimum_required(VERSION 4.1)
project(client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/jyh/Qt/6.10.1/macos")

find_package(Qt6 COMPONENTS
        Core
        Network
        REQUIRED)

add_executable(client main.cpp
        src/tcpSocket.cpp
        include/tcpSocket.h)
target_link_libraries(client
        Qt::Core
        Qt::Network
)

