#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "exceptions.hpp"

using std::string;

class ElementQuery {
    
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

    string strat;
    string value;
};

class Element {
  
  public:

    string sessid;
    string id;
    Element();
  	Element(string,string);
    void click();
    Element* element(ElementQuery*);
    std::vector<Element*> elements(ElementQuery* eq); 
    void sendKey(int keynum);
    void sendKeys(std::vector<int>);
    void sendKeys(std::string);
    string getText();
    string getCSS(std::string property);
    string getAttribute(std::string attr);
    string getName();

    Element* clone_();
    

};

#endif
