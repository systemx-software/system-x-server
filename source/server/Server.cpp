#include "Server.h"
#include <boost/asio.hpp>


namespace sysx::server
{
    Server::Server()
    {

    }
    Server& Server::Instance()
    {
        static auto obj = Server();

        return obj;
    }
    void Server::Start()
    {
        using boost::asio::ip::tcp;

        boost::asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 7777));

    }
} // namespace systemx::server