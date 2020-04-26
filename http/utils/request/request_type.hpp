//
// Created by Mark Vass on 2020. 04. 19..
//

#ifndef HTTP_REQUEST_TYPE_HPP
#define HTTP_REQUEST_TYPE_HPP

namespace http::utils::request {

enum request_type {
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    TRACE,
    OPTIONS,
    CONNECT,
    PATCH,
    UNKNOWN
};

}

#endif //HTTP_REQUEST_TYPE_HPP
