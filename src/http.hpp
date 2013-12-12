#ifndef HTTP_H
#define HTTP_H

#include <curl/curl.h>
#include <stdlib.h>
#include <string>
#include "assoc.hpp"

class http {

  private:
  	CURL* ch;
  	struct curl_slist *headers;
  public:
  	http();
  	void destroy();
  	void add_header(std::string);
  	std::string get(std::string url);
  	std::string post(std::string,std::string);
  	std::string post(std::string url,AssocArray<std::string> post_data);
  	std::string del(std::string url);
    
};

#endif