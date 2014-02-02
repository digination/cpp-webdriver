#include "restio.hpp"

AssocArray<uint8_t> initSMAP() {

  AssocArray<uint8_t> smap;
  smap["Success"] = 0;
  smap["NoSuchDriver"] = 6;
  smap["NoSuchElement"] = 7;
  smap["NoSuchFrame"] = 8;
  smap["UnknownCommand"] = 9;
  smap["StaleElementReference"] = 10;
  smap["ElementNotVisible"] = 11;
  smap["InvalidElementState"] = 12;
  smap["UnknownError"] = 13;
  smap["ElementIsNotSelectable"] = 15;
  smap["JavaScriptError"] = 17;
  smap["XPathLookupError"] = 19;
  smap["Timeout"] = 21;
  smap["NoSuchWindow"] = 23;
  smap["InvalidCookieDomain"] = 24;
  smap["UnableToSetCookie"] = 25;
  smap["UnexpectedAlertOpen"] = 26;
  smap["NoAlertOpenError"] = 27;
  smap["ScriptTimeout"] = 28;
  smap["InvalidElementCoordinates"] = 29;
  smap["IMENotAvailable"] = 30;
  smap["IMEEngineActivationFailed"] = 31;
  smap["InvalidSelector"] = 32;
  smap["SessionNotCreatedException"] = 33;
  smap["MoveTargetOutOfBounds"] = 34;
  return smap;
}

AssocArray<uint8_t> restio::statusmap = initSMAP();

restio::restio() {
  http();
  add_header("Content-Type: application/json;charset=UTF-8");
  add_header("Accept: application/json");
}

seleniumAnswer* restio::get(std::string url) {
  std::string ans = http::get(url);
  return parse_answer(ans);
}

seleniumAnswer* restio::post(std::string url,std::string pdata) {
  std::string ans = http::post(url,pdata);
  return parse_answer(ans);
}

seleniumAnswer* restio::del(std::string url) {
  std::string ans = http::del(url);
  return parse_answer(ans);
}


seleniumAnswer* restio::parse_answer(std::string ans) {

  extern bool debug;
  seleniumAnswer* result = new seleniumAnswer();

  if (debug) {
    cout << ans << endl;
  }

  Document document;
  document.Parse<0>(ans.c_str());

  if (document.IsObject()) {

    if (document.HasMember("status")) {
      result->status = document["status"].GetInt();
    }
    if (document.HasMember("sessionId") ) {
      if (document["sessionId"].IsString()) {
        result->sessionId = document["sessionId"].GetString();
      }
    }

    if (document.HasMember("value")) {
      if (document["value"].IsString()) {
        result->value = document["value"].GetString();
      }
      else if (document["value"].IsObject() || document["value"].IsArray() ) {
        result->value_object = document["value"];
      }


    }
  }
  else {
    result->status =0;
    result->value = ans;
  }
  return result;
}
