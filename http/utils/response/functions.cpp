//
// Created by Mark Vass on 2020. 04. 26..
//

#include "functions.hpp"
#include "status_code.hpp"
#include "content_types.hpp"
#include "../http_version.hpp"

using informational_resposne = http::utils::response::status_code::informational_response;
using success = http::utils::response::status_code::success;
using redirection = http::utils::response::status_code::redirection;
using client_errors = http::utils::response::status_code::client_errors;
using server_erros = http::utils::response::status_code::server_errors;

std::string http::utils::response::get_status_code_string(int c) {
    switch(c) {
        case informational_resposne::CONTINUE: {
            return "Continue";
        }
        case informational_resposne::SWITCHING_PROTOCOLS: {
            return "Switching Protocols";
        }
        case informational_resposne::PROCESSING: {
            return "Processing";
        }
        case informational_resposne::EARLY_HINTS: {
            return "Early Hints";
        }
        case success::OK: {
            return "OK";
        }
        case success::CREATED: {
            return "Created";
        }
        case success::ACCEPTED: {
            return "Accepted";
        }
        case success::NON_AUTHORITATIVE_INFORMATION: {
            return "Non Authoritative Information";
        }
        case success::NO_CONTENT: {
            return "No Content";
        }
        case success::RESET_CONTENT: {
            return "Reset Content";
        }
        case success::PARTIAL_CONTENT: {
            return "Partial Content";
        }
        case success::MULTI_STATUS: {
            return "Multi Status";
        }
        case success::ALREADY_REPORTED: {
            return "Already Reported";
        }
        case success::IM_USED: {
            return "I'm used";
        }
        default:
            return "ERROR";

    }
}

using application = http::utils::response::content_types::application;
using audio = http::utils::response::content_types::audio;

std::string http::utils::response::get_content_type_string(int c) {
    switch(c) {
        case application::JSON: {
            return "application/json";
        }
        default:
            return "ERROR";
    }
}

std::string http::utils::response::get_http_version_string(int c) {
    switch(c) {
        case http::utils::http_version::HTTP_1_0: {
            return "HTTP/1.0";
        }
        case http::utils::http_version::HTTP_1_1: {
            return "HTTP/1.1";
        }
        case http::utils::http_version::HTTP_2_0: {
            return "HTTP/2.0";
        }
        default:
            return "ERROR";
    }
}
