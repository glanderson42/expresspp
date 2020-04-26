//
// Created by Mark Vass on 2020. 04. 19..
//

#ifndef WEBSERVER_REQUEST_HPP
#define WEBSERVER_REQUEST_HPP

#include <string>
#include <iostream>

#include "request_type.hpp"
#include "connection_type.hpp"

namespace http::utils::request {

class request {
private:
    request_type type;
    connection_type connection;
    std::string url;
public:
    request(request_type type, connection_type connection, std::string&& url);
    request_type get_request_type();
    connection_type get_connection();
    std::string get_url();
};

}

#endif //WEBSERVER_REQUEST_HPP
