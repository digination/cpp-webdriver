#include "http.hpp"
#include "json.hpp"

class restio: public http {

  public:
  	static AssocArray<uint8_t> statusmap;
  	restio();
    ptree get(std::string);
    ptree post(std::string,std::string);
    ptree del(std::string);

  private:
  	ptree parse_answer(std::string);

};

