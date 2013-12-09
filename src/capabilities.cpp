#include "capabilities.h"

Capabilities::Capabilities() {

  browserName = "firefox";
  version = "";
  platform = "";
  javascriptEnabled = true;
  takesScreenshot = false;
  handlesAlerts = false;
  databaseEnabled = false;
  locationContextEnabled = false;
  applicationCacheEnabled = true;
  browserConnectionEnabled = true;
  cssSelectorsEnabled = true;
  webStorageEnabled = false;
  rotatable = false;
  acceptSslCerts = true;
  nativeEvents = true;

}

string Capabilities::json_encode() {

  string ret = "{\n";
  ret += "\t\"browserName\":" + browserName + ",\n";
  
  if (version != "") {
    ret += "\t\"version\":" + version + ",\n";
  }
  if (platform != "") {
    ret += "\t\"platform\":" + platform + ",\n";
  }

  ret += "\t\"javascriptEnabled\":" + bool2string(javascriptEnabled) + ",\n";
  ret += "\t\"takesScreenshot\":" + bool2string(takesScreenshot) + ",\n";
  ret += "\t\"handlesAlerts\":" + bool2string(handlesAlerts) + ",\n";
  ret += "\t\"databaseEnabled\":" + bool2string(databaseEnabled) + ",\n";
  ret += "\t\"locationContextEnabled\":" + bool2string(locationContextEnabled) + ",\n";
  ret += "\t\"applicationCacheEnabled\":" + bool2string(applicationCacheEnabled) + ",\n";
  ret += "\t\"browserConnectionEnabled\":" + bool2string(browserConnectionEnabled) + ",\n";
  ret += "\t\"cssSelectorsEnabled\":" + bool2string(cssSelectorsEnabled) + ",\n";
  ret += "\t\"webStorageEnabled\":" + bool2string(webStorageEnabled) + ",\n";
  ret += "\t\"rotatable\":" + bool2string(rotatable) + ",\n";
  ret += "\t\"acceptSslCerts\":" + bool2string(acceptSslCerts) + ",\n";
  ret += "\t\"nativeEvents\":" + bool2string(nativeEvents) + "\n";
  ret +="}";

  return ret;
}