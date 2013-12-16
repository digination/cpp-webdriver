#include "element.hpp"

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

  restio* rio = new restio();
  ptree resp = rio->post(seleniumURL + 
                                 "/session/" + 
                                 sessid + 
                                 "/element/" + 
                                 id + 
                                 "/click","");
  rio->destroy();

}


string Element::getText() {

  extern std::string seleniumURL;

  restio* rio = new restio();
  ptree resp = rio->get(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/text");
  rio->destroy();

  if (  resp.get<int>("status") == restio::statusmap["Success"] ) {
    return resp.get<string>("value");
  }
  return "nil";
}


void Element::sendKey(int keynum) {
  extern std::string seleniumURL;
}


void Element::sendKeys(std::vector<int> keys) {
  extern std::string seleniumURL;
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
  restio* rio = new restio();
  
  rio->post(seleniumURL + 
            "/session/" + 
            sessid + 
            "/element/" + 
            id + 
            "/value",pdata);
  rio->destroy();

}


Element* Element::element(ElementQuery* eq) {

  extern std::string seleniumURL;
  std::string pdata = eq->json_encode();

  restio* rio = new restio();
  ptree resp = rio->post(seleniumURL + "/session/" + sessid + "/element/" + id + "/element" ,pdata);
  rio->destroy();  

  if (resp.get<int>("status") == restio::statusmap["Success"] ) {
    return new Element(id, resp.get<string>("value.ELEMENT") );
  }
  return NULL;

}


std::string Element::getCSS(std::string property) {

  string res = "";

  extern std::string seleniumURL;
  restio* rio = new restio();
  
  ptree resp = rio->get(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/css/" + property);
  rio->destroy();

  if (resp.get<int>("status") == restio::statusmap["Success"]) {
    return resp.get<string>("value");
  }

  return "nil";
}


std::string Element::getAttribute(std::string attr) {

  extern std::string seleniumURL;
  restio* rio = new restio();

  ptree resp = rio->get(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/attribute/" + attr);
  
  rio->destroy();
  if (resp.get<int>("status") == restio::statusmap["Success"]) {
    return resp.get<string>("value");
  }
  return "nil";
}