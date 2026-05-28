#define _WIN32_WINNT 0x0A00

#include <iostream>
#include "httplib.h"
#include "json.hpp"
#include "API_Utils.h"

using json = nlohmann::json;



int main()
{

    std::string answer;

    httplib::Client cli("http://api.open-notify.org");

    std::cout << "Hello! Pick what information you want to recieve." << std::endl;
    std::cout << "  1. Names and location of all astronuats currently in space." << std::endl;
    std::cout << "  2. Current location of the ISS in terms of longitude and lattidude" << std::endl;
    std::cin >> answer;


    if (answer == "1")
    {
        displayAstronauts(cli);
    }
    else if (answer == "2")
    {
        displayLocation(cli);
    }
    else
    {
        std::cout << "Invalid Answer" << std::endl;
        return 0;
    }

    return 0;
}

