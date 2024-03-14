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


add_executable(sysx-server source/main.cpp)
add_subdirectory(extlibs)

target_link_libraries(sysx-server PRIVATE boost_asio)
