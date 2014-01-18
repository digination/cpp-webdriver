#include "cookie.hpp"

Cookie::Cookie(string iname,string ival) {
  name = iname;
  value = ival;
  path = "";
  domain = "";
  secure = false;
  expiry = -1;
}

std::string Cookie::json_encode() {

  std::string res =  "{\"name\":\"" + name + "\",";
  res += "\"value\":\"" + value + "\",";

  if (path != "") {
    res += "\"path\":\"" + path + "\",";    
  } 

  if (domain != "") {
    res += "\"domain\":\"" + domain + "\",";
  }

  if (expiry != -1) {
    res += "\"expiry\":" + int2string(expiry) + ",";
  }

  res[-1] = '\0';
  res += "}";
  return res;

}