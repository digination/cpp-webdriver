#include "session.h"
#include "globals.h"

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


Element* Session::element(ElementQuery* eq) {
  
  http* h = new http();
  std::string pdata = eq->json_encode();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/element",pdata);
  h->destroy();

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