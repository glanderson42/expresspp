//
// Created by Mark Vass on 2020. 04. 20..
//

#include <sys/socket.h>
#include "../../deps/fmt.hpp"
#include "response.hpp"

http::utils::response::response::response(int soc) : socket(soc) {}

void http::utils::response::response::set_http_version(int http_ver) {
    this->version = http_ver;
}

void http::utils::response::response::set_status_code(int code) {
    this->status = code;
}

void http::utils::response::response::set_content_type(int content_type) {
    this->type = content_type;
}

void http::utils::response::response::set_body(body_type* response_body) {
    this->body = *response_body;
    if(dynamic_cast<std::string*>(response_body)) {
        std::string* tmp_body = response_body;
        this->content_length = tmp_body->size();
    } else if(dynamic_cast<nlohmann::json*>(response_body)) {
        nlohmann::json* json_body = response_body;
        this->content_length = json_body->size();
    }
}

void http::utils::response::response::send(body_type* content_body) {
    std::string response = fmt::format("{}", "asd");
    ::send(socket, body.c_str(), strlen(body.c_str()), 0);
}