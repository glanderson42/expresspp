//
// Created by Mark Vass on 2020. 04. 20..
//

#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <string>

#include "content_types.hpp"
#include "status_code.hpp"
#include "../http_version.hpp"
#include "body_type.hpp"

namespace http::utils::response {

class response {
private:
    int version = http_version::HTTP_1_1;
    int status = status_code::success::OK;
    int type = -1;
    int content_length = 0;
    int socket;
    body_type body;

public:
    response() = default;
    explicit response(int soc);
    void set_http_version(int);
    void set_status_code(int);
    void set_content_type(int);
    void set_body(body_type*);
    void send(body_type* content_body = nullptr);
};

}

#endif //HTTP_RESPONSE_HPP
