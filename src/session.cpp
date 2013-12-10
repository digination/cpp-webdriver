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

  std::cout << "RESPONSE:" << resp_raw << std::endl;
  
}


void Session::back() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/back","");
  std::cout << "RESPONSE:" << resp_raw << std::endl;

}


void Session::forward() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/forward","");
  std::cout << "RESPONSE:" << resp_raw << std::endl;

}


void Session::refresh() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/refresh","");
  std::cout << "RESPONSE:" << resp_raw << std::endl;

}


Element* Session::element(ElementQuery* eq) {
  
  http* h = new http();
  std::string pdata = eq->json_encode();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/element",pdata);

  std::cout << "RESPONSE:" << resp_raw << std::endl;
  ptree resp;
  json_decode(resp_raw,&resp);

  if (resp.get<int>("status") == 0 ) {
    return new Element(id, resp.get<string>("value.ELEMENT") );
  }

  else return NULL;

}

Element* Session::activeElement() {

  http* h = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/element/active","");

  std::cout << "RESPONSE:" << resp_raw << std::endl;
  ptree resp;
  json_decode(resp_raw,&resp);

  if (resp.get<int>("status") == 0 ) {
    return new Element(id, resp.get<string>("value.ELEMENT") );
  }

  else return NULL;


}


