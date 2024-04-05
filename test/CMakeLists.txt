set(TEST_NAME "test1")

add_executable(${TEST_NAME} ${TEST_NAME}.cpp ../app/func.cpp)

target_include_directories(${TEST_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${TEST_NAME} PRIVATE ${Boost_LIBRARIES})

target_include_directories(${TEST_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${TEST_NAME} PRIVATE ${OpenCV_LIBRARIES})

target_compile_options(${TEST_NAME} PRIVATE -g -O0 -fprofile-arcs -ftest-coverage)
target_link_libraries(${TEST_NAME} PRIVATE gtest gmock gmock_main gcov)

set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

add_custom_target(${TEST_NAME}_cov
    COMMAND mkdir -p report/${TEST_NAME}
    COMMAND gcovr --root ${CMAKE_SOURCE_DIR} --html-nested report/${TEST_NAME}/coverage.html --exclude '${CMAKE_SOURCE_DIR}/extern/' --exclude '${CMAKE_SOURCE_DIR}/test/' --exclude-throw-branches
    COMMAND rm -rf ${CMAKE_SOURCE_DIR}/coverage/${TEST_NAME}
    COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/coverage/${TEST_NAME}
    COMMAND mv report/${TEST_NAME}/* ${CMAKE_SOURCE_DIR}/coverage/${TEST_NAME}
    COMMAND rm -rf report/${TEST_NAME})
