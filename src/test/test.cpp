#include <iostream>
#include "../selenium.h"

using namespace std;


int getpositions() {

  //vector<Element*> = ; 
}

int openpos(Session* sess,string epic,string way,int qte,int stop,int limit) {

  Element* openpos_line = sess->element(new ElementQuery(ElementQuery::STRAT_CLASS,
                                                         "tr[class='rec-" + epic + "']" ));


  if (openpos_line != NULL) {

    Element* openpos_btn = openpos_line->element(new ElementQuery(ElementQuery::STRAT_CLASS, "dealOpen"));
    if (openpos_btn != NULL) {

      cout<< "OPENPOS TEXT:" << openpos_btn->getText() << endl;

      openpos_btn->click();
    }

    else {
      cout << "OPENPOS BTN NOT FOUND!" << endl;
    }

  }

  else {
    cout << "OPENPOS LINE NOT FOUND" << endl;
  }

}

int main(int argc,char** argv) {

  cout << "Libselenium++ Test Program" << endl;

  Selenium* s = new Selenium("http://127.0.0.1:4444/wd/hub");

  Capabilities* dcap = new Capabilities();
  Session *sess = s->createSession(dcap);
  
  if (sess != NULL) {
    
    sess->url("http://www.ig.com/fr/login");

    ElementQuery* q1 = new ElementQuery(ElementQuery::STRAT_ID,"account_id");
    ElementQuery* q2 = new ElementQuery(ElementQuery::STRAT_ID,"password");
    ElementQuery* q3 = new ElementQuery(ElementQuery::STRAT_ID,"loginbutton");

    Element* account_id = sess->element(q1);
    Element* password = sess->element(q2);
    Element* loginbutton = sess->element(q3);

    if (account_id != NULL) {
      account_id->sendKeys("");
    }

    if (password != NULL) {
      password->sendKeys("");
    }

    if (loginbutton != NULL) {
      loginbutton->click();
    }

    sleep(10);

    
    //Passage du bouton "Valider et sauvegarder"
    Element* accept_btn = sess->element(new ElementQuery(ElementQuery::STRAT_CLASS,
                                                         "submit_button"));
    if (accept_btn != NULL) {
      accept_btn->click();
    }
    else {
      cout << "CANNOT GET ACCCEPT BTN" << endl;
    }

    //Selection des valeurs dans "Ma Liste"
    vector<Element*> watchlist_links = sess->elements(new ElementQuery(ElementQuery::STRAT_CLASS,"watchlistName"));

    if (watchlist_links.size() == 3) {
      watchlist_links[2]->click();
    }

    //Fin de L'initialisation
    sleep(3);

    openpos(sess,"IX.D.CAC.IMF.IP","buy",2,10,10);

    //############## Values Fetching  ##############
    //vector<Element*> a_list = sess->elements(new ElementQuery(ElementQuery::STRAT_TAG_NAME,"a"));
    //cout << "# Of Links:" << a_list.size() << endl;
    
  }

}