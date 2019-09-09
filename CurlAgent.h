/**
 * CulrAgent.h
 *
 *  Created on: Nov 5, 2014
 *      Author: csantana
 */

#ifndef CULRAGENT_H_
#define CULRAGENT_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <curl/curl.h>
#include "headers/misc/utils.h"
#include "headers/misc/http_codes.h"

/*!
 * Struct used in the callback function CurlAgent::write_callback to transfer internal data
 * of libcurl to a user pointer to this structure.<br>
 * For more details (external links):
 * - [CURLOPT_WRITEFUNCTION](http://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html)
 * - [getinmemory function](http://curl.haxx.se/libcurl/c/getinmemory.html)
 *
 */
struct MemoryStruct {
    char memory[MAX_RESPONSE_BUFFER_SIZE];
    size_t size;
};

/**
 * Class that manages http transactions via libcurl using C and some C++ structures
 */
class CurlAgent {

private:
    /** server name*/
    std::string serverName;
    /** resource asked to the server*/
    std::string resourceUrl;
    /** last http transaction status code.*/
    int lastHttpStatus;
    /** libCURL handler */
    CURL *curl_handle;
    /** data extracted/inserted  from/into libCurl library */
    struct MemoryStruct chunk;

public:
    /** libCURL code */
    CURLcode res;

    /**
     * Abstraction that represents an object request to the REST like server
     * @param url the representation of the desired resource from the server
     * @return the json contents of the server response
     */
    std::string sendGetRequest(std::string url);

    /**
     * Abstraction that represents a collection update to the REST like server
     * @param url the collection id of the collection to be updated
     * @param postfields Http post method parameter
     * @return the json contents of the server response
     */
    std::string sendPostRequest(std::string url, std::string postfields);

    /**
     * Abstraction that represents an object update to the REST like server
     * @param url the identifier of the resource to be updated
     * @param content the information to be updated on the server
     *
     */
    void sendPutRequest(std::string url, std::string content);

    /**
     * Get the numeric http code of the last transaction
     * @return a numeric http status code
     */
    int getHttpStatus();

    /**
     * Default constructor
     */
    CurlAgent();
    /**
     * Constructor to assing the server name directly
     * @param serverName name or ip of target server
     */
    CurlAgent(std::string serverName);

    /**
     * Default constructor
     */
    ~CurlAgent();

    /**
     * Retrieves the full string of the last performed access
     * @return string having the server name plus url resource
     */
    std::string getFullURL();

    /**
     * Callback function to write the data returned by libcurl to a memory area. This function obeys the
     * fwrite C prototype.<br>
     * For more information check (external links):
     * - [CURLOPT_WRITEFUNCTION](http://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html)
     * - [getinmemory function](http://curl.haxx.se/libcurl/c/getinmemory.html)
     *
     * @param contents libcurl internal data structure pointer
     * @param size size in bytes of each element to be written in the internal buffer
     * @param nmemb number of elements
     * @param userp external information to be stored into libcurl internal structure and further sent
     * to the server
     * @return number of bytes writter successfully in the internal buffer
     */
    static size_t write_callback(void *contents, size_t size,
                                 size_t nmemb, void *userp) {

        size_t realsize = size * nmemb;
        struct MemoryStruct *mem = (struct MemoryStruct *) userp;
        int content_size = MAX_RESPONSE_BUFFER_SIZE;

        mem->memory[0] = '\0';
        mem->size = 0;

        // using limited buffer size avoiding (re or m)alloc call
        if (realsize < MAX_RESPONSE_BUFFER_SIZE)
            content_size = realsize;

        // always overwrite the data previously stored in the buffer
        memcpy(&mem->memory, contents, content_size);
        mem->size = content_size;
        mem->memory[mem->size] = '\0';

        return content_size;
    }

    /**
     * Callback function to read the data from internal memory to a user memory area. This function obeys the
     * fread C prototype.<br>
     * For more information check (external links):
     * - [CURLOPT_READFUNCTION](http://curl.haxx.se/libcurl/c/CURLOPT_READFUNCTION.html)
     * - [ftp upload function](http://curl.haxx.se/libcurl/c/ftpupload.html)
     *
     * @param ptr pointer to user memory space
     * @param size size in bytes of each element to be read from the internal buffer
     * @param nmemb number of elements
     * @param stream pointer to libcurl internal memory
     * @return number elements read successfully
     */
    static size_t read_callback(void *ptr, size_t size, size_t nmemb,
                                void *stream) {
        curl_off_t nread;

        std::string *content = (std::string *) stream;
        size_t realsize = content->length();


        memcpy(ptr, content->c_str(), content->length());

        nread = (curl_off_t) realsize;

        return nread;
    }
};

#endif /* CULRAGENT_H_ */