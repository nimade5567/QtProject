cmake_minimum_required(VERSION 4.1)
project(mqtt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/jyh/Qt/6.10.1/macos")

find_package(Qt6 COMPONENTS
        Core
        Network
        Mqtt
        REQUIRED)

add_executable(mqtt main.cpp
        src/mqttclient.cpp
        include/mqttclient.h)
target_link_libraries(mqtt
        Qt::Core
        Qt::Network
        Qt::Mqtt
)

