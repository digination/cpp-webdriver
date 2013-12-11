#include "element.h"

string ElementQuery::STRAT_CLASS = "class name";
string ElementQuery::STRAT_CSS_SELECTOR = "css selector";
string ElementQuery::STRAT_ID = "id";
string ElementQuery::STRAT_NAME = "name";
string ElementQuery::STRAT_LINK_TEXT = "link text";
string ElementQuery::STRAT_PARTIAL_LINK_TEXT = "partial link text";
string ElementQuery::STRAT_TAG_NAME = "tag name";
string ElementQuery::STRAT_XPATH = "xpath";

ElementQuery::ElementQuery(string istrat,string ivalue) {
  strat = istrat;
  value = ivalue;
}

string ElementQuery::json_encode() {
  string ret = "{";
  ret += "\t\"using\":\"" + strat + "\",\n";
  ret += "\t\"value\":\"" + value + "\"\n";
  ret +="}";
  return ret;
}


Element::Element() {

}

Element::Element(string i_sessid,string i_id) {
  sessid = i_sessid;
  id = i_id;
}


void Element::click() {

  extern std::string seleniumURL;

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + 
                                 "/session/" + 
                                 sessid + 
                                 "/element/" + 
                                 id + 
                                 "/click","");

  std::cout << resp_raw << std::endl;

}


string Element::getText() {

  extern std::string seleniumURL;

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->get(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/text");

  std::cout << resp_raw << std::endl;

  return "";
}


void Element::sendKey(int keynum) {
  extern std::string seleniumURL;
  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/value","");

  std::cout << resp_raw << std::endl;

}


void Element::sendKeys(std::vector<int> keys) {

  extern std::string seleniumURL;

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/value","");

  std::cout << resp_raw << std::endl;
 
}

void Element::sendKeys(string keys) {

  extern std::string seleniumURL;
  string keys_array = "[";
  string pdata;

  for (int i=0;i<keys.length();i++) {
    keys_array += "'" + char2string(keys[i])  + "'";
    if (i+1 != keys.length() ) keys_array += ",";
  }
  keys_array += "]";
  pdata = "{\"value\":" + keys_array  +  "}";
  std::cout << pdata << std::endl;
  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/value",pdata);
  

  
}
