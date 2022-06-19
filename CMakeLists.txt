cmake_minimum_required(VERSION 3.0.0)
project(cpp-boilerplate VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(extern/googletest-1.11.0)

add_subdirectory(test)
add_test(test1 test/test1)

add_subdirectory(app)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
