#include "element.h"

string ElementQuery::STRAT_CLASS = "class name";
string ElementQuery::STRAT_CSS_SELECTOR = "css selector";
string ElementQuery::STRAT_ID = "id";
string ElementQuery::STRAT_NAME = "name";
string ElementQuery::STRAT_LINK_TEXT = "link text";
string ElementQuery::STRAT_PARTIAL_LINK_TEXT = "partial link text";
string ElementQuery::STRAT_TAG_NAME = "partial link text";
string ElementQuery::STRAT_XPATH = "xpath";

ElementQuery::ElementQuery(string istrat,string ivalue) {
  strat = istrat;
  value = ivalue;
}

string ElementQuery::json_encode() {

  string ret = "{";
  ret += "\t\"using\":\"" + strat + "\",\n";
  ret += "\t\"value\":\"" + value + "\"\n";
  ret +="}";

  return ret;

}
