cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_SHARED_MODULE_PREFIX "")

include("cmake/SetupVcpkg.cmake")

vcpgk_install_not_found(sqlite3, unofficial-sqlite3)
vcpgk_install_not_found(boost-beast, Boost)


if(WIN32)
    set(CMAKE_CXX_COMPILER cl.exe)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out")
elseif(UNIX)
    set(CMAKE_CXX_COMPILER g++)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE}")
endif()

project(sysx-server)
add_executable(sysx-server source/main.cpp)
target_include_directories(sysx-server PRIVATE source)
add_subdirectory(source)

find_package(Boost)
target_link_libraries(sysx-server PRIVATE ${Boost_LIBRARIES})
target_include_directories(sysx-server PRIVATE ${Boost_INCLUDE_DIRS})

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(sysx-server PRIVATE unofficial::sqlite3::sqlite3)