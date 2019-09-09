/*
 * http_codes.h
 *
 *  Created on: Dec 12, 2014
 *      Author: csantana
 */

#ifndef HTTP_CODES_H_
#define HTTP_CODES_H_


#define HTTP_CODE_100 (100) //Continue [RFC7231, Section 6.2.1]
#define HTTP_CODE_101 (101) //Switching Protocols [RFC7231, Section 6.2.2]
#define HTTP_CODE_102 (102) //Processing [RFC2518]
#define HTTP_CODE_200 (200) //OK [RFC7231, Section 6.3.1]
#define HTTP_CODE_201 (201) //Created [RFC7231, Section 6.3.2]
#define HTTP_CODE_202 (202) //Accepted [RFC7231, Section 6.3.3]
#define HTTP_CODE_203 (203) //Non-Authoritative Information [RFC7231, Section 6.3.4]
#define HTTP_CODE_204 (204) //No Content [RFC7231, Section 6.3.5]
#define HTTP_CODE_205 (205) //Reset Content [RFC7231, Section 6.3.6]
#define HTTP_CODE_206 (206) //Partial Content [RFC7233, Section 4.1]
#define HTTP_CODE_207 (207) //Multi-Status [RFC4918]
#define HTTP_CODE_208 (208) //Already Reported [RFC5842]
#define HTTP_CODE_226 (226) //IM Used [RFC3229]
#define HTTP_CODE_300 (300)
#define HTTP_CODE_301 (301) //Moved Permanently [RFC7231, Section 6.4.2]
#define HTTP_CODE_302 (302) //Found [RFC7231, Section 6.4.3]
#define HTTP_CODE_303 (303) //See Other [RFC7231, Section 6.4.4]
#define HTTP_CODE_304 (304) //Not Modified [RFC7232, Section 4.1]
#define HTTP_CODE_305 (305) //Use Proxy [RFC7231, Section 6.4.5]
#define HTTP_CODE_306 (306) //(Unused) [RFC7231, Section 6.4.6]
#define HTTP_CODE_307 (307) //Temporary Redirect [RFC7231, Section 6.4.7]
#define HTTP_CODE_308 (308) //Permanent Redirect [RFC7238]
#define HTTP_CODE_400 (400) //Bad Request [RFC7231, Section 6.5.1]
#define HTTP_CODE_401 (401) //Unauthorized [RFC7235, Section 3.1]
#define HTTP_CODE_402 (402) //Payment Required [RFC7231, Section 6.5.2]
#define HTTP_CODE_403 (403) //Forbidden [RFC7231, Section 6.5.3]
#define HTTP_CODE_404 (404) //Not Found [RFC7231, Section 6.5.4]
#define HTTP_CODE_405 (405) //Method Not Allowed [RFC7231, Section 6.5.5]
#define HTTP_CODE_406 (406) //Not Acceptable [RFC7231, Section 6.5.6]
#define HTTP_CODE_407 (407) //Proxy Authentication Required [RFC7235, Section 3.2]
#define HTTP_CODE_408 (408) //Request Timeout [RFC7231, Section 6.5.7]
#define HTTP_CODE_409 (409) //Conflict [RFC7231, Section 6.5.8]
#define HTTP_CODE_410 (410) //Gone [RFC7231, Section 6.5.9]
#define HTTP_CODE_411 (411) //Length Required [RFC7231, Section 6.5.10]
#define HTTP_CODE_412 (412) //Precondition Failed [RFC7232, Section 4.2]
#define HTTP_CODE_413 (413) //Payload Too Large [RFC7231, Section 6.5.11]
#define HTTP_CODE_414 (414) //URI Too Long [RFC7231, Section 6.5.12]
#define HTTP_CODE_415 (415) //Unsupported Media Type [RFC7231, Section 6.5.13]
#define HTTP_CODE_416 (416) //Range Not Satisfiable [RFC7233, Section 4.4]
#define HTTP_CODE_417 (417) //Expectation Failed [RFC7231, Section 6.5.14]
#define HTTP_CODE_422 (422) //Unprocessable Entity [RFC4918]
#define HTTP_CODE_423 (423) //Locked [RFC4918]
#define HTTP_CODE_424 (424) //Failed Dependency [RFC4918]
#define HTTP_CODE_425 (425) //Unassigned //
#define HTTP_CODE_426 (426) //Upgrade Required [RFC7231, Section 6.5.15]
#define HTTP_CODE_427 (427) //Unassigned //
#define HTTP_CODE_428 (428) //Precondition Required [RFC6585]
#define HTTP_CODE_429 (429) //Too Many Requests [RFC6585]
#define HTTP_CODE_430 (430) //Unassigned //
#define HTTP_CODE_431 (431) //Request Header Fields Too Large [RFC6585]
#define HTTP_CODE_500 (500) //Internal Server Error [RFC7231, Section 6.6.1]
#define HTTP_CODE_501 (501) //Not Implemented [RFC7231, Section 6.6.2]
#define HTTP_CODE_502 (502) //Bad Gateway [RFC7231, Section 6.6.3]
#define HTTP_CODE_503 (503) //Service Unavailable [RFC7231, Section 6.6.4]
#define HTTP_CODE_504 (504) //Gateway Timeout [RFC7231, Section 6.6.5]
#define HTTP_CODE_505 (505) //HTTP Version Not Supported [RFC7231, Section 6.6.6]
#define HTTP_CODE_506 (506) //Variant Also Negotiates [RFC2295]
#define HTTP_CODE_507 (507) //Insufficient Storage [RFC4918]
#define HTTP_CODE_508 (508) //Loop Detected [RFC5842]
#define HTTP_CODE_509 (509) //Unassigned //
#define HTTP_CODE_510 (510) //Not Extended [RFC2774]
#define HTTP_CODE_511 (511) //Network Authentication Required [RFC6585]

#endif /* HTTP_CODES_H_ */
