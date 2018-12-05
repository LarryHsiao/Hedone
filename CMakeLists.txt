cmake_minimum_required(VERSION 3.12)
project(Hedone)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

include(GoogleTest)
include(CTest)
enable_testing()
set(BUILD_TESTING ON)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(Hedone src/main.cpp)
target_link_libraries(Hedone ${wxWidgets_LIBRARIES})

set(SOURCE_UNIT_TEST test/GeneralTest.cpp test/edge/JsonTest.cpp test/edge/CurlTest.cpp)
add_executable(UnitTest ${SOURCE_UNIT_TEST})
target_link_libraries(UnitTest ${CMAKE_SOURCE_DIR}/cget/lib/libgtest.so)
target_link_libraries(UnitTest ${CMAKE_SOURCE_DIR}/cget/lib/libgtest_main.so)
target_link_libraries(UnitTest ${CMAKE_SOURCE_DIR}/cget/lib/libcurl.so)


GTEST_ADD_TESTS(UnitTest "${FooTestArgs}" AUTO)