#include <iostream>
#include <boost/asio.hpp>
#include "DataBase/DataBase.h"
#include "DataBase/api/User.h"

#include <print>

int main() 
{
    auto db = systemx::data_base::api::User(1);

    std::cout << db.GetName();

    return 0;
}