#ifndef UTILS_H
#define UTILS_H

#include  <vector>
#include <string>
#include <iostream>
#include <sstream>

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <iterator>


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

std::string &ltrim(std::string &s);
std::string &rtrim(std::string &s);
std::string &trim(std::string &s);

uint64_t getMsTimeStamp();
std::string randstring(int len);
std::string sreplace(std::string &s,
                      std::string toReplace,
                      std::string replaceWith);

void sreplaceAll(std::string&, 
	             const std::string&,
                 const std::string&);


std::string currentDateTime();
std::string float2string(float);
std::string int2string(int);

bool contains(std::vector<std::string>,std::string);

std::string strtolower(std::string);


std::string stripHTML(std::string);
std::string stripTags(std::string);

time_t str2time(std::string s);
time_t str2time2(std::string s);

bool vector_in(std::vector<int>*,int);
bool vector_in_str(std::vector<std::string>*,std::string);

inline std::string const bool2string(bool b)
{
  return b ? "true" : "false";
}



#endif