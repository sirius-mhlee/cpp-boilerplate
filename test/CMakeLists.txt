add_executable(test1 test1.cpp ../app/func.cpp)
target_compile_options(test1 PRIVATE -g -O0 -fprofile-arcs -ftest-coverage)
target_link_libraries(test1 gtest gmock gmock_main gcov)

set_property(TARGET test1 PROPERTY CXX_STANDARD 20)
set_property(TARGET test1 PROPERTY CXX_STANDARD_REQUIRED ON)

add_custom_target(test1_cov
    COMMAND lcov --rc lcov_branch_coverage=1 -c -d . -o tmp.info
    COMMAND lcov --rc lcov_branch_coverage=1 --remove tmp.info '/usr/include/*' '*/extern/*' -o test1.info
    COMMAND genhtml test1.info --branch-coverage -o report
    COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/coverage/test1
    COMMAND mv report/* ${CMAKE_SOURCE_DIR}/coverage/test1)
