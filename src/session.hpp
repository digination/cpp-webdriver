#include <string>
#include "restio.hpp"
#include "capabilities.hpp"
#include "element.hpp"
#include "json.hpp"
#include "log.hpp"
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
    string getScreenshot();
    std::vector<Log*> getLogs(string);
    string getSource();

    ptree execute(string,bool);
    
    /* Alerts/Notices Management */
    void acceptAlert();
    void dismissAlert();
    string getAlertText();
    void sendKeysToAlert(string);

};

