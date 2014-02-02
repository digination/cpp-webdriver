#include "selenium.hpp"

Selenium::Selenium(std::string surl,bool dbg) {

  extern std::string seleniumURL; 
  extern bool debug;

  selenium_url = surl;
  seleniumURL = surl;
  debug = dbg;
  
  restio* rio  = new restio();
  rio->get(selenium_url + "/status");
  
}

Session* Selenium::createSession(Capabilities* desiredCapabilities) {

  std::string pdata = "{\"desiredCapabilities\":" + desiredCapabilities->json_encode() + "}";

  restio* rio  = new restio();
  seleniumAnswer* ans = rio->post(selenium_url + "/session",pdata);
  
  if ( ans->status == restio::statusmap["Success"] ) {

     Session* s = new Session();
     s->id = ans->getSession();
     //s->id = resp.get<std::string>("sessionId");
     std::cout << s->id << std::endl;
     return s;
  }
  return NULL;
}
