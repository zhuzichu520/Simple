file(GLOB LOGIN "login/*.cpp" “include/login/*.h”)
add_library(Source ${LOGIN})
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(Source ${REQUIRED_LIBS_QUALIFIED})