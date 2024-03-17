#include <iostream>
#include <boost/asio.hpp>

#include <boost/regex.h>
int main() 
{
    boost::regex xRegEx("(\\w+)-(\\d+)-(\\w+)-(\\d+)");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}