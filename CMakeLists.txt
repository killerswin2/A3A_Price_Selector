cmake_minimum_required(VERSION 3.25.1)

project(helloworld LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#packages here

set(CMAKE_PREFIX_PATH "C:/Qt/6.4.2/msvc2019_64/")
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Widgets) 
qt_standard_project_setup()

add_executable(helloworld src/main.cpp "src/test.cpp" "src/clipboard/clipboard.cpp" "src/list/list.cpp" "src/mainwindow/mainwindow.cpp" "src/priceselector/priceselector.cpp" )

target_link_libraries(helloworld PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
