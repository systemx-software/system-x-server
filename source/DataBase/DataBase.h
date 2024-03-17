#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <shared_mutex>

struct sqlite3;

namespace systemx::data_base
{
    class DataBase
    {
    public:
        DataBase(const DataBase&) = delete;
        ~DataBase() = default;
        static DataBase& GetInstance();

        std::vector<std::vector<std::string>> QueryUnique(const std::string& str);
        std::vector<std::vector<std::string>> QueryShared(const std::string& str);

    private:
        std::vector<std::vector<std::string>> Query(const std::string& str);

        DataBase(const std::string& path);
        std::unique_ptr<sqlite3, std::function<int(sqlite3*)>> m_pDataBase;

        std::shared_mutex m_pMutex;
    };  
} // namespace systemx