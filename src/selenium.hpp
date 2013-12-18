#ifndef SELENIUM_H
#define SELENIUM_H
#include <string>
#include "restio.hpp"
#include "utils.hpp"
#include "capabilities.hpp"
#include "session.hpp"
#include "json.hpp"
class Selenium {
  private:
  	std::string selenium_url;
  public:
  	Selenium(std::string,bool);
    Session* createSession(Capabilities* desiredCapabilities);

};

#endif
