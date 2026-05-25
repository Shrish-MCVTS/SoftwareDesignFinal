#include <iostream>
#include "httplib.h"
#include "json.hpp"

using json = nlohmann::json;

int main() {

    httplib::Client cli("http://uselessfacts.jsph.pl/");

    auto res = cli.Get("/api/v2/facts/random");

    if (res && res->status == 200) {

        json data = json::parse(res->body);

        std::cout << "Random Fact" << std::endl;
        std::cout << data["text"] << std::endl;
        std::cout << data["source"] << std::endl;

    } else {
        std::cout << "Failed" << std::endl;
    }

    return 0;
}