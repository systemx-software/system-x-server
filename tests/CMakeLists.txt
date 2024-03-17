enable_testing()
project(unit-tests)

include("${CMAKE_SOURCE_DIR}/cmake/SetupVcpkg.cmake")

vcpgk_install_not_found(gtest GTest)