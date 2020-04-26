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

http::utils::request::request_type http::utils::request::request::get_request_type() {
    return this->type;
}

http::utils::request::connection_type http::utils::request::request::get_connection() {
    return this->connection;
}

std::string http::utils::request::request::get_url() {
    return this->url;
}