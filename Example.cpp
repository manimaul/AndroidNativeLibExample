//
// Created by William Kamp on 10/22/15.
//

#include "Example.h"

using namespace std;

std::string Example::getVersion() {
    std::string version = "0.1";
    std::string version_name = "example version: " + version;
    return version_name;
}
