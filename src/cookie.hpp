#ifndef COOKIE_HPP
#define COOKIE_HPP
#include <string>
#include "utils.hpp"

using namespace std;

class Cookie {

  public:
  	Cookie(string,string);
  	string name;
  	string value;
  	string path;
  	string domain;
  	bool secure;
  	int expiry;
  	string json_encode();
};
#endif