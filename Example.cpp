//
// Created by William Kamp on 10/22/15.
//

#include "Example.h"
#include <boost/format.hpp>

using namespace std;

const char* Example::getVersion() {
    const char *version = "0.1";
    string v = str(boost::format("example version: %1%") % version).c_str();
    return v.c_str();
}
