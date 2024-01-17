set(APP_NAME "app")

add_executable(${APP_NAME} main.cpp func.cpp)

target_include_directories(${APP_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PRIVATE ${Boost_LIBRARIES})

target_include_directories(${APP_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PRIVATE ${OpenCV_LIBRARIES})

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${APP_NAME} PROPERTY CXX_CPPCHECK cppcheck --std=c++20 --quiet --enable=all --suppress=missingIncludeSystem:* --config-exclude=${CMAKE_SOURCE_DIR}/extern)
