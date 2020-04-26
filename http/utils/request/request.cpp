//
// Created by Mark Vass on 2020. 04. 19..
//

#include "request.hpp"

http::utils::request::request::request(
        request_type type,
        connection_type connection,
        std::string&& url
        )
    : type(type)
    , connection(connection)
    , url(url)
    {}