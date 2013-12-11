cpp-webdriver
=============

cpp-webdriver is a C++ binding for the Selenium REST API.

Dependancies
------------

* boost 1.4+

* libcurl4-openssl

* cmake 2.6+

Status
------

* API: 25% (see API-STATUS.txt)

* Doc: 0%

* Unit Tests: 0% (Code Coverage: 0%)


Compile & Install
-----------------

Clone this repository with the following command:

```shell
git clone http://github.com/digination/cpp-webdriver

#Then, create a new directory for building puproses:

mkdir cpp-webdriver-build

cd cpp-webdriver-build

cmake ../cpp-webdriver

make && make install.
```

Usage Example
-------------

```C++
#include "selenium.h"
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;

int main(int argc,char* argv) {
	
  //creates new selenium object with the selenium entry page as argument.
  Selenium* s = new Selenium("http://127.0.0.1:4444/wd/hub");

  //creates new selenium session.    
  Session* sess = s->createSession(new Capabilities());

  //goes to the google home page.
  sess->url("http://www.google.com");

  //gets all the links on the page
  std::vector<Element*> links = sess->elements(new ElementQuery(ElementQuery::STRAT_TAG_NAME,"a"));

  //displays the number of links on the google homepage
  cout << "# of links:" << links.size() << endl;

}
```
