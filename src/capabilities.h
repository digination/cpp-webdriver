#ifndef CAPABILITIES_H
#define CAPABILITIES_H
#include <string>
#include "utils.h"

using std::string;

class Capabilities {

  public:
  	
  	string browserName;
    string version;
    string platform;
  	bool javascriptEnabled;
  	bool takesScreenshot; 
  	bool handlesAlerts; 
  	bool databaseEnabled; 
  	bool locationContextEnabled; 
  	bool applicationCacheEnabled; 
  	bool browserConnectionEnabled; 
  	bool cssSelectorsEnabled; 
  	bool webStorageEnabled; 
  	bool rotatable; 
  	bool acceptSslCerts; 
  	bool nativeEvents; 

  	Capabilities();
  	string json_encode();
}; 

#endif