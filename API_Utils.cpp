#define _WIN32_WINNT 0x0A00

#include <iostream>
#include "httplib.h"
#include "json.hpp"

using json = nlohmann::json;


void displayAstronauts(httplib::Client& cli){
    auto res = cli.Get("/astros.json");
        if (res && res->status == 200)
        {
            json data = json::parse(res->body);

            for (auto &astronaut : data["people"])
            {
                std::cout << "Name: " << astronaut["name"] << std::endl;
                std::cout << "Current Aircraft: " << astronaut["craft"] << std::endl;
            }
        }
        else
        {
            std::cout << "Failed" << std::endl;
        }
}

void displayLocation(httplib::Client& cli){
    auto res2 = cli.Get("/iss-now.json");
        if(res2 && res2->status == 200){
            json data2 = json::parse(res2->body);
            std::cout << "Current Position of the ISS: " << std::endl;
            std::cout << "  Latitude: " << data2["iss_position"]["latitude"] << std::endl;
            std::cout << "  Longitude: " << data2["iss_position"]["longitude"] << std::endl;
        }
        else
        {
            std::cout << "Failed" << std::endl;
        }
}