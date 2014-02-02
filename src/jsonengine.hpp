#ifndef JSON_H
#define JSON_H
#include <sstream>
#include <rapidjson/document.h>

using std::string;
using namespace rapidjson;


Document* json_decode(string);
std::string json_escape(const std::string& input);

#endif