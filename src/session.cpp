#include "session.hpp"
#include "globals.hpp"

Session::Session() {

}

void Session::url(string url) {

  extern std::string seleniumURL;
  restio* rio = new restio();
  rio->post(seleniumURL + "/session/" + id + "/url",  "{\"url\":\"" + url + "\"}");
  rio->destroy();
}


void Session::back() {

  restio* rio = new restio();
  rio->post(seleniumURL + "/session/" + id + "/back","");
  rio->destroy();
}

void Session::forward() {

  restio* rio = new restio();
  rio->post(seleniumURL + "/session/" + id + "/forward","");
  rio->destroy();
}

void Session::refresh() {
  restio* rio = new restio();
  rio->post(seleniumURL + "/session/" + id + "/refresh","");
  rio->destroy();
}

ptree Session::execute(string script,bool async) {

  string pdata = "{\"script\":\"" + json_escape(script) + "\",\"args\": []}";
  restio* rio = new restio();
  ptree resp = rio->post(seleniumURL + "/session/" + id + ( (async) ? "/execute_async": "/execute" ) ,pdata);
  rio->destroy();
  return resp;

}

Element* Session::element(ElementQuery* eq) {
  
  restio* rio = new restio();
  std::string pdata = eq->json_encode();
  ptree resp = rio->post(seleniumURL + "/session/" + id + "/element",pdata);
  rio->destroy();

  if (resp.get<int>("status") == restio::statusmap["Success"] ) {
    return new Element(id, resp.get<string>("value.ELEMENT") );
  }
  else return NULL;
}

std::vector <Element*> Session::elements(ElementQuery* eq) {
  std::vector<Element*> result;
  std::string pdata = eq->json_encode();

  restio* rio = new restio();
  ptree resp = rio->post(seleniumURL + "/session/" + id + "/elements",pdata);
  rio->destroy();

  if (resp.get<int>("status") == restio::statusmap["Success"] ) {

     BOOST_FOREACH(boost::property_tree::ptree::value_type &v,
                   resp.get_child("value")) {
       const ptree& child = v.second;
       result.push_back(new Element(id,child.get<string>("ELEMENT")));
     }
  }
  return result;
}

Element* Session::activeElement() {
  restio* rio = new restio();
  ptree resp = rio->post(seleniumURL + "/session/" + id + "/element/active","");
  rio->destroy();

  if (resp.get<int>("status") == restio::statusmap["Success"] ) {
    return new Element(id, resp.get<string>("value.ELEMENT") );
  }
  else return NULL;
}

//################ ALERTS MANAGEMENT FCTS ##################

void Session::acceptAlert() {
  restio* rio = new restio();
  rio->post(seleniumURL + "/session/" + id + "/accept_alert","");
  rio->destroy();
}

void Session::dismissAlert() {

  restio* rio = new restio();
  rio->post(seleniumURL + "/session/" + id + "/dismiss_alert","");
  rio->destroy();
}

string Session::getAlertText() {

  restio* rio = new restio();
  ptree resp = rio->get(seleniumURL + "/session/" + id + "/alert_text");
  rio->destroy();

  if (resp.get<int>("status") == restio::statusmap["Success"] ) {
    return resp.get<string>("value");
  }
  return "nil";
}

void Session::sendKeysToAlert(string text) {

  string pdata = "{\"text\":\"" + text  + "\"}";
  restio* rio = new restio();
  rio->post(seleniumURL + "/session/" + id + "/alert_text",pdata);
  rio->destroy();
}

string Session::getURL() {

  restio* rio = new restio();
  ptree resp = rio->get(seleniumURL + "/session/" + id + "/url");
  rio->destroy();

  if (resp.get<int>("status") == restio::statusmap["Success"] ) {
    return resp.get<string>("value");
  }
  return "nil";
}

string Session::getScreenshot() {
  restio* rio = new restio();
  ptree resp = rio->get(seleniumURL + "/session/" + id + "/screenshot");
  rio->destroy();
  
  if (resp.get<int>("status") == restio::statusmap["Success"] ) {
    return resp.get<string>("value");
  }
  return "nil";
}