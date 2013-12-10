#include <iostream>
#include "../selenium.h"

using namespace std;

int main(int argc,char** argv) {

  cout << "Libselenium++ Test Program" << endl;

  Selenium* s = new Selenium("http://127.0.0.1:4444/wd/hub");

  Capabilities* dcap = new Capabilities();
  Session *sess = s->createSession(dcap);
  
  if (sess != NULL) {
    sess->url("http://www.google.com");

    ElementQuery* eq = new ElementQuery(ElementQuery::STRAT_ID,"gb_70");
    ElementQuery* eq2 = new ElementQuery(ElementQuery::STRAT_TAG_NAME,"title");
    Element* e1 = sess->element(eq);
    Element* e2 = sess->element(eq2);
    Element* e3 = sess->activeElement();

    e1->getText();
    e1->click();

    //cout << e1->id << ":" << e2->id << ":" << e3->id << endl;
    //sess->url("http://ig.com/fr/login");
    //sess->back();

  }

}