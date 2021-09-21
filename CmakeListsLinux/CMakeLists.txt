cmake_minimum_required(VERSION 2.8)
project(MyLogViewer LANGUAGES CXX)
set(CMAKE_CXXSTANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(MyLogViewer appwindow.cpp logitem.cpp main.cpp mainwindow.cpp mainwindow.ui)
target_link_libraries(MyLogViewer PRIVATE Qt5::Widgets)