cmake_minimum_required(VERSION 3.19)
project(Simple VERSION 1.0.0 LANGUAGES CXX)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set(QT_VERSION 5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CONFIG_RC Simple.rc)
set_property(SOURCE Simple.rc APPEND PROPERTY
        OBJECT_DEPENDS ${PROJECT_SOURCE_DIR}/res/favicon.ico
        )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(REQUIRED_LIBS Core Network Gui Qml Quick QuickControls2)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Network Qt5::Gui Qt5::Qml Qt5::Quick Qt5::QuickControls2 spdlog::spdlog)

include(cmake/Dependencies.cmake)
include(cmake/FetchSpdlog.cmake)
include_directories(library/include)
include_directories(src/include)
add_subdirectory(library)
add_subdirectory(src)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
add_executable(${PROJECT_NAME} src/main.cpp res/qml.qrc ${CONFIG_RC})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} Library Source)