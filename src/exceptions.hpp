#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

using namespace std;



class WebdriverNetworkException: public exception {

  virtual const char* what() const throw()
  {
    return "An exception occured Regarding Selenium network connection";
  }

} ;


class WebdriverAnswerException: public exception {

  virtual const char* what() const throw()
  {
    return "An exception occured because a bad answer was provided by sleenium server.";
  }

};


class WebdriverValueException: public exception {

  virtual const char* what() const throw()
  {
    return "Webdriver triggered an exception because of unexpected Selenium Server value";
  }

} ;

class WebdriverSessionException: public exception {

  virtual const char* what() const throw()
  {
    return "An exception occured Regarding a Webdriver Session";
  }

};


class WebdriverElementException: public exception {

  virtual const char* what() const throw()
  {
    return "An exception occured Regarding a Webdriver Element";
  }

};

#endif