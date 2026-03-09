cmake_minimum_required(VERSION 3.21)

project(Vexora LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

find_package(spdlog CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

include_directories(include)

add_executable(vexora
    src/main.cpp
)

add_executable(vexora_tests
    tests/sample_test.cpp
)

target_link_libraries(vexora_tests
    PRIVATE
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME vexora_tests COMMAND vexora_tests)

target_link_libraries(vexora PRIVATE spdlog::spdlog)

enable_testing()