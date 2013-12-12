#include "session.hpp"
#include "globals.hpp"

Session::Session() {

}

void Session::url(string url) {

  extern std::string seleniumURL;

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/url",  "{\"url\":\"" + url + "\"}");
  h->destroy();

}


void Session::back() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/back","");
  h->destroy();

}


void Session::forward() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/forward","");
  h->destroy();
}


void Session::refresh() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/refresh","");
  h->destroy();
}

ptree Session::execute(string script,bool async) {

  ptree result;
  
  string pdata = "{\"script\": " + script + ",\"args\": []}";

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + ( (async) ? "/execute_async": "/execute" ) ,pdata);
  h->destroy();

  return result;

}

Element* Session::element(ElementQuery* eq) {
  
  http* h = new http();
  std::string pdata = eq->json_encode();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/element",pdata);
  h->destroy();

  std::cout << resp_raw << std::endl;

  ptree resp;
  json_decode(resp_raw,&resp);

  if (resp.get<int>("status") == 0 ) {
    return new Element(id, resp.get<string>("value.ELEMENT") );
  }
  else return NULL;
}


std::vector <Element*> Session::elements(ElementQuery* eq) {
  std::vector<Element*> result;
  std::string pdata = eq->json_encode();

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/elements",pdata);
  h->destroy();

  ptree resp;
  json_decode(resp_raw,&resp);

  if (resp.get<int>("status") == 0 ) {

     BOOST_FOREACH(boost::property_tree::ptree::value_type &v,
                   resp.get_child("value")) {
       const ptree& child = v.second;
       result.push_back(new Element(id,child.get<string>("ELEMENT")));
     }
  }
  return result;
}

Element* Session::activeElement() {
  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/element/active","");
  h->destroy();

  ptree resp;
  json_decode(resp_raw,&resp);

  if (resp.get<int>("status") == 0 ) {
    return new Element(id, resp.get<string>("value.ELEMENT") );
  }
  else return NULL;
}


//################ ALERTS MANAGEMENT FCTS ##################

void Session::acceptAlert() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/accept_alert","");
  h->destroy();

}

void Session::dismissAlert() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/dismiss_alert","");
  h->destroy();

}

string Session::getAlertText() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->get(seleniumURL + "/session/" + id + "/alert_text");
  h->destroy();

  return resp_raw;
}

void Session::sendKeysToAlert(string text) {

  string pdata = "{\"text\":\"" + text  + "\"}";
  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/alert_text",pdata);
  h->destroy();

}