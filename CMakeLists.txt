cmake_minimum_required(VERSION 3.10)

project(graylog_sink LANGUAGES CXX)

include_directories(include)

add_library(graylog_sink src/graylog_sink.cpp)

find_package(spdlog REQUIRED)
target_link_libraries(graylog_sink PRIVATE spdlog::spdlog)

enable_testing()
add_executable(test_graylog_sink tests/test_graylog_sink.cpp)
target_link_libraries(test_graylog_sink PRIVATE graylog_sink spdlog::spdlog)
add_test(NAME SinkTests COMMAND test_graylog_sink)