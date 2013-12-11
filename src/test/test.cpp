#include <iostream>
#include "../selenium.h"

using namespace std;

int main(int argc,char** argv) {

  cout << "Libselenium++ Test Program" << endl;

  Selenium* s = new Selenium("http://127.0.0.1:4444/wd/hub");

  Capabilities* dcap = new Capabilities();
  Session *sess = s->createSession(dcap);
  
  if (sess != NULL) {
    sess->url("http://www.ig.com/fr/login");

    ElementQuery* q1 = new ElementQuery(ElementQuery::STRAT_ID,"account_id");
    ElementQuery* q2 = new ElementQuery(ElementQuery::STRAT_ID,"password");
    ElementQuery* q3 = new ElementQuery(ElementQuery::STRAT_ID,"loginbutton");

    Element* account_id = sess->element(q1);
    Element* password = sess->element(q2);
    Element* loginbutton = sess->element(q3);

    if (account_id != NULL) {
      account_id->sendKeys("demo-avargas");
    }

    if (password != NULL) {
      password->sendKeys("oinitan44");
    }

    if (loginbutton != NULL) {
      loginbutton->click();
    }

    sleep(10);

    //* ############## Values Fetching  ##############*/
    
    ElementQuery *q4 = new ElementQuery(ElementQuery::STRAT_CLASS)
    





  }

}