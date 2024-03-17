#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>
struct sqlite3;

namespace systemx::data_base
{
    class DataBase
    {
    public:
        DataBase(const DataBase&) = delete;
        ~DataBase() = default;
        static DataBase& GetInstance();
    private:
        std::vector<std::vector<std::string>> Query(const std::string& str);
        DataBase(const std::string& path);
        std::unique_ptr<sqlite3, std::function<void(sqlite3*)>> m_pDataBase;
    };  
} // namespace systemx