cmake_minimum_required(VERSION 3.15)
project(http)

set(CMAKE_CXX_STANDARD 20)


add_library(http_request_utils
        http/utils/request/request.cpp
        http/utils/request/request.hpp
        http/utils/request/request_type.hpp
        http/utils/request/connection_type.hpp
        http/utils/request/functions.cpp
        http/utils/request/functions.hpp
        http/utils/http_version.hpp)

add_library(http_response_utils
        http/utils/response/response.cpp
        http/utils/response/response.hpp
        http/utils/response/status_code.hpp
        http/utils/http_version.hpp http/utils/response/content_types.hpp)

add_library(http http/server.cpp http/server.hpp)
target_link_libraries(http http_request_utils http_response_utils)

add_executable(http_server main.cpp)

target_link_libraries(http_server http)