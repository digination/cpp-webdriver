#include "seleniumanswer.hpp"

seleniumAnswer::seleniumAnswer() {

  status = -1;
  sessionId = "";
  value = "";

}

seleniumAnswer::seleniumAnswer(int s,string sess,string v) {
  status = s;
  sessionId = sess;
  value = v;
}

string seleniumAnswer::getSession() {
  return sessionId;
}

string seleniumAnswer::getString() {
  return value;
}

int seleniumAnswer::getInt() {
  return atoi(value.c_str());
}

Element* seleniumAnswer::getElement(string sessid) {
  string eid = value_object["ELEMENT"].GetString();
  return new Element(sessid,eid);
}

vector<Element*> seleniumAnswer::getElements(string sessid) {
  vector<Element*> result;
  for (SizeType i = 0; i < value_object.Size(); i++) {
    result.push_back(new Element(sessid, value_object[i]["ELEMENT"].GetString() ));
  }
  return result;
}

vector<Cookie*> seleniumAnswer::getCookies() {
  vector<Cookie*> result;
  return result;
}

vector<Log*> seleniumAnswer::getLogs() {
  vector<Log*> result;
  return result; 
}
