//
// Created by mattheus on 05/09/19.
//

#ifndef DB_LOCAL_JSONSTRING_H
#define DB_LOCAL_JSONSTRING_H



#include <iostream>
#include "include/rapidjson/document.h"
#include "include/rapidjson/filereadstream.h"
#include "include/rapidjson/filewritestream.h"
#include "include/rapidjson/prettywriter.h"


class JsonString {

private:

    /**
     * internal rapidjson buffer used to convert some object to a JSON string
     */
    rapidjson::StringBuffer strbuffer;

    /**
     * rapidjson type that extracts fields from JSON string
     */
    rapidjson::Document document;

    /**
     * last document parse operation result
     */
    bool parseOk;

    /**
     *
     */
    std::string innerJSON;

    /**
     *
     */
    int fields;

    rapidjson::Writer<rapidjson::StringBuffer> writer;

public:
    JsonString(std::string jsonString);
    JsonString();
    ~JsonString();

    bool addField(std::string name, bool value);
    bool addField(std::string name, int value);
    bool addField(std::string name, float value);
    bool addField(std::string name, std::string value);

    std::string getStringValue(std::string field);
    bool getBoolValue(std::string field);
    int getIntValue(std::string field);
    float getFloatValue(std::string field);

    void parseString(std::string jsonString);

    std::string writeString();

    void reset();

};

#endif /* JSONSTRING_H_ */