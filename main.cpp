#include <cstdio>
#include <memory>

#include "http/server.hpp"

int main([[maybe_unused]]int argc, [[maybe_unused]]char const *argv[])
{
    http::server::server server;
    int PORT = 4000;
    server.use("/asd", [](http::utils::request::request req, http::utils::response::response res) {
        //nlohmann::json* res_json = new nlohmann::json();
        //std::shared_ptr<nlohmann::json> res_json = std::make_shared<nlohmann::json>();
        nlohmann::json res_json;
        res_json["response"] = "works";
        res.send(static_cast<http::utils::response::body_type*>(&res_json));

    });
    server.listen(PORT, [PORT]() {
        std::printf("Server is started on port: %d\n", PORT);
    });
    return 0;
}
