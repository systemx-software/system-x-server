#include "User.h"
#include "DataBase/DataBase.h"


namespace systemx::data_base::api
{
    std::optional<std::string> User::GetName() const
    {
        auto& pDataBase = DataBase::GetInstance();

        const auto data = pDataBase.QueryShared(std::format("SELECT `name` FROM `users` WHERE `id` = {}", m_id));
        
        if (data.empty())
            return std::nullopt;

        return data[0][0];
    }

    std::optional<std::string> User::GetStatus() const
    {
        auto& pDataBase = DataBase::GetInstance();

        const auto data = pDataBase.QueryShared(std::format("SELECT `status` FROM `users` WHERE `id` = {}", m_id));

        if (data.empty())
            return std::nullopt;

        return data[0][0];
    }

    std::optional<std::string> User::GetEmail() const
    {
        return std::string();
    }

} // namespace systemx::data_base