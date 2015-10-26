#include <iostream>
#include "Example.h"
#include "NetCxx.h"

using namespace std;

int main() {
    Example example;
    cout << example.getVersion() << endl;
    NetCxx net;
    auto response = net.get("http://example.com");
    cout << "Response code: " << response.response_code << endl;
    cout << "Response body: " << response.body << endl;
    cout << "Response error: " << response.error << endl;

    response = net.post("http://example.com/login", "{\"user_name\":\"user\",\"password\":\"pass\"}");
    cout << "Response code: " << response.response_code << endl;
    cout << "Response body: " << response.body << endl;
    cout << "Response error: " << response.error << endl;

    return 0;
}