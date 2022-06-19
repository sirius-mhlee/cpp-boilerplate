set(TEST_NAME "test1")

add_executable(${TEST_NAME} ${TEST_NAME}.cpp ../app/func.cpp)
target_compile_options(${TEST_NAME} PRIVATE -g -O0 -fprofile-arcs -ftest-coverage)
target_link_libraries(${TEST_NAME} gtest gmock gmock_main gcov)

set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

add_custom_target(${TEST_NAME}_cov
    COMMAND lcov --rc lcov_branch_coverage=1 -c -d . -o tmp.info
    COMMAND lcov --rc lcov_branch_coverage=1 --remove tmp.info '/usr/include/*' '*/extern/*' -o ${TEST_NAME}.info
    COMMAND genhtml ${TEST_NAME}.info --branch-coverage -o report
    COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/coverage/${TEST_NAME}
    COMMAND mv report/* ${CMAKE_SOURCE_DIR}/coverage/${TEST_NAME})
