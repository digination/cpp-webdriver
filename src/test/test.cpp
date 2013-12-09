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
  }

}