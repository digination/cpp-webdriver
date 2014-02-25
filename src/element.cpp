#include "element.hpp"
#include "restio.hpp"

string ElementQuery::STRAT_CLASS = "class name";
string ElementQuery::STRAT_CSS_SELECTOR = "css selector";
string ElementQuery::STRAT_ID = "id";
string ElementQuery::STRAT_NAME = "name";
string ElementQuery::STRAT_LINK_TEXT = "link text";
string ElementQuery::STRAT_PARTIAL_LINK_TEXT = "partial link text";
string ElementQuery::STRAT_TAG_NAME = "tag name";
string ElementQuery::STRAT_XPATH = "xpath";


WebdriverElementException wee;


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
  seleniumAnswer* ans = rio->post(seleniumURL + 
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
  
  //cout << "TEXT_URL:" << seleniumURL + "/session/" + sessid + "/element/" + id + "/text" <<endl;

  seleniumAnswer* ans = rio->get(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/text");
  
  rio->destroy();
  
  if (  ans->status == restio::statusmap["Success"] ) {
    return ans->getString();
  }
  else throw wee;

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
  //std::cout << pdata << std::endl;
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
  seleniumAnswer* ans = rio->post(seleniumURL + "/session/" + sessid + "/element/" + id + "/element" ,pdata);
  rio->destroy();  

  if (ans->status == restio::statusmap["Success"] ) {
    return ans->getElement(sessid);
  }
  else throw wee;
  
}



std::vector<Element*> Element::elements(ElementQuery* eq) {

  std::vector<Element*> result;

  extern std::string seleniumURL;
  std::string pdata = eq->json_encode();

  restio* rio = new restio();
  seleniumAnswer* ans = rio->post(seleniumURL + "/session/" + sessid + "/element/" + id + "/elements" ,pdata);
  rio->destroy();  

  if (ans->status == restio::statusmap["Success"] ) {
    result = ans->getElements(sessid);
  }
  else throw wee;
  return result;

}

std::string Element::getCSS(std::string property) {

  string res = "";

  extern std::string seleniumURL;
  restio* rio = new restio();
  
  seleniumAnswer* ans = rio->get(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/css/" + property);
  rio->destroy();

  if (ans->status == restio::statusmap["Success"]) {
    return ans->getString();
  }
  else throw wee;
}

std::string Element::getAttribute(std::string attr) {

  extern std::string seleniumURL;
  restio* rio = new restio();

  seleniumAnswer* ans = rio->get(seleniumURL + 
                                "/session/" + 
                                sessid + 
                                "/element/" + 
                                id + 
                                "/attribute/" + attr);
  
  rio->destroy();
  if (ans->status == restio::statusmap["Success"]) {
    return ans->getString();
  }
  else throw wee;
}

//function that clones the object and returns a new reference.

Element* Element::clone_() {
  return new Element(sessid,id);
}