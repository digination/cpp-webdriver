#include "seleniumanswer.hpp"

WebdriverValueException vex;

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
  if (value_object.IsObject()) {
    string eid = value_object["ELEMENT"].GetString();
    return new Element(sessid,eid);
  }
  else throw vex;
}

vector<Element*> seleniumAnswer::getElements(string sessid) {
  vector<Element*> result;
  if (value_object.IsArray()) {
    for (SizeType i = 0; i < value_object.Size(); i++) {
      result.push_back(new Element(sessid, value_object[i]["ELEMENT"].GetString() ));
    }
    return result;
  }
  else throw vex;
}

vector<string> seleniumAnswer::getWindows() {
  vector<string> result;
  if (value_object.IsArray()) {
    for (SizeType i = 0; i < value_object.Size(); i++) {
      result.push_back(value_object[i]["WINDOW"].GetString() );
    }
    return result;
  }
  else throw vex;
}


vector<Cookie*> seleniumAnswer::getCookies() {
  vector<Cookie*> result;
  return result;
}

vector<Log*> seleniumAnswer::getLogs() {
  vector<Log*> result;
  return result; 
}
