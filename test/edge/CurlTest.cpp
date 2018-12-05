//
// Created by larryhsiao on 12/7/18.
//

#include <gtest/gtest.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <stdexcept>

#define TEST_SUIT CurlEdgeTest

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

TEST(TEST_SUIT, GetRequest_complex) {
    CURLcode res;
    std::string readBuffer;

    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        ASSERT_EQ(CURLE_OK, res);

        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        ASSERT_EQ(200, response_code);
    }
}

/**
 * Don`t read the response data but only response code.
 */
TEST(TEST_SUIT, GetRequest_simple) {
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        ASSERT_EQ(200, response_code);
    }
}

