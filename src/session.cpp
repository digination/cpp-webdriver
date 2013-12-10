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


void Session::element(ElementQuery* eq) {
  
  http* h = new http();
  std::string pdata = eq->json_encode();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(seleniumURL + "/session/" + id + "/element",pdata);

  std::cout << "RESPONSE:" << resp_raw << std::endl;

}