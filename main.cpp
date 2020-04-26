// Server side C/C++ program to demonstrate Socket programming
#include <cstdio>

#include "http/server.hpp"

int main([[maybe_unused]]int argc, [[maybe_unused]]char const *argv[])
{
    http::server::server server;
    int PORT = 4000;
    server.listen(PORT, [PORT]() {
        std::printf("Server is started on port: %d\n", PORT);
    });
    return 0;
}
