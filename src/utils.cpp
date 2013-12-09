#include "utils.h"

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}


uint64_t getMsTimeStamp() {

    struct timeval t1;
    uint64_t mtime;    
    long seconds, useconds;    

    gettimeofday(&t1, NULL);

    seconds  = t1.tv_sec;
    useconds = t1.tv_usec;

    //mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    mtime = seconds;
    mtime *= 1000;
    mtime += (useconds/1000.0);

    return mtime;
}

std::string randstring(int len)
{
   std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   int pos;
   while(str.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    str.erase (pos, 1);
   }
   return str;
}

std::string sreplace(std::string &s,
                      std::string toReplace,
                      std::string replaceWith) {

    if (s.find(toReplace) != std::string::npos ) {
      return(s.replace(s.find(toReplace), toReplace.length(), replaceWith));
    }

    else return s;

}

void sreplaceAll(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}



std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}


std::string float2string(float f) {
  std::ostringstream os;
  os << f;
  return os.str();
}

std::string int2string(int i) {
  std::ostringstream os;
  os << i;
  return os.str();
}


bool contains(std::vector<std::string> l,std::string s) {

 for (int i=0;i<l.size();i++) {
   if (l.at(i) == s) {
     return true;  
   }
 }  

    return false;
}

std::string strtolower(std::string s) {

  for (int i=0;i<s.size();++i) {
    s[i] = tolower(s[i]);
  }

  return s;
}

time_t str2time(std::string s) {

  struct tm c_time;

  sscanf(s.c_str(), "%04d-%02d-%02d %02d:%02d:%02d",
       &c_time.tm_year, &c_time.tm_mon,  &c_time.tm_mday,
       &c_time.tm_hour, &c_time.tm_min, &c_time.tm_sec);

  c_time.tm_year -= 1900;
  c_time.tm_mon -= 1;

  return mktime(&c_time);

}


time_t str2time2(std::string s) {

  struct tm c_time;

  sscanf(s.c_str(), "%02d/%02d/%04d %02d:%02d:%02d",
       &c_time.tm_mday, &c_time.tm_mon, &c_time.tm_year,
       &c_time.tm_hour, &c_time.tm_min, &c_time.tm_sec);

  c_time.tm_year -= 1900;
  c_time.tm_mon -= 1;

  return mktime(&c_time);

}


bool vector_in(std::vector<int>* v,int n) {
  for (int i=0;i< v->size();i++) {
    if ( v->at(i) == n ) return true;
  }
  return false;
}

bool vector_in_str(std::vector<std::string>* v,std::string s) {
  for (int i=0;i<v->size();i++) {
    if (v->at(i) == s ) return true;
  }
  return false;
}
