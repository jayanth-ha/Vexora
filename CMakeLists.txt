cmake_minimum_required(VERSION 3.21)

project(Vexora LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

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
    src/ingestion/directory_scanner.cpp
    src/ingestion/document_loader.cpp
    src/ingestion/text_chunker.cpp
)

add_executable(vexora_tests
    tests/sample_test.cpp
)

target_include_directories(vexora PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(vexora_tests
    PRIVATE
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME vexora_tests COMMAND vexora_tests)

target_link_libraries(vexora PRIVATE spdlog::spdlog)

enable_testing()