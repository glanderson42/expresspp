//
// Created by Mark Vass on 2020. 04. 19..
//

#include <vector>

#include "functions.hpp"
#include "request_type.hpp"
#include "request.hpp"
#include "connection_type.hpp"

http::utils::request::request http::utils::request::request_parser(char* raw_buffer) {
    std::string buffer { raw_buffer };
    std::vector<std::string> parts;
    split(buffer, parts, ' ');
    request_type type = get_type(parts[0]);
    std::string url = parts[1];
    connection_type connection;
    int counter = 0;
    for(std::string& part : parts) {
        if(part == "Connection") {
            connection = get_connection_type(parts[counter + 1]);
        }
        ++counter;
    }

    return request(type, connection, std::move(url));
}

size_t http::utils::request::split(const std::string& buffer, std::vector<std::string>& strings, char ch) {
    size_t pos = buffer.find( ch );
    size_t initialPos = 0;
    strings.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strings.push_back( buffer.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = buffer.find( ch, initialPos );
    }

    // Add the last one
    strings.push_back( buffer.substr( initialPos, std::min( pos, buffer.size() ) - initialPos + 1 ) );

    return strings.size();
}

http::utils::request::request_type http::utils::request::get_type(const std::string& sw) {
    if(sw.starts_with("GET")) {
        return request_type::GET;
    } else if(sw.starts_with("HEAD")) {
        return request_type::HEAD;
    } else if(sw.starts_with("POST")) {
        return request_type::POST;
    } else if(sw.starts_with("PUT")) {
        return request_type::PUT;
    } else if(sw.starts_with("DELETE")) {
        return request_type::DELETE;
    } else if(sw.starts_with("TRACE")) {
        return request_type::TRACE;
    } else if(sw.starts_with("OPTIONS")) {
        return request_type::OPTIONS;
    } else if(sw.starts_with("CONNECT")) {
        return request_type::CONNECT;
    } else if(sw.starts_with("PATCH")) {
        return request_type::PATCH;
    } else {
        return request_type::UNKNOWN;
    }
}

http::utils::request::connection_type http::utils::request::get_connection_type(const std::string& str) {
    if(str == "keep-alive") {
        return http::utils::request::connection_type::KEEP_ALIVE;
    } else {
        return http::utils::request::connection_type::CLOSED;
    }
}