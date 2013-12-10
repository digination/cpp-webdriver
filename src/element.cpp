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
  std::string resp_raw = h->post(seleniumURL + "/session/" + sessid + "/element/" + id + "/click","");

  std::cout << resp_raw << std::endl;

}


string Element::getText() {

  extern std::string seleniumURL;

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->get(seleniumURL + "/session/" + sessid + "/element/" + id + "/text");
  std::cout << resp_raw << std::endl;

  return "";


}