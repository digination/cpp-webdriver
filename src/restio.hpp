#ifndef RESTIO_HPP
#define RESTIO_HPP

#include "http.hpp"
#include "jsonengine.hpp"
#include "seleniumanswer.hpp"

#include <stdint.h>

class restio: public http {

  public:
  	static AssocArray<uint8_t> statusmap;
  	restio();
    seleniumAnswer* get(std::string);
    seleniumAnswer* post(std::string,std::string);
    seleniumAnswer* del(std::string);

  private:
  	seleniumAnswer* parse_answer(std::string);

};

#endif
