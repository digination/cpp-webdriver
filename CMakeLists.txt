cmake_minimum_required(VERSION 2.6)

project(selenium++)

add_library(selenium++
            STATIC
            src/assoc.h
            src/http.cpp
            src/selenium.cpp
            src/capabilities.cpp
            src/utils.cpp
            src/json.cpp
            src/session.cpp
            src/element.cpp
)

add_executable(wdtests
               tests/tests_wd.cpp
               tests/tests_session.cpp
               tests/tests_element.cpp

)





find_library (CURL curl)

target_link_libraries(
  selenium++
  curl
)

target_link_libraries(
  wdtests
  selenium++
)

#install (TARGETS adam DESTINATION bin)

