#include "log.hpp"

std::string Log::LTYPE_CLIENT = "client";
std::string Log::LTYPE_DRIVER = "driver";
std::string Log::LTYPE_BROWSER = "browser";
std::string Log::LTYPE_SERVER = "server";


void Log::print() {
  std::cout << "[" << timestamp << "]" << "[" << level << "]" << message << std::endl;
}