#pragma once



namespace sysx::server
{
    class Server
    {
    private:
        Server(/* args */);
        ~Server() = default;
    public:
        static Server& Instance();
        void Start();
    };

}