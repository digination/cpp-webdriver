cpp-webdriver
=============

cpp-webdriver is a C++ binding for the Selenium REST API.

Dependancies
------------

* boost 1.4+

* libcurl4-ssl


Compile & Install
-----------------

Clone this repository with the following command:

git clone http://github.com/digination/cpp-webdriver

Then, create a new directory for building puproses:

mkdir cpp-webdriver-build

cd cpp-webdriver-build

cmake ../cpp-webdriver/CmakeFile.txt

make && make install.

