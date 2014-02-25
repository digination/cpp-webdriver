#ifndef SELENIUMANSWER_HPP
#define SELENIUMANSWER_HPP

#include <string>
#include <vector>

#include "element.hpp"
#include "log.hpp"
#include "cookie.hpp"
#include "exceptions.hpp"
#include <rapidjson/document.h>

using namespace std;
using namespace rapidjson;

class seleniumAnswer {

  public:
    seleniumAnswer();
    seleniumAnswer(int,string,string);
    int getInt();
    string getString();
    string getSession();
    Element* getElement(string);
    vector<Element*> getElements(string);
    vector<string> getWindows();
    vector<Cookie*> getCookies();
    vector<Log*> getLogs();

    int status;
    string sessionId;
    string value;
    Value value_object;

};

#endif