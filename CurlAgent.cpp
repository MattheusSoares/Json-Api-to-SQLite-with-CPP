
#include <curl/curl.h>
#include "CurlAgent.h"

CurlAgent::CurlAgent(void) {
    curl_global_init(CURL_GLOBAL_ALL);
    this->curl_handle = curl_easy_init();
    this->res = CURLE_OK;
    this->lastHttpStatus = HTTP_CODE_200;
}

CurlAgent::CurlAgent(std::string serverName) {
    curl_global_init(CURL_GLOBAL_ALL);
    this->curl_handle = curl_easy_init();
    this->serverName = serverName;
    this->res = CURLE_OK;
    this->lastHttpStatus = HTTP_CODE_200;
}

CurlAgent::~CurlAgent() {
    curl_easy_cleanup(this->curl_handle);
    curl_global_cleanup();
}

std::string CurlAgent::sendGetRequest(std::string url) {

    resourceUrl = this->serverName + url;
    std::string return_str;

    curl_easy_reset(this->curl_handle);
    curl_easy_setopt(this->curl_handle, CURLOPT_URL, resourceUrl.c_str());
    curl_easy_setopt(this->curl_handle, CURLOPT_WRITEFUNCTION, this->write_callback);
    curl_easy_setopt(this->curl_handle, CURLOPT_WRITEDATA, (void * ) &(this->chunk));
    curl_easy_setopt(this->curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_setopt(this->curl_handle, CURLOPT_TIMEOUT, 2L);

    this->res = curl_easy_perform(this->curl_handle);

    if (this->res != CURLE_OK) {
        std::cout << "curl_easy_perform(): " << curl_easy_strerror(res) << std::endl;
        return_str = "";
    } else {
        curl_easy_getinfo(this->curl_handle, CURLINFO_RESPONSE_CODE, &this->lastHttpStatus);
        return_str = chunk.memory;
    }

    return return_str;
}

std::string CurlAgent::sendPostRequest(std::string url, std::string postfields) {

    curl_easy_reset(this->curl_handle);

    resourceUrl = this->serverName + url;

    curl_easy_setopt(this->curl_handle, CURLOPT_URL, resourceUrl.c_str());

    curl_easy_setopt(this->curl_handle, CURLOPT_WRITEFUNCTION, this->write_callback);

    curl_easy_setopt(this->curl_handle, CURLOPT_POSTFIELDS, postfields.c_str());

    curl_easy_setopt(this->curl_handle, CURLOPT_WRITEDATA, (void * ) &(this->chunk));

    curl_easy_setopt(this->curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    curl_easy_setopt(this->curl_handle, CURLOPT_TIMEOUT, 2L);

    this->res = curl_easy_perform(this->curl_handle);

    if (this->res != CURLE_OK)
        std::cout << "curl_easy_perform(): " << curl_easy_strerror(this->res) << std::endl;

    std::string return_str(this->chunk.memory);
    return return_str;
}

void CurlAgent::sendPutRequest(std::string url, std::string content) {

    curl_easy_reset(this->curl_handle);
    resourceUrl = this->serverName + url;
    curl_easy_setopt(this->curl_handle, CURLOPT_URL, resourceUrl.c_str());
    curl_easy_setopt(this->curl_handle, CURLOPT_READFUNCTION, this->read_callback);
    curl_easy_setopt(this->curl_handle, CURLOPT_UPLOAD, 2L);
    curl_easy_setopt(this->curl_handle, CURLOPT_READDATA, &content);
    curl_easy_setopt(this->curl_handle, CURLOPT_INFILESIZE, (curl_off_t )content.length());
    curl_easy_setopt(this->curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_setopt(this->curl_handle, CURLOPT_TIMEOUT, 2L);
    this->res = curl_easy_perform(this->curl_handle);

    if (this->res != CURLE_OK)
        std::cout << "curl_easy_perform(): " << curl_easy_strerror(this->res) << std::endl;

}

int CurlAgent::getHttpStatus() {
    return this->lastHttpStatus;
}

std::string CurlAgent::getFullURL() {
    return this->resourceUrl;
}