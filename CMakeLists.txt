cmake_minimum_required (VERSION 2.8)

project(ColourRandomiser)

set(CMAKE_C_FLAGS_DEBUG "-O0")

find_package(Boost REQUIRED COMPONENTS system)


find_package(PkgConfig REQUIRED)
pkg_search_module(OPENCV REQUIRED opencv)
include_directories(${OPENCV_INCLUDE_DIRS})
link_directories(${OPENCV_LIBRARY_DIRS})
link_libraries( ${OPENCV_LIBRARIES} )
link_libraries( ${Boost_LIBRARIES} )

add_executable(colour-randomiser colour-randomiser.cpp)
install(TARGETS colour-randomiser RUNTIME DESTINATION bin)

