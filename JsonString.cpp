//
// Created by mattheus on 05/09/19.
//

#include "JsonString.h"

JsonString::JsonString() {
    parseOk = false;
    fields = 0;
    innerJSON = "";
    strbuffer.Clear();
    writer.Reset(strbuffer);
}

JsonString::~JsonString() {

}

JsonString::JsonString(std::string jsonString) {
    document.Parse(jsonString.c_str());
    parseOk = document.IsObject();
    fields = document.MemberCount();
    strbuffer.Clear();
    writer.Reset(strbuffer);
}

void JsonString::parseString(std::string jsonString) {
    document.Parse(jsonString.c_str());
    parseOk = document.IsObject();
}

bool JsonString::addField(std::string name, std::string value) {

    if (fields == 0) {
        writer.StartObject();
    }

    writer.String(name.c_str());
    writer.String(value.c_str(), (rapidjson::SizeType) value.length());
    fields++;

    return true;

}

bool JsonString::addField(std::string name, bool value) {

    if (fields == 0) {
        writer.StartObject();
    }

    writer.String(name.c_str());
    writer.Bool(value);

    fields++;

    return true;

}

bool JsonString::addField(std::string name, int value) {

    if (fields == 0) {
        writer.StartObject();
    }

    writer.String(name.c_str());
    writer.Int(value);
    fields++;

    return true;

}

bool JsonString::addField(std::string name, float value) {

    if (fields == 0) {
        writer.StartObject();
    }

    writer.String(name.c_str());
    writer.Double((double) value);

    fields++;

    return true;

}

std::string JsonString::getStringValue(std::string field) {

    if (parseOk) {

        // check if the string was parsed correctly
        if (document.IsObject()) {
            // TODO: to avoid errors during the document members access use exception handling
            for (rapidjson::Value::ConstMemberIterator itr = document.MemberBegin();
                 itr != document.MemberEnd(); ++itr) {
                // if we found the field
                if (itr->name.GetString() == field) {
                    return itr->value.GetString();
                }
            }
        }
        // if field not found
        return "";

    } else {
        // if parse not ok
        return "";
    }
}

bool JsonString::getBoolValue(std::string field) {

    if (parseOk) {
        // check if the string was parsed correctly
        if (document.IsObject()) {
            // TODO: to avoid errors during the document members access use exception handling
            for (rapidjson::Value::ConstMemberIterator itr = document.MemberBegin();
                 itr != document.MemberEnd(); ++itr) {
                // if we found the field
                if (itr->name.GetString() == field) {
                    return itr->value.GetBool();
                }
            }
        }
        // if field not found
        return false;

    } else {
        // if parse not ok
        return false;
    }
}

float JsonString::getFloatValue(std::string field) {

    if (parseOk) {
        // check if the string was parsed correctly
        if (document.IsObject()) {
            // TODO: to avoid errors during the document members access use exception handling
            for (rapidjson::Value::ConstMemberIterator itr = document.MemberBegin();
                 itr != document.MemberEnd(); ++itr) {
                // if we found the field
                if (itr->name.GetString() == field) {
                    return (float) itr->value.GetDouble();
                }
            }
        }
        // if field not found
        return -1.0f;

    } else {
        // if parse not ok
        return -1.0f;
    }
}

int JsonString::getIntValue(std::string field) {

    if (parseOk) {
        // check if the string was parsed correctly
        if (document.IsObject()) {
            // TODO: to avoid errors during the document members access use exception handling
            for (rapidjson::Value::ConstMemberIterator itr = document.MemberBegin();
                 itr != document.MemberEnd(); ++itr) {
                // if we found the field
                if (itr->name.GetString() == field) {
                    return itr->value.GetInt();
                }
            }
        }
        // if field not found
        return -1;

    } else {
        // if parse not ok
        return -1;
    }
}

std::string JsonString::writeString() {

    writer.EndObject();
    innerJSON = strbuffer.GetString();
    return innerJSON;
}

void JsonString::reset() {
    parseOk = false;
    fields = 0;
    innerJSON = "";
    writer.Reset(strbuffer);
    strbuffer.Clear();
}