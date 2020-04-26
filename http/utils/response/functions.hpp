//
// Created by Mark Vass on 2020. 04. 26..
//

#ifndef HTTP_FUNCTIONS_HPP
#define HTTP_FUNCTIONS_HPP

#include <string>

namespace http::utils::response {

std::string get_content_type_string(int);
std::string get_status_code_string(int);
std::string get_http_version_string(int);

}
#endif //HTTP_FUNCTIONS_HPP
