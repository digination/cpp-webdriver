#include <string>
#include "restio.hpp"
#include "capabilities.hpp"
#include "element.hpp"
#include "log.hpp"
#include "cookie.hpp"
#include <vector>

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
    void windowSize(string,int,int);

    string getURL(); 
    string getScreenshot();
    string getWindowHandle();
    void  activateWindow(string handle);
    void  window(string) ;
    vector<std::string> getWindowHandles();
    int* getWindowSize(string);
    std::vector<Log*> getLogs(string);
    string getSource();

    std::vector <Cookie*> getCookies();
    void cookie(Cookie*);
    void deleteCookie(string);

    seleniumAnswer* execute(string,bool);

    /* Alerts/Notices Management */
    void acceptAlert();
    void dismissAlert();
    string getAlertText();
    void sendKeysToAlert(string);

    void cleanElements(vector<Element*>*);
};

