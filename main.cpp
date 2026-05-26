#define _WIN32_WINNT 0x0A00

#include <iostream>
#include "httplib.h"
#include "json.hpp"

using json = nlohmann::json;

int main() {

    httplib::Client cli("http://api.open-notify.org");

    auto res = cli.Get("/astros.json");

    if (res && res->status == 200) {

        json data = json::parse(res->body);

        std::cout << "People currently in space:" << std::endl;
        for (auto& astronaut : data["people"]) {
            std::cout << astronaut["name"] << std::endl;
        }

    } else {
        std::cout << "Failed" << std::endl;
    }

    return 0;
}