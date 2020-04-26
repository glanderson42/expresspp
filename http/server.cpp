//
// Created by Mark Vass on 2020. 04. 19..
//

#include "server.hpp"

#include <iostream>
#include <functional>


http::server::server::server() {
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket init failed" << std::endl;
        std::exit(-1);
    }
}

