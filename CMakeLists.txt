cmake_minimum_required(VERSION 3.19)
project(Simple VERSION 1.0.0 LANGUAGES CXX)

set(QT_VERSION 5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(REQUIRED_LIBS Core Gui Widgets Qml Quick QuickControls2)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Qml Qt5::Quick Qt5::QuickControls2)

include_directories(include/library)
add_subdirectory(library)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
add_executable(${PROJECT_NAME} main.cpp qml.qrc)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} Tools)