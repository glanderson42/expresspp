//
// Created by Mark Vass on 2020. 04. 26..
//

#ifndef HTTP_BODY_TYPE_HPP
#define HTTP_BODY_TYPE_HPP

#include "../../deps/json.hpp"

namespace http::utils::response {
struct body_type
        : public nlohmann::json
        , public std::string
        {};
}

#endif //HTTP_BODY_TYPE_HPP
