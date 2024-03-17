cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_SHARED_MODULE_PREFIX "")

set(BUILD_TESTING OFF)

if(WIN32)
    set(CMAKE_CXX_COMPILER cl.exe)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out")
elseif(UNIX)
    set(CMAKE_CXX_COMPILER g++)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}")
endif()

project(sysx-server)

find_package(Boost 1.83 REQUIRED COMPONENTS system)


add_executable(sysx-server source/main.cpp)

target_link_directories(sysx-server PRIVATE source)

add_subdirectory(source)


message(STATUS "Boost libs: $ENV{OPENSSL_ROOT_DIR}")

target_link_libraries(sysx-server PRIVATE Boost::system)