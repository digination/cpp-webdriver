#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>

using std::string;

class ElementQuery {

  private:
    string strat;
    string value;  
  public:
   
    static string STRAT_CLASS ;
    static string STRAT_CSS_SELECTOR ;
    static string STRAT_ID ;
    static string STRAT_NAME ;
    static string STRAT_LINK_TEXT ;
    static string STRAT_PARTIAL_LINK_TEXT ;
    static string STRAT_TAG_NAME ;
    static string STRAT_XPATH ;

  	ElementQuery(string,string);
    string json_encode();

};

class Element {
  public:
  	Element();
};

#endif