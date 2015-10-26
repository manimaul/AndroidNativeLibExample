//
// Created by William Kamp on 10/25/15.
//

#include "NetCxx.h"

#include <curl/curl.h>

// libcurl with C++ http://curl.haxx.se/libcurl/c/libcurl-tutorial.html#HTTP
// The callbacks CANNOT be non-static class member functions
static size_t WriteMemoryCallback(char *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    auto mem = reinterpret_cast<NetCxx::Response*>(userp);
    mem->body.assign(contents);
    return realsize;
}

NetCxx::NetCxx() {
    curl_global_init(CURL_GLOBAL_SSL);
}

NetCxx::Response NetCxx::get(std::string url) {
    CURL *curl_handle;
    CURLcode res;

    NetCxx::Response chunk;

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* specify URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

    /* we pass our 'chunk' struct to the callback function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

    /* some servers don't like requests that are made without a user-agent
       field, so we provide one */
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    /* get it! */
    res = curl_easy_perform(curl_handle);

    /* get the response code */
    curl_easy_getinfo (curl_handle, CURLINFO_RESPONSE_CODE, &chunk.response_code);

    /* check for errors */
    if(res != CURLE_OK) {
        chunk.error.assign(curl_easy_strerror(res));
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    return chunk;
}

NetCxx::Response NetCxx::post(std::string url, std::string body) {
    CURL *curl_handle;
    CURLcode res;

    NetCxx::Response chunk;

    /* init the curl session */
    curl_handle = curl_easy_init();

    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    /* specify URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());

    /* post binary data */
    curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, body.c_str());

    /* set the size of the postfields data */
    curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDSIZE, body.size());

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

    /* we pass our 'chunk' struct to the callback function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

    /* pass our list of custom made headers */
    curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);

    res = curl_easy_perform(curl_handle); /* post away! */

    /* get the response code */
    curl_easy_getinfo (curl_handle, CURLINFO_RESPONSE_CODE, &chunk.response_code);

    curl_slist_free_all(headers); /* free the header list */

    /* check for errors */
    if(res != CURLE_OK) {
        chunk.error.assign(curl_easy_strerror(res));
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    return chunk;
}

NetCxx::~NetCxx() {
    /* we're done with libcurl, so clean it up */
    curl_global_cleanup();
}
