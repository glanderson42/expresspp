cmake_minimum_required(VERSION 3.15)
project(http)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(http/deps/json)
add_subdirectory(http/deps/fmt)


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
        http/utils/http_version.hpp
        http/utils/response/content_types.hpp http/utils/response/body_type.hpp http/utils/response/functions.cpp http/utils/response/functions.hpp)

add_library(http http/server.cpp http/server.hpp http/deps/json.hpp http/deps/fmt.hpp)
# target_link_libraries(http PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(http PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(http PRIVATE fmt::fmt-header-only)
target_link_libraries(http PRIVATE http_request_utils)
target_link_libraries(http PRIVATE http_response_utils)

add_executable(http_server main.cpp)

target_link_libraries(http_server http)