#define _WIN32_WINNT 0x0A00

#pragma once
#include "httplib.h"
#include "json.hpp"


void displayAstronauts(httplib::Client& cli);
void displayLocation(httplib::Client& cli);
