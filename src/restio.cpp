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

ptree restio::get(std::string url) {
  std::string ans = http::get(url);
  return parse_answer(ans);
}

ptree restio::post(std::string url,std::string pdata) {
  std::string ans = http::post(url,pdata);
  return parse_answer(ans);
}

ptree restio::del(std::string url) {
  std::string ans = http::del(url);
  return parse_answer(ans);
}


ptree restio::parse_answer(std::string ans) {

  extern bool debug;

  ptree result;
  if (debug) {
    cout << ans << endl;
  }

  if (ans != "") {
    json_decode(ans,&result);
    /*
    if (result.count("value") > 0 ) {
      return result.get_child("value");
    }

    if (result.count("status") > 0 ) {
      return result.get_child("status"); 
    }
    */
  }
  return result;
}
