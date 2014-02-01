#include "json.hpp"

using namespace std;

ptree json_decode(string s) {

  ptree p;

  std::istringstream ss (s);
  try {
    read_json (ss,p);
  }
  catch (exception e) {
    cerr << "*CRITICAL: CANNOT PARSE/MALFORMED JSON '" << s << "'" << endl;
  }
}

std::string json_escape(const std::string& input) {
    std::ostringstream ss;
    for (std::string::const_iterator iter = input.begin(); iter != input.end(); iter++) {
        switch (*iter) {
            case '\\': ss << "\\\\"; break;
            case '"': ss << "\\\""; break;
            case '/': ss << "\\/"; break;
            case '\b': ss << "\\b"; break;
            case '\f': ss << "\\f"; break;
            case '\n': ss << "\\n"; break;
            case '\r': ss << "\\r"; break;
            case '\t': ss << "\\t"; break;
            default: ss << *iter; break;
        }
    }
    return ss.str();
}
