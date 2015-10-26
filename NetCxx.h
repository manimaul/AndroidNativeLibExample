//
// Created by William Kamp on 10/25/15.
//

#ifndef ANDROIDNATIVELIBEXAMPLE_NETCXX_H
#define ANDROIDNATIVELIBEXAMPLE_NETCXX_H

#include <string>

class NetCxx {

public:

    struct Response {
        std::string body;
        std::string error;
        long response_code;
    };

    NetCxx();

    NetCxx::Response get(std::string url);
    NetCxx::Response post(std::string url, std::string body);

    virtual ~NetCxx();

};


#endif //ANDROIDNATIVELIBEXAMPLE_NETCXX_H
