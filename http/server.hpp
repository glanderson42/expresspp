//
// Created by Mark Vass on 2020. 04. 19..
//

#ifndef WEBSERVER_WEBSERVER_HPP
#define WEBSERVER_WEBSERVER_HPP

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

#include "utils/request/request.hpp"
#include "utils/request/functions.hpp"

namespace http::server {

class server {
private:
    int server_fd;
    int new_socket;
    int opt;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

public:
    explicit server();

    template <class Functor>
    void listen(int port, Functor func = nullptr);
};

}

template <class Functor>
void http::server::server::listen(int port, Functor func) {
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        std::cerr << "Set sockopt failed" << std::endl;
        std::exit(-1);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if(bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Binding failed" << std::endl;
        std::exit(-1);
    }

    if(::listen(server_fd, 3) < 0) {
        std::cerr << "Server can not listening" << std::endl;
        std::exit(-1);
    }


    func();


    std::string asd  = "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-length: 13\r\n\r\n{\"asd\":\"asd\"}";

    while(true) {
        if((new_socket = accept(server_fd,
                                (struct sockaddr*)&address,(socklen_t*)&addrlen)) < 0) {
            std::cerr << "Accept failed" << std::endl;
            std::exit(-1);
        }

        // char buffer[1024];
        char* buffer = new char[30 * 1024];
        read(new_socket, buffer, 1024);
        std::printf("%s", buffer);
        std::string buff { buffer };
        http::utils::request::request req = http::utils::request::request_parser(buffer);

        if(buff.find("GET /asd") != std::string::npos) {
            send(new_socket, asd.c_str(), strlen(asd.c_str()), 0);
        } else {

        }
        delete[] buffer;
    }
}

#endif //WEBSERVER_WEBSERVER_HPP
