#include <string>
#include "http.h"
#include "capabilities.h"
#include "element.h"
#include "json.h"
#include <vector>
#include <boost/foreach.hpp>

using std::string;
using std::vector;

class Session {
  public:
    string id;
    Capabilities* capabilities;
  	Session();
  	void url(string);
  	void back();
  	void forward();
  	void refresh();
  	Element* element(ElementQuery*);
    std::vector<Element*> elements(ElementQuery*);
  	Element* activeElement();
  	void click(Element*);
  	void click(ElementQuery*);
  	void click(string);
    string getURL(); 
    ptree execute(string,bool);

    /* Alerts/Notices Management */
    void acceptAlert();
    void dismissAlert();
    string getAlertText();
    void sendKeysToAlert(string);

};

