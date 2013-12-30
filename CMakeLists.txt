cmake_minimum_required(VERSION 2.6)

project(selenium++)

add_library(selenium++
            SHARED
            src/assoc.hpp
            src/http.cpp
            src/restio.cpp
            src/selenium.cpp
            src/capabilities.cpp
            src/utils.cpp
            src/json.cpp
            src/session.cpp
            src/element.cpp
            src/log.cpp
)

#add_executable(wdtests
#               tests/tests_wd.cpp
#               tests/tests_session.cpp
#               tests/tests_element.cpp
#
#)


find_library (CURL curl)

target_link_libraries(
  selenium++
  curl
)

#target_link_libraries(
#  wdtests
#  selenium++
#)

install (TARGETS selenium++ DESTINATION lib)

install (FILES src/selenium.hpp DESTINATION include/selenium)
install (FILES src/session.hpp DESTINATION include/selenium)
install (FILES src/capabilities.hpp DESTINATION include/selenium)
install (FILES src/element.hpp DESTINATION include/selenium)
install (FILES src/json.hpp DESTINATION include/selenium)
install (FILES src/http.hpp DESTINATION include/selenium)
install (FILES src/restio.hpp DESTINATION include/selenium)

install (FILES src/utils.hpp DESTINATION include/selenium)
install (FILES src/assoc.hpp DESTINATION include/selenium)
install (FILES src/globals.hpp DESTINATION include/selenium)

