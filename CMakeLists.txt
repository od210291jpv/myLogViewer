cmake_minimum_required(VERSION 2.8.11)
project(MyLogViewer LANGUAGES CXX)
set (CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.12.0\\5.12.0\\msvc2017_64\\")

set(CMAKE_CXXSTANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED Widgets)


add_executable(MyLogViewer appwindow.cpp logitem.cpp main.cpp mainwindow.cpp mainwindow.ui)
target_link_libraries(MyLogViewer PRIVATE Qt5::Widgets)