//
// Created by Mark Vass on 2020. 04. 19..
//

#ifndef HTTP_FUNCTIONS_HPP
#define HTTP_FUNCTIONS_HPP

#include <string>
#include <vector>

#include "request.hpp"
#include "request_type.hpp"
#include "connection_type.hpp"

namespace http::utils::request {

request request_parser(char* raw_buffer);
size_t split(const std::string& buffer, std::vector<std::string>& strings, char ch);
request_type get_type(const std::string& sw);
connection_type get_connection_type(const std::string& str);

}

#endif //HTTP_FUNCTIONS_HPP
