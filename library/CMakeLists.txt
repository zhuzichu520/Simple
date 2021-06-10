file(GLOB TOOLS "tools/*.cpp" “include/tools/*.h”)
file(GLOB BASE "base/*.cpp" "include/base/*.h")
file(GLOB FRAMELESS "frameless/*.cpp" "include/frameless/*.h")
file(GLOB HTTP "http/*.cpp" "include/http/*.h")

add_library(Library ${TOOLS} ${BASE} ${HTTP})
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(Library ${REQUIRED_LIBS_QUALIFIED} glog)