#include <string>
#include "http.h"
#include "capabilities.h"
#include "element.h"

using std::string;

#define CSS_SELECTOR 0x01
#define NAME_SELECTOR 0x02
#define ID_SELECTOR 0x03

class Session {
  public:
    string id;
    Capabilities* capabilities;
  	Session();
  	void url(string);
  	void click(Element*);
  	void click(string);

};

