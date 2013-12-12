#include "selenium.hpp"

Selenium::Selenium(std::string surl) {

  extern std::string seleniumURL; 

  selenium_url = surl;
  seleniumURL = surl;

  http* h  = new http();
  std::string status_resp = h->get(selenium_url + "/status");
  std::cout << status_resp << std::endl;
 
}

Session* Selenium::createSession(Capabilities* desiredCapabilities) {

  std::string pdata = "{\"desiredCapabilities\":" + desiredCapabilities->json_encode() + "}";

  http* h  = new http();
  h->add_header("Content-Type: application/json;charset=UTF-8");
  h->add_header("Accept: application/json");
  std::string resp_raw = h->post(selenium_url + "/session",pdata);

  std::cout << resp_raw << std::endl;

  ptree resp;
  json_decode(resp_raw,&resp);

  if ( resp.get<int>("status") == 0 ) {

     Session* s = new Session();
     s->id = resp.get<std::string>("sessionId");
     std::cout << s->id << std::endl;
     return s;
  }
  return NULL;
}
