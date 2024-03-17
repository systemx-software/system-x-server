#include <iostream>
#include <boost/asio.hpp>
#include "DataBase/DataBase.h"


int main() 
{
    systemx::data_base::DataBase::GetInstance();
    return 0;
}