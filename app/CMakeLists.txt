set(APP_NAME "app")

add_executable(${APP_NAME} main.cpp func.cpp)

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
