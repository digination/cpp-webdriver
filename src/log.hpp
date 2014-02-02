#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>


class Log {

  public:

  	static std::string LTYPE_CLIENT;
  	static std::string LTYPE_DRIVER;
  	static std::string LTYPE_BROWSER;
  	static std::string LTYPE_SERVER;

    int timestamp;
    std::string level;
    std::string message;
    void print();

};

#endif




