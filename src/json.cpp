#include "json.hpp"

void json_decode(string s,ptree* p) {
  std::istringstream ss (s);
  read_json (ss,*p);
}
