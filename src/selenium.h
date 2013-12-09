#ifndef SELENIUM_H
#define SELENIUM_H
#include <string>
#include "http.h"
#include "utils.h"
#include "capabilities.h"
#include "session.h"
#include "json.h"
class Selenium {
  private:
  	std::string selenium_url;
  public:
  	Selenium(std::string);
    Session* createSession(Capabilities* desiredCapabilities);

};

#endif
