cmake_minimum_required(VERSION 3.25)
project(Game_of_Life)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Game_of_Life main.cpp statistics.cpp statistics.h statistics.ui cellmatrix.cpp cellmatrix.h cellmatrix.ui mainwindow.h)
target_link_libraries(Game_of_Life
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

