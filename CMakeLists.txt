cmake_minimum_required(VERSION 3.25.1)

project(A3A_PRICE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#allow for paths defined by users
if(DEFINED ${QT_PATH_DIR})
	set(CMAKE_PREFIX_PATH ${QT_PATH_DIR})
else()
	set(CMAKE_PREFIX_PATH "C:/Qt/6.4.2/msvc2019_64/")
endif()

#packages here
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Widgets) 
qt_standard_project_setup()

add_executable(A3A_PRICE src/main.cpp "src/test.cpp" "src/clipboard/clipboard.cpp" "src/list/list.cpp" "src/mainwindow/mainwindow.cpp" "src/priceselector/priceselector.cpp")

target_link_libraries(A3A_PRICE PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
