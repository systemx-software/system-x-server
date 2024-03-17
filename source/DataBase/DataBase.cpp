#include "DataBase.h"

#include <stdexcept>
#include <sqlite3.h>
#include <format>
#include <functional>

namespace systemx::data_base
{
    DataBase &DataBase::GetInstance()
    {
        auto GetDatabasePath = []()
        {
            const char* databasePath = std::getenv("SYSTEMX_DB_PATH");
            if (databasePath == nullptr)
                throw std::runtime_error("SYSTEMX_DB_PATH is not set");
            return databasePath;
        };

        static DataBase instance(GetDatabasePath());
        return instance;
    }

    std::vector<std::vector<std::string>> DataBase::QueryUnique(const std::string &str)
    {
        std::unique_lock lock(m_pMutex);
        return Query(str);
    }

    std::vector<std::vector<std::string>> DataBase::QueryShared(const std::string &str)
    {
        std::unique_lock lock(m_pMutex);
        return QueryShared(str);
    }

    std::vector<std::vector<std::string>> DataBase::Query(const std::string &str)
    {
        std::vector<std::vector<std::string>> out;

        std::unique_ptr<sqlite3_stmt, std::function<int(sqlite3_stmt*)>> pSqliteStatement(nullptr, sqlite3_finalize);

        sqlite3_prepare_v2(m_pDataBase.get(), str.c_str(), (int)str.size(), std::out_ptr(pSqliteStatement), nullptr);
    
        if (!pSqliteStatement)
            throw std::runtime_error("Cannot create sql statement");

        while (sqlite3_step(pSqliteStatement.get()) != SQLITE_DONE)
        {
            const auto rowLength = sqlite3_column_count(pSqliteStatement.get());
            std::vector<std::string> rowData;
            rowData.reserve(rowLength);

            for (int i = 0; i < rowLength; ++i)
            {
                const auto pText = sqlite3_column_text(pSqliteStatement.get(), i);

                if (sqlite3_column_type(pSqliteStatement.get(), i) != SQLITE_BLOB || !pText)
                    rowData.emplace_back((pText) ? (const char*)pText : "");
            }
            out.emplace_back(rowData);
        }
        return out;
    }

    DataBase::DataBase(const std::string &path)
    {
        m_pDataBase = std::unique_ptr<sqlite3, std::function<int(sqlite3*)>>(nullptr, sqlite3_close);

        if (sqlite3_open(path.c_str(), std::out_ptr(m_pDataBase)) != SQLITE_OK)
            throw std::runtime_error(std::format("Can't open database: {}", sqlite3_errmsg(m_pDataBase.get())));
    }
}