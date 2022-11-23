cmake_minimum_required(VERSION 3.21)
project(LTColor)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LTColor main.cpp MainWidget.cpp MainWidget.h MainWidget.ui ColorDesktop.cpp ColorDesktop.h ColorDesktop.ui DetailWidget.cpp DetailWidget.h DetailWidget.ui)
target_link_libraries(LTColor
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

