//
// Created by Mark Vass on 2020. 04. 19..
//

#ifndef HTTP_CONNECTION_TYPE_HPP
#define HTTP_CONNECTION_TYPE_HPP

namespace http::utils::request {

enum connection_type {
    KEEP_ALIVE,
    CLOSED,
};

}

#endif //HTTP_CONNECTION_TYPE_HPP
